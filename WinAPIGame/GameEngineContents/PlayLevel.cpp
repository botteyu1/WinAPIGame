#include "PlayLevel.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "Undead.h"
#include "Rock.h"
#include "NPC.h"
#include "Spike.h"
#include "Key.h"
#include "LockBox.h"
#include <vector>

// Contents
#include "Player.h"
#include "BackGround.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
	
}

void PlayLevel::Start()
{
	




	//ChangeRenderer = CreateRenderer(RenderOrder::);
	
	BatchActor();

	//세팅된 위치 플레이 타일에 저장
	TileMap::SetLevelTileMap(&TileMapStartData);
}

void PlayLevel::BatchActor()
{
	//TileMap* LevelTileMap = TileMap::GetLevelTileMap();
	float4 Size = TileMapStartData.GetTileMapSize();
	//std::vector<Obstacle*>& AllObstacle = Obstacle::GetAllObstacle();
	Obstacle* ObstacleObj;
	float TileSize = 100.0f;
	for (int Y = 0; Y < Size.iY(); Y++)
	{
		for (int X = 0; X < Size.iX(); X++)
		{
			std::pair<TTYPE, GameEngineActor*>& TilePair = TileMapStartData.GetTilePair(X, Y);
			float4 Pos = {static_cast<float>(X), static_cast<float>(Y), 0.0f, 0.0f};
			switch (TilePair.first)
			{
			case TTYPE::NO:
				break;
			case TTYPE::WA:
				break;
			case TTYPE::PL:
				LevelPlayer = CreateActor<Player>();
				LevelPlayer->SetPos(TileMapStartData.GetTilePos(X, Y));
				LevelPlayer->SetPlayerTilePos(X,Y);
				TilePair.second = LevelPlayer;
				break;
			case TTYPE::NP:
				ObstacleObj = CreateActor<NPC>();
				ObstacleObj->Init(Pos);
				TilePair.second = ObstacleObj;
				break;
			case TTYPE::UN:
				ObstacleObj = CreateActor<Undead>();
				ObstacleObj->Init(Pos);
				TilePair.second = ObstacleObj;
				break;
			case TTYPE::RO:
				ObstacleObj = CreateActor<Rock>();
				ObstacleObj->Init(Pos);
				TilePair.second = ObstacleObj;
				break;
			case TTYPE::LO:
				ObstacleObj = CreateActor<LockBox>();
				ObstacleObj->Init(Pos);
				TilePair.second = ObstacleObj;
				break;
			case TTYPE::KE:
				ObstacleObj = CreateActor<Key>();
				ObstacleObj->Init(Pos);
				TilePair.second = ObstacleObj;
				break;
			case TTYPE::EN:
				break;
			default:
				break;
			}
			std::pair<TTYPE, Obstacle*>& TrapPair = TileMapStartData.GetTileTrapPair(X, Y);
			switch (TrapPair.first)
			{
			case TTYPE::SP:
				ObstacleObj = CreateActor<Spike>();
				ObstacleObj->Init(Pos, 0);
				TrapPair.second = ObstacleObj;
				break;
			case TTYPE::SO:
				ObstacleObj = CreateActor<Spike>();
				ObstacleObj->Init(Pos, 1);
				TrapPair.second = ObstacleObj;
				break;
			case TTYPE::SF:
				ObstacleObj = CreateActor<Spike>();
				ObstacleObj->Init(Pos, 2);
				TrapPair.second = ObstacleObj;
				break;
			default:
				break;
			}
		}
	}

	
}
void PlayLevel::ResetActor()
{
	//TileMap* LevelTileMap = TileMap::GetLevelTileMap();
	float4 Size = TileMapStartData.GetTileMapSize();
	Obstacle* ObstacleObj;
	float TileSize = 100.0f;
	for (int Y = 0; Y < Size.iY(); Y++)
	{
		for (int X = 0; X < Size.iX(); X++)
		{
			std::pair<TTYPE, GameEngineActor*>& TilePair = TileMapStartData.GetTilePair(X, Y);
			float4 Pos = { static_cast<float>(X), static_cast<float>(Y), 0.0f, 0.0f };
			Obstacle* ObstacleObj = static_cast<Obstacle*>(TilePair.second);
			
			switch (TilePair.first)
			{
			case TTYPE::NO:
				break;
			case TTYPE::WA:
				break;
			case TTYPE::PL:
				LevelPlayer->SetPos(TileMapStartData.GetTilePos(X, Y));
				LevelPlayer->SetPlayerTilePos(X, Y);
				TilePair.second = LevelPlayer;
				TilePair.second->On();
				break;
			case TTYPE::NP:
			case TTYPE::UN:
			case TTYPE::RO:
			case TTYPE::LO:
			case TTYPE::KE:
			case TTYPE::EN:
				static_cast<Obstacle*>(TilePair.second)->Init(Pos);
				TilePair.second->On();
				
				break;
			default:
				break;
			}

			std::pair<TTYPE, Obstacle*>& TrapPair = TileMapStartData.GetTileTrapPair(X, Y);
			switch (TrapPair.first)
			{
			case TTYPE::SP:
				static_cast<Obstacle*>(TrapPair.second)->Init(Pos, 0);
				TrapPair.second->On();
				break;
			case TTYPE::SO:
				static_cast<Obstacle*>(TrapPair.second)->Init(Pos, 1);
				TrapPair.second->On();
				break;
			case TTYPE::SF:
				static_cast<Obstacle*>(TrapPair.second)->Init(Pos, 2);
				TrapPair.second->On();
				break;
			default:
				break;
			}
		}
	}
}

void PlayLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('R'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}

	// GameEngineCore::ChangeLevel("TitleLevel");
}
void PlayLevel::Render(float _Delta)
{
}
void PlayLevel::Release()
{
}





void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	
	
	ResetActor();
	//저장한 시작위치 불러오기
	TileMap::SetLevelTileMap(&TileMapStartData);
	if (nullptr == LevelPlayer)
	{
		MsgBoxAssert("플레이어를 세팅해주지 않았습니다");
	}
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}