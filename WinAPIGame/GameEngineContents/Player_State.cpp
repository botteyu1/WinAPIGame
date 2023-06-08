#include "Player.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "PlayLevel.h"
#include "ContentsEnum.h"

#include "Undead.h"
#include "Rock.h"
#include "Key.h"
#include "LockBox.h"
#include "VFX.h"



void Player::IdleStart()
{
	

	// MainRenderer->ChangeAnimation("Right_Idle");
}

void Player::RunStart()
{
	MotionTime = 0.0f;
	MainRenderer->ChangeAnimation("player_run");

	PlayerVFX->Small_VFXOn(TilePos);
	
	float4 nextTilePos = GetPlayerTilePos() + Dir;
	std::pair<TTYPE, GameEngineActor*>& NextTilePair = TileMap::GetLevelTileMap()->GetTilePair(nextTilePos);
	TTYPE NextTile = NextTilePair.first;
	GameEngineActor* Obstacle = NextTilePair.second;


	// 이동할 때 키나 상자인경우 사망처리
	switch (NextTile)
	{
	case TTYPE::KE:
		KeyCheck = true;
		static_cast<Key*>(Obstacle)->Obtained();
		break;
	case TTYPE::LO:
		static_cast<LockBox*>(Obstacle)->Obtained();
		break;
	default:
		break;
	}
	//기존 플레이어 타일 위치 이동되는 타일로 바꾸기
	TileMap::GetLevelTileMap()->SetTilePair(NextTilePair.first, NextTilePair.second, TilePos);
	//이동할 타일 위치 플레이어로 바꾸기
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::PL ,this, nextTilePos);

	// 플레이어 타일 위치 업데이트
	TilePos = nextTilePos;

	
}

void Player::AttackStart()
{
	MotionTime = 0.0f;
	MainRenderer->ChangeAnimation("player_Attack");

	//공격하는 위치 타일 정보 가져오기
	float4 nextTilePos = GetPlayerTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(nextTilePos.iX(), nextTilePos.iY());
	GameEngineActor* Obstacle = TileMap::GetLevelTileMap()->GetTileActor(nextTilePos.iX(), nextTilePos.iY());

	PlayerVFX->Hit_VFXOn(nextTilePos);

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
}

void Player::SuccessStart()
{
	MotionTime = 0.0f;
	MainRenderer->ChangeAnimation("player_success");
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
		case TTYPE::KE:
			Move();
			ChanageState(PlayerState::Run);
			break;
		case TTYPE::WA:
			break;
		case TTYPE::NP:
			ChanageState(PlayerState::Success);
			break;
		case TTYPE::UN:
		case TTYPE::RO:
			Move();
			ChanageState(PlayerState::Attack);
			break;
		case TTYPE::LO:
			if (KeyCheck == true)
			{
				Move();
				ChanageState(PlayerState::Run);
			}
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
	//한번 트랩 체크
	/*static bool Check = false;
	if (Check == false)
	{
		TrapChek();
		Check = true;
	}*/
	

	//애니메이션에 맞게 100픽셀 이동
	
	//인자하나 만들어서 100픽셀 계산해서 이동후 완료하면 아이들로 전호나
	float Speed = TILESIZE * 10 * _Delta;

	//더한 후 픽셀을 벗어나면 타일사이즈로에 맞게  돌리고 그에맞게 스피드도 돌린다.
	MotionTime += Speed;
	if (MotionTime >= TILESIZE)
	{
		Speed -= (MotionTime - TILESIZE);
	}

	float4 MovePos = Dir * Speed;
	

	if (MotionTime >= TILESIZE)
	{
		//Check = false;
		ChanageState(PlayerState::Idle);
	}

	AddPos(MovePos);
}

//모션딜레이
void Player::AttackUpdate(float _Delta)
{
	MotionTime += 1000.0f * _Delta;

	if (MotionTime >= TILESIZE)
	{
		ChanageState(PlayerState::Idle);
	}
}

void Player::SuccessUpdate(float _Delta)
{
	MotionTime += 1000.0f * _Delta;

	if (MotionTime >= TILESIZE)
	{
		ChanageState(PlayerState::Idle);
	}
}
