#include "LockBox.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"

LockBox::LockBox() 
{
}

LockBox::~LockBox()
{
}

void LockBox::Start()
{
	static int RockNum = 1;
	if (false == ResourcesManager::GetInst().IsLoadTexture("lockbox001.png"))
	{

		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\lockbox\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("lockbox001.png"));
	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	
	MainRenderer->SetTexture("lockbox001.png");

	ChanageState(ObstacleState::Idle);
}

void LockBox::Obtained()
{
	ChanageState(ObstacleState::Death);
}

void LockBox::DeathStart()
{
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
	Death();
}

