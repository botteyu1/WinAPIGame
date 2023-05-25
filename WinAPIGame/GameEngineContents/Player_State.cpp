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

	//���� �÷��̾� Ÿ�� ��ġ ��� �ٽ� �ٲٱ�
	float4 PlayerTilePos = GetPlayerTilePos();
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, PlayerTilePos);

	//�̵��� Ÿ�� ��ġ �÷��̾�� �ٲٱ�
	PlayerTilePos += Dir;
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::PL ,this, PlayerTilePos);

	// �÷��̾� Ÿ�� ��ġ ������Ʈ
	TilePos = PlayerTilePos;

	RunUpdate(_Delta);
}

void Player::AttackStart(float _Delta)
{
	PixelCount = 0.0f;
	MainRenderer->ChangeAnimation("player_Attack");

	//�����ϴ� ��ġ Ÿ�� ���� ��������
	float4 PlayerTilePos = GetPlayerTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(PlayerTilePos.iX(), PlayerTilePos.iY());
	GameEngineActor* Obstacle = TileMap::GetLevelTileMap()->GetTileActor(PlayerTilePos.iX(), PlayerTilePos.iY());

	// Ÿ�Կ� �´� �� ó��
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
	//�ִϸ��̼ǿ� �°� 100�ȼ� �̵�
	
	//�����ϳ� ���� 100�ȼ� ����ؼ� �̵��� �Ϸ��ϸ� ���̵�� ��ȣ��
	float Speed = 1000.0f * _Delta;

	//���� �� �ȼ��� ����� Ÿ�ϻ�����ο� �°�  ������ �׿��°� ���ǵ嵵 ������.
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
