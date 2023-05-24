#include "Undead.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include "ContentsEnum.h"
#include <GameEngineCore/ResourcesManager.h>
#include "Player.h"



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
		ResourcesManager::GetInst().CreateSpriteFolder("undead_death", FolderPath.PlusFilePath("undead_death"));
		
	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	MainRenderer->CreateAnimation("undead_idle", "undead_idle", 0, 11, 0.07f, true);
	MainRenderer->CreateAnimation("undead_death", "undead_death", 0, 5, 0.05f, false);
	MainRenderer->ChangeAnimation("undead_idle");
}