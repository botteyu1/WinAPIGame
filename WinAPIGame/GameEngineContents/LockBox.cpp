#include "LockBox.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"
#include "Player.h"
#include "VFX.h"
LockBox::LockBox() 
{
}

LockBox::~LockBox()
{
}

void LockBox::Start()
{
	
	if (false == ResourcesManager::GetInst().IsLoadTexture("lockbox001.png"))
	{

		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\obstacle\\lockbox\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("lockbox001.png"));
	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	
	MainRenderer->SetTexture("lockbox001.png");

	ChangeState(ObstacleState::Idle);
}

void LockBox::Obtained()
{
	ChangeState(ObstacleState::Death);
}

void LockBox::DeathStart()

{	
	//플레이어의 vfx를 가져와서 큰 파티클을 생성
	Player::GetMainPlayer()->GetPlayerVFX()->Huge_VFXOn(GetTilePos()); 
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
	Off();
}

