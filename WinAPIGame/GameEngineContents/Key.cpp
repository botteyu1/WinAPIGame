#include "Key.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"
Key::Key() 
{
}

Key::~Key()
{
}

void Key::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("Key"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\");

		ResourcesManager::GetInst().CreateSpriteFolder("Key", FolderPath.PlusFilePath("Key"));

	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	MainRenderer->CreateAnimation("Key", "Key", 0, 11, 0.07f, true);
	MainRenderer->ChangeAnimation("Key");

	ChanageState(ObstacleState::Idle);
}

void Key::Obtained()
{
	ChanageState(ObstacleState::Death);
}

void Key::DeathStart()
{
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
	Off();
}

void Key::DeathUpdate(float _Delta)
{
	
}

