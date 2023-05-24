#include "Player.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "PlayLevel.h"
#include "ContentsEnum.h"

void Player::IdleStart()
{
	

	// MainRenderer->ChangeAnimation("Right_Idle");
}

void Player::RunStart(float _Delta)
{
	RunPixelCount = 0.0f;
	MainRenderer->ChangeAnimation("player_run");

	//TileMap::GetLevelTileMap()->SetTileType(PlayerTilePos,TTYPE::PL);
	

	RunUpdate(_Delta);
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
			ChanageState(_Delta, PlayerState::Attack);
			break;
		case TTYPE::SP:
			break;
		case TTYPE::RO:
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
	RunPixelCount += Speed;
	if (RunPixelCount >= TILESIZE)
	{
		Speed -= (RunPixelCount - TILESIZE);
	}

	float4 MovePos = Dir * Speed;
	

	if (RunPixelCount >= 100.0f)
	{
		ChanageState( _Delta,PlayerState::Idle);
	}

	AddPos(MovePos);
	//GetLevel()->GetMainCamera()->AddPos(MovePos);


}