#include "PlayLevel.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "Undead.h"
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
		TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::PL, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::NO, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
		TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
		TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,	TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
	};


	TileMap::GetLevelTileMap()->Init(TileData, {8.0f,8.0f}, {510.0f,120.0f});
	BatchActor();
}

void PlayLevel::BatchActor()
{
	TileMap* LevelTileMap = TileMap::GetLevelTileMap();
	float4 Size = LevelTileMap->GetTileMapSize();
	std::vector<Obstacle*>& AllObstacle = Obstacle::GetAllObstacle();
	Obstacle* Obstacle;
	float TileSize = 100.0f;
	for (int Y = 0; Y < Size.iY(); Y++)
	{
		for (int X = 0; X < Size.iX(); X++)
		{
			TTYPE TileType = LevelTileMap->GetTileType(X, Y);
			switch (TileType)
			{
			case TTYPE::NO:
				break;
			case TTYPE::WA:
				break;
			case TTYPE::PL:
				LevelPlayer = CreateActor<Player>();
				LevelPlayer->SetPos(LevelTileMap->GetTilePos(X, Y));
				LevelPlayer->SetPlayerTilePos(X,Y);
				break;
			case TTYPE::NP:
				break;
			case TTYPE::UN:
				Obstacle = CreateActor<Undead>();
				Obstacle->Init(LevelTileMap->GetTilePos(X, Y));
				AllObstacle.push_back(Obstacle);
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