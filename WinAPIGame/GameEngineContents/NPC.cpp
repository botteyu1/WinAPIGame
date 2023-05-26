#include "NPC.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"

NPC::NPC() 
{
}

NPC::~NPC()
{
}

void NPC::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("pandemonica"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\npc\\");

		ResourcesManager::GetInst().CreateSpriteFolder("pandemonica", FolderPath.PlusFilePath("pandemonica"));

	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	MainRenderer->CreateAnimation("pandemonica", "pandemonica", 0, 11, 0.07f, true);
	MainRenderer->ChangeAnimation("pandemonica");

	ChanageState(ObstacleState::Idle);
}

