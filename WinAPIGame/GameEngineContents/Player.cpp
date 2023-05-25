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
#include "Bullet.h"
#include <GameEnginePlatform/GameEngineInput.h>
Player* Player::MainPlayer = nullptr;

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
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
		// MainRenderer->SetRenderScale({ 200, 200 });
		// MainRenderer->SetSprite("Left_Player.bmp");

		//애니메이션은 로드된 스프라이트를 가지고 만든다.
		MainRenderer->CreateAnimation("player_idle", "player_idle", 0, 11, 0.07f, true);
			
		MainRenderer->CreateAnimation("player_run", "player_run", 0, 5, 0.06f, false);
		MainRenderer->CreateAnimation("player_attack", "player_attack", 0, 12, 0.06f, false);
		MainRenderer->CreateAnimation("player_success", "player_success", 0, 12, 0.06f, false);

		MainRenderer->ChangeAnimation("player_idle");
		//MainRenderer->Flip();
		MainRenderer->SetRenderScaleToTexture();
	}



	ChanageState(0.0f,PlayerState::Idle);
	Dir = float4::RIGHT;

}

void Player::Update(float _Delta)
{
	
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
		return AttackUpdate(_Delta);
	default:
		break;
	}
}

void Player::ChanageState(float _Delta, PlayerState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case PlayerState::Idle:
			IdleStart();
			break;
		case PlayerState::Run:
			RunStart( _Delta);
			break;	
		case PlayerState::Attack:
			AttackStart( _Delta);
		case PlayerState::Success:
			AttackStart( _Delta);
			break;
		default:
			break;
		}
	}

	State = _State;
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
