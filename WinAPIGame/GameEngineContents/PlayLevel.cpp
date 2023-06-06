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
#include "LevelChange.h"
#include "Player.h"
#include "BackGround.h"
#include "UI.h"
#include <GameEnginePlatform/GameEngineSound.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
	

}

void PlayLevel::Start()
{
	/*GameEngineSound::SetGlobalVolume(0.05f);
	if (nullptr == GameEngineSound::FindSound("BGMTest.mp3"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Sound\\");

		GameEngineSound::SoundLoad(FilePath.PlusFilePath("BGMTest.mp3"));
	}
	GameEngineSound::SoundPlay("BGMTest.mp3");*/


	PlayLevelChange = CreateActor<LevelChange>();
	
	SetLevelData();
	BatchActor();

	//세팅된 위치 플레이 타일에 저장
	TileMap::SetLevelTileMap(&TileMapStartData);

	PlayUI = CreateActor<UI>();
	PlayUI->Init(StageLevel);
}

void PlayLevel::BatchActor()
{
	TileMap::SetLevelTileMap(&TileMapStartData);
	float4 Size = TileMapStartData.GetTileMapSize();
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
				ObstacleObj->Init(Pos, StageLevel);
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
			std::pair<OTYPE, Obstacle*>& TrapPair = TileMapStartData.GetTileTrapPair(X, Y);
			switch (TrapPair.first)
			{
			case OTYPE::SP:
				ObstacleObj = CreateActor<Spike>();
				ObstacleObj->Init(Pos, 0);
				TrapPair.second = ObstacleObj;
				break;
			case OTYPE::SO:
				ObstacleObj = CreateActor<Spike>();
				ObstacleObj->Init(Pos, 1);
				TrapPair.second = ObstacleObj;
				break;
			case OTYPE::SF:
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
	Obstacle* ObstacleObj = nullptr;
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

			std::pair<OTYPE, Obstacle*>& TrapPair = TileMapStartData.GetTileTrapPair(X, Y);
			switch (TrapPair.first)
			{
			case OTYPE::SP:
				static_cast<Obstacle*>(TrapPair.second)->Init(Pos, 0);
				TrapPair.second->On();
				break;
			case OTYPE::SO:
				static_cast<Obstacle*>(TrapPair.second)->Init(Pos, 1);
				TrapPair.second->On();
				break;
			case OTYPE::SF:
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
	//씬전환 애니메이션 중 화면이 전부 가려졋을 때 레벨전환이 일어남
	if (PlayLevelChange->State == LevelState::Transition && PlayLevelChange->CoverFullScreen == true)
	{
		std::string ResetLevel = "PlayLevel" + std::to_string(StageLevel);
		GameEngineCore::ChangeLevel(ResetLevel);
		PlayLevelChange->CoverFullScreen = false;
	}

	if (true == GameEngineInput::IsDown('R'))
	{
		PlayLevelChange->ChanageState(LevelState::Transition);
	}
	if (true == GameEngineInput::IsDown('T'))
	{
		PlayLevelChange->ChanageState(LevelState::Death);

	}
	if (true == GameEngineInput::IsDown('1'))
	{
		PlayLevelChange->ChanageState(LevelState::Transition);
		StageLevel = 1;
	}
	if (true == GameEngineInput::IsDown('2'))
	{
		PlayLevelChange->ChanageState(LevelState::Transition);
		StageLevel = 2;
	}
	if (true == GameEngineInput::IsDown('3'))
	{
		PlayLevelChange->ChanageState(LevelState::Transition);
		StageLevel = 3;
	}
	
}
void PlayLevel::Render(float _Delta)
{
}
void PlayLevel::Release()
{
}





void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	
	
	TileMap::SetLevelTileMap(&TileMapStartData);
	ResetActor();
	//저장한 시작위치 불러오기
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}