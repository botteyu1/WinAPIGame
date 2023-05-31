#include "Undead.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include "ContentsEnum.h"
#include <GameEngineCore/ResourcesManager.h>
#include "Player.h"
#include "TileMap.h"



Undead::Undead() 
{
}

Undead::~Undead()
{
}



void Undead::Start()
{
	
	if (false == ResourcesManager::GetInst().IsLoadSprite("undead_idle"))
	{

		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\");

		ResourcesManager::GetInst().CreateSpriteFolder("undead_idle", FolderPath.PlusFilePath("undead_idle"));
		ResourcesManager::GetInst().CreateSpriteFolder("undead_move", FolderPath.PlusFilePath("undead_move"));
		
	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	MainRenderer->CreateAnimation("undead_idle", "undead_idle", 0, 11, 0.07f, true);
	MainRenderer->CreateAnimation("undead_move", "undead_move", 0, 5, 0.05f, false);
	MainRenderer->ChangeAnimation("undead_idle");

	ChanageState(ObstacleState::Idle);
}



void Undead::TryMove(float4 _Dir)
{
	Dir = _Dir;
	float4 nextTilePos = GetTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(nextTilePos.iX(), nextTilePos.iY()); 
	
	switch (NextTile)
	{
	case TTYPE::NO:
		
		
		ChanageState(ObstacleState::Move);
		
		break;
	case TTYPE::WA:
	case TTYPE::PL:
	case TTYPE::NP:
	case TTYPE::UN:
	case TTYPE::RO:
	case TTYPE::LO:
	case TTYPE::KE:
		ChanageState( ObstacleState::Death);
		break;

	case TTYPE::EN:
		break;
	default:
		break;
	}
}

void Undead::IdleStart()
{

}

void Undead::MoveStart()
{
	PixelCount = 0.0f;
	MainRenderer->ChangeAnimation("undead_move");

	//����  Ÿ�� ��ġ ��� �ٽ� �ٲٱ�

	float4 nextTilePos = GetTilePos() += Dir;

	std::pair<TTYPE, GameEngineActor*>& NextTilePair = TileMap::GetLevelTileMap()->GetTilePair(nextTilePos);
	TileMap::GetLevelTileMap()->SetTilePair(NextTilePair.first, NextTilePair.second, TilePos);

	//�̵��� Ÿ�� ��ġ �ٲٱ� 
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::UN, this, nextTilePos);

	// ��ġ ������Ʈ
	TilePos = nextTilePos;
	
	
}

void Undead::DeathStart()
{
	
}

void Undead::IdleUpdate(float _Delta)
{
	if (true == MainRenderer->IsAnimationEnd())
	{
		MainRenderer->ChangeAnimation("undead_Idle");
	}


	Obstacle* NextTrapTile = TileMap::GetLevelTileMap()->GetTileTrapActor(TilePos.iX(), TilePos.iY()); //Ʈ���ִ��� Ȱ��ȭ�� ���
	if (NextTrapTile != nullptr and NextTrapTile->GetState() == ObstacleState::Attack)
	{
		ChanageState(ObstacleState::Death); 
	}
}

void Undead::MoveUpdate(float _Delta)
{
	//�ִϸ��̼ǿ� �°� 100�ȼ� �̵�

	//�����ϳ� ���� 100�ȼ� ����ؼ� �̵��� �Ϸ��ϸ� ���̵�� ��ȯ
	float Speed = TILESIZE * 10 * _Delta;

	//���� �� �ȼ��� ����� Ÿ�ϻ�����ο� �°�  ������ �׿��°� ���ǵ嵵 ������.
	PixelCount += Speed;
	if (PixelCount >= TILESIZE)
	{
		Speed -= (PixelCount - TILESIZE);
	}

	float4 MovePos = Dir * Speed;


	if (PixelCount >= TILESIZE)
	{
		ChanageState(ObstacleState::Idle);
	}

	AddPos(MovePos);
}

void Undead::DeathUpdate(float _Delta)
{
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
	Off();
}

