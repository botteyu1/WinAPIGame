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
	BackGroundPtr = CreateActor<BackGround>();
	BackGroundPtr->Init("chapterBG0001.bmp");

	std::vector<TTYPE> TileData =
	{
		TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::PL, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::WA, TTYPE::SP, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::WA, TTYPE::SP, TTYPE::UN, TTYPE::NO, TTYPE::UN, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::NP, TTYPE::WA,
		TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,	TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
	};


	TileMap::GetLevelTileMap()->Init(TileData, {9.0f,8.0f}, {510.0f,120.0f});
	BatchActor();
}

void PlayLevel::BatchActor()
{
	TileMap* LevelTileMap = TileMap::GetLevelTileMap();
	float4 Size = LevelTileMap->GetTileMapSize();
	//std::vector<Obstacle*>& AllObstacle = Obstacle::GetAllObstacle();
	Obstacle* ObstacleObj;
	float TileSize = 100.0f;
	for (int Y = 0; Y < Size.iY(); Y++)
	{
		for (int X = 0; X < Size.iX(); X++)
		{
			std::pair<TTYPE, GameEngineActor*>& TilePair = LevelTileMap->GetTilePair(X, Y);
			float4 Pos = {static_cast<float>(X), static_cast<float>(Y), 0.0f, 0.0f};
			switch (TilePair.first)
			{
			case TTYPE::NO:
				break;
			case TTYPE::WA:
				break;
			case TTYPE::PL:
				LevelPlayer = CreateActor<Player>();
				LevelPlayer->SetPos(LevelTileMap->GetTilePos(X, Y));
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
				break;
			case TTYPE::KE:
				break;
			case TTYPE::EN:
				break;
			default:
				break;
			}
			
			std::pair<TTYPE, Obstacle*>& TrapPair = LevelTileMap->GetTileTrapPair(X, Y);
			switch (TrapPair.first)
			{
			case TTYPE::SP:
				ObstacleObj = CreateActor<Spike>();
				ObstacleObj->Init(Pos, 0);
				TrapPair.second = ObstacleObj;
				break;
			case TTYPE::SN:
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
void PlayLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('O'))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	// GameEngineCore::ChangeLevel("TitleLevel");
}
void PlayLevel::Render()
{
}
void PlayLevel::Release()
{
}





void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (nullptr == LevelPlayer)
	{
		MsgBoxAssert("플레이어를 세팅해주지 않았습니다");
	}

	//float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	////LevelPlayer->SetPos(WinScale.Half());
	//// 0 0
	//// x y
	//GetMainCamera()->SetPos(LevelPlayer->GetPos() - WinScale.Half());

}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}