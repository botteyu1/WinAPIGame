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

	//기존  타일 위치 길로 다시 바꾸기

	float4 nextTilePos = GetTilePos() += Dir;

	std::pair<TTYPE, GameEngineActor*>& NextTilePair = TileMap::GetLevelTileMap()->GetTilePair(nextTilePos);
	TileMap::GetLevelTileMap()->SetTilePair(NextTilePair.first, NextTilePair.second, TilePos);

	//이동할 타일 위치 바꾸기 
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::UN, this, nextTilePos);

	// 위치 업데이트
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


	Obstacle* NextTrapTile = TileMap::GetLevelTileMap()->GetTileTrapActor(TilePos.iX(), TilePos.iY()); //트랩있는지 활성화시 사망
	if (NextTrapTile != nullptr and NextTrapTile->GetState() == ObstacleState::Attack)
	{
		ChanageState(ObstacleState::Death); 
	}
}

void Undead::MoveUpdate(float _Delta)
{
	//애니메이션에 맞게 100픽셀 이동

	//인자하나 만들어서 100픽셀 계산해서 이동후 완료하면 아이들로 전환
	float Speed = TILESIZE * 10 * _Delta;

	//더한 후 픽셀을 벗어나면 타일사이즈로에 맞게  돌리고 그에맞게 스피드도 돌린다.
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

