#include "Key.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"
#include "Player.h"
#include "VFX.h"
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
	//플레이어의 vfx를 가져와서 큰 파티클을 생성
	Player::GetMainPlayer()->GetPlayerVFX()->Huge_VFXOn(GetTilePos());
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
	Off();
}

void Key::DeathUpdate(float _Delta)
{
	
}

