#include "Spike.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "Player.h"
#include "TileMap.h"

Spike::Spike()
{
}

Spike::~Spike()
{
}

void Spike::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("spike_on"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\");

		ResourcesManager::GetInst().CreateSpriteFolder("spike_on", FolderPath.PlusFilePath("spike_on"));
		ResourcesManager::GetInst().CreateSpriteFolder("spike_off", FolderPath.PlusFilePath("spike_off"));

	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	MainRenderer->CreateAnimation("spike_on", "spike_on", 0, 3, 0.05f, false);
	MainRenderer->CreateAnimation("spike_off", "spike_off", 0, 3, 0.05f, false);
	MainRenderer->ChangeAnimation("spike_on");

	ChanageState(ObstacleState::Attack);
}
void Spike::Init(float4 _TilePos, int _Custom)
{
	Obstacle::Init(_TilePos, _Custom);
}
// 공격안하는 대기상황
void Spike::IdleStart()
{
	MainRenderer->ChangeAnimation("spike_off");
}

//공격하는 상황
void Spike::AttackStart()
{
	
	MainRenderer->ChangeAnimation("spike_on");
}

void Spike::IdleUpdate(float _delta)
{
	
	if (Player::GetMainPlayer()->IsMoved() == true)
	{
		ChanageState(ObstacleState::Attack);
	}
}

void Spike::AttackUpdate(float _delta)
{
	if (Player::GetMainPlayer()->IsMoved() == true)
	{
		ChanageState(ObstacleState::Idle);
	}
	
}
