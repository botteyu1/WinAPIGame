#include "Player.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "PlayLevel.h"
#include "ContentsEnum.h"

#include "Undead.h"
#include "Rock.h"

void Player::IdleStart()
{
	

	// MainRenderer->ChangeAnimation("Right_Idle");
}

void Player::RunStart(float _Delta)
{
	PixelCount = 0.0f;
	MainRenderer->ChangeAnimation("player_run");

	//기존 플레이어 타일 위치 길로 다시 바꾸기
	float4 PlayerTilePos = GetPlayerTilePos();
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, PlayerTilePos);

	//이동할 타일 위치 플레이어로 바꾸기
	PlayerTilePos += Dir;
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::PL ,this, PlayerTilePos);

	// 플레이어 타일 위치 업데이트
	TilePos = PlayerTilePos;

	RunUpdate(_Delta);
}

void Player::AttackStart(float _Delta)
{
	PixelCount = 0.0f;
	MainRenderer->ChangeAnimation("player_Attack");

	//공격하는 위치 타일 정보 가져오기
	float4 PlayerTilePos = GetPlayerTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(PlayerTilePos.iX(), PlayerTilePos.iY());
	GameEngineActor* Obstacle = TileMap::GetLevelTileMap()->GetTileActor(PlayerTilePos.iX(), PlayerTilePos.iY());

	// 타입에 맞는 적 처리
	switch (NextTile)
	{
	case TTYPE::UN:
		static_cast<Undead*>(Obstacle)->TryMove(Dir);
		break;
	case TTYPE::RO:
		static_cast<Rock*>(Obstacle)->TryMove(Dir);
		break;
	default:
		break;
	}

	AttackUpdate(_Delta);
}

void Player::IdleUpdate(float _Delta)
{

	if (true == MainRenderer->IsAnimationEnd())
	{
		MainRenderer->ChangeAnimation("player_Idle");
	}

	
	if (true == GameEngineInput::IsDown('A')
		|| true == GameEngineInput::IsDown('W')
		|| true == GameEngineInput::IsDown('S')
		|| true == GameEngineInput::IsDown('D'))
	{
		DirCheck();

		float4 PlayerTilePos = GetPlayerTilePos() + Dir;
		TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(PlayerTilePos.iX(), PlayerTilePos.iY());

		switch (NextTile)
		{
		case TTYPE::NO:
			ChanageState(_Delta, PlayerState::Run);
			break;
		case TTYPE::WA:
			break;
		case TTYPE::NP:
			ChanageState(_Delta, PlayerState::Success);
			break;
		case TTYPE::UN:
		case TTYPE::RO:
			ChanageState(_Delta, PlayerState::Attack);
			break;
		case TTYPE::SP:
			break;
		case TTYPE::LO:
			break;
		case TTYPE::KE:
			break;
		case TTYPE::EN:
			break;
		default:
			break;
		}
		return;
	}

}


void Player::RunUpdate(float _Delta)
{
	//애니메이션에 맞게 100픽셀 이동
	
	//인자하나 만들어서 100픽셀 계산해서 이동후 완료하면 아이들로 전호나
	float Speed = 1000.0f * _Delta;

	//더한 후 픽셀을 벗어나면 타일사이즈로에 맞게  돌리고 그에맞게 스피드도 돌린다.
	PixelCount += Speed;
	if (PixelCount >= TILESIZE)
	{
		Speed -= (PixelCount - TILESIZE);
	}

	float4 MovePos = Dir * Speed;
	

	if (PixelCount >= TILESIZE)
	{
		ChanageState( _Delta,PlayerState::Idle);
	}

	AddPos(MovePos);
}

void Player::AttackUpdate(float _Delta)
{
	PixelCount += 1000.0f * _Delta;

	if (PixelCount >= TILESIZE)
	{
		ChanageState(_Delta, PlayerState::Idle);
	}
}
