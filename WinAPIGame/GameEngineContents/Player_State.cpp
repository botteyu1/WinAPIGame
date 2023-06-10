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
#include "Dialog.h"
#include "NPC.h"
#include "LevelChange.h"



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
	std::pair<OTYPE, Obstacle*>& NextTrapTilePair = TileMap::GetLevelTileMap()->GetTileTrapPair(nextTilePos);
	
	// �̵��� �� Ű�� �����ΰ�� ���ó��
	if (NextTrapTilePair.first == OTYPE::KE)
	{
		KeyCheck = true;
		static_cast<Key*>(NextTrapTilePair.second)->Obtained();
	}
	if (NextTilePair.first == TTYPE::LO)
	{
		static_cast<LockBox*>(NextTilePair.second)->Obtained();
	}

	//���� �÷��̾� Ÿ�� ��ġ �̵��Ǵ� Ÿ�Ϸ� �ٲٱ�
	TileMap::GetLevelTileMap()->SetTilePair(NextTilePair.first, NextTilePair.second, TilePos);
	//�̵��� Ÿ�� ��ġ �÷��̾�� �ٲٱ�
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::PL ,this, nextTilePos);

	// �÷��̾� Ÿ�� ��ġ ������Ʈ
	TilePos = nextTilePos;

	
}

void Player::AttackStart()
{
	MotionTime = 0.0f;
	MainRenderer->ChangeAnimation("player_Attack");

	//�����ϴ� ��ġ Ÿ�� ���� ��������
	float4 nextTilePos = GetPlayerTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(nextTilePos.iX(), nextTilePos.iY());
	GameEngineActor* Obstacle = TileMap::GetLevelTileMap()->GetTileActor(nextTilePos.iX(), nextTilePos.iY());

	//��ġ�� Ÿ�� ����Ʈ����
	PlayerVFX->Hit_VFXOn(nextTilePos);

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
			Move();
			ChangeState(PlayerState::Run);
			break;
		case TTYPE::WA:
			break;
		case TTYPE::NP:
			PlayLevelPtr->GetDialog()->ChangeState(DialogState::On);
			ChangeState(PlayerState::Max);
			Move();
			//ChangeState(PlayerState::Success);
			break;
		case TTYPE::UN:
		case TTYPE::RO:
			Move();
			ChangeState(PlayerState::Attack);
			break;
		case TTYPE::LO:
			if (KeyCheck == true)
			{
				Move();
				ChangeState(PlayerState::Run);
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
	//�ѹ� Ʈ�� üũ
	/*static bool Check = false;
	if (Check == false)
	{
		TrapChek();
		Check = true;
	}*/
	

	//�ִϸ��̼ǿ� �°� 100�ȼ� �̵�
	
	//�����ϳ� ���� 100�ȼ� ����ؼ� �̵��� �Ϸ��ϸ� ���̵�� ��ȣ��
	float Speed = TILESIZE * 10 * _Delta;

	//���� �� �ȼ��� ����� Ÿ�ϻ�����ο� �°�  ������ �׿��°� ���ǵ嵵 ������.
	MotionTime += Speed;
	if (MotionTime >= TILESIZE)
	{
		Speed -= (MotionTime - TILESIZE);
	}

	float4 MovePos = Dir * Speed;
	

	if (MotionTime >= TILESIZE)
	{
		//Check = false;
		ChangeState(PlayerState::Idle);
	}

	AddPos(MovePos);
}

//��ǵ�����
void Player::AttackUpdate(float _Delta)
{
	MotionTime += 1000.0f * _Delta;

	if (MotionTime >= TILESIZE)
	{
		ChangeState(PlayerState::Idle);
	}
}

void Player::SuccessUpdate(float _Delta)
{
	

	if (MainRenderer->GetCurFrame() == 6)
	{
		//npc ��ġ Ÿ�� ���� ��������
		
		float4 NPCPos = PlayLevelPtr->GetNPCPos();
		GameEngineActor* Obstacle = TileMap::GetLevelTileMap()->GetTileActor(NPCPos.iX(), NPCPos.iY());

		static_cast<NPC*>(Obstacle)->ChangeState(ObstacleState::Death);
	}

	if (true == MainRenderer->IsAnimationEnd())
	{
		PlayLevelPtr->GetLevelChange()->ChangeState(LevelState::Transition);
		PlayLevelPtr->AddNextStageLevel(1);
		ChangeState(PlayerState::Idle);
	}
}
