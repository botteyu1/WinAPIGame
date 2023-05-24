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
	//�ִϸ��̼ǿ� �°� 100�ȼ� �̵�
	
	//�����ϳ� ���� 100�ȼ� ����ؼ� �̵��� �Ϸ��ϸ� ���̵�� ��ȣ��
	float Speed = 1000.0f * _Delta;

	//���� �� �ȼ��� ����� Ÿ�ϻ�����ο� �°�  ������ �׿��°� ���ǵ嵵 ������.
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