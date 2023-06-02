#include "Player.h"
#include "ContentsEnum.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "Obstacle.h"
#include "TileMap.h"
Player* Player::MainPlayer = nullptr;

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("player_idle001.png"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");

		FolderPath.MoveChild("ContentsResources\\Texture\\");
		//로드하면서 스프라이트를 생성한다
		ResourcesManager::GetInst().CreateSpriteFolder("player_idle", FolderPath.PlusFilePath("player_idle"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_run", FolderPath.PlusFilePath("player_run"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_attack", FolderPath.PlusFilePath("player_attack"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_success", FolderPath.PlusFilePath("player_success"));
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::Play);

		//애니메이션은 로드된 스프라이트를 가지고 만든다.3
		MainRenderer->CreateAnimation("player_idle", "player_idle", 0, 11, 0.07f, true);
			
		MainRenderer->CreateAnimation("player_run", "player_run", 0, 5, 0.06f, false);
		MainRenderer->CreateAnimation("player_attack", "player_attack", 0, 12, 0.06f, false);
		MainRenderer->CreateAnimation("player_success", "player_success", 0, 18, 0.1f, false);

		MainRenderer->ChangeAnimation("player_idle");
		//MainRenderer->Flip();
		MainRenderer->SetRenderScaleToTexture();
	}



	ChanageState(PlayerState::Idle);
	Dir = float4::RIGHT;
	HP = 10;

}

void Player::Update(float _Delta)
{
	if (HP == 0)
	{
		int a = 0;
	}
	Moved = false; // 이동 초기화
	StateUpdate(_Delta);
}

void Player::StateUpdate(float _Delta)
{
	switch (State)
	{
	case PlayerState::Idle:
		return IdleUpdate(_Delta);
	case PlayerState::Run:
		return RunUpdate(_Delta);
	case PlayerState::Attack:
		return AttackUpdate(_Delta);
	case PlayerState::Success:
		return SuccessUpdate(_Delta);
	default:
		break;
	}
}

void Player::ChanageState(PlayerState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case PlayerState::Idle:
			IdleStart();
			break;
		case PlayerState::Run:
			RunStart();
			break;	
		case PlayerState::Attack:
			AttackStart();
			break;
		case PlayerState::Success:
			SuccessStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}


void Player::TrapChek()
{
	Obstacle* NextTrapTile = TileMap::GetLevelTileMap()->GetTileTrapActor(TilePos.iX(), TilePos.iY()); //트랩있는지 활성화시 사망
	if (NextTrapTile != nullptr and NextTrapTile->GetState() == ObstacleState::Attack)
	{
		HP--;
	}
}

void Player::DirCheck()
{
	if (true == GameEngineInput::IsDown('A') )
	{
		Dir = float4::LEFT;
		MainRenderer->FlipON();//왼쪽이면 플립
	
		return;
	}

	if (true == GameEngineInput::IsDown('D'))
	{
		Dir = float4::RIGHT;
		MainRenderer->FlipOFF(); //오른쪽이면 플립 풀기
		
		return;
	}
	if (true == GameEngineInput::IsDown('W'))
	{
		Dir = float4::UP;
		
		return;
	}
	if (true == GameEngineInput::IsDown('S'))
	{
		Dir = float4::DOWN;
		
		return;
	}
	return;



}




void Player::LevelStart()
{
	MainPlayer = this;
}

void Player::Move()
{
	HP--;
	Moved = true;
}