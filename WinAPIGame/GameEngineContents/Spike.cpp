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
		FolderPath.MoveChild("ContentsResources\\Texture\\obstacle\\");

		ResourcesManager::GetInst().CreateSpriteFolder("spike_on", FolderPath.PlusFilePath("spike_on"));
		ResourcesManager::GetInst().CreateSpriteFolder("spike_off", FolderPath.PlusFilePath("spike_off"));

	}
	
	MainRenderer = CreateRenderer(RenderOrder::Trap);
	MainRenderer->CreateAnimation("spike_on", "spike_on", 0, 3, 0.05f, false);
	MainRenderer->CreateAnimation("spike_off", "spike_off", 0, 3, 0.05f, false);
	MainRenderer->ChangeAnimation("spike_on");
	
	
}
void Spike::Init(float4 _TilePos, int _Custom)
{
	Obstacle::Init(_TilePos, _Custom);

	if (_Custom == 0)
	{
		AlwayAttack = true;
		ChangeState(ObstacleState::Attack);
	}
	else if (_Custom == 1)
	{
		AlwayAttack = false;
		ChangeState(ObstacleState::Attack);
	}
	else if (_Custom == 2)
	{
		AlwayAttack = false;
		ChangeState(ObstacleState::Idle);
	}

	//밑에 깔리기 위한 pos 조정
	AddPos({ 0.0f,20.0f });
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
		Player* playerptr = Player::GetMainPlayer();
		playerptr->Player::TrapChek(GetTilePos());
		ChangeState(ObstacleState::Attack);
	}
}

void Spike::AttackUpdate(float _delta)
{
	if ((Player::GetMainPlayer()->IsMoved() == true) )
	{
		if (AlwayAttack == false)
		{
			ChangeState(ObstacleState::Idle);
		}
		else
		{
			Player* playerptr = Player::GetMainPlayer();
			playerptr->Player::TrapChek(GetTilePos());
		}

		
	}
	
}
