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
		//�ε��ϸ鼭 ��������Ʈ�� �����Ѵ�
		ResourcesManager::GetInst().CreateSpriteFolder("player_idle", FolderPath.PlusFilePath("player_idle"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_run", FolderPath.PlusFilePath("player_run"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_attack", FolderPath.PlusFilePath("player_attack"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_success", FolderPath.PlusFilePath("player_success"));
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::Play);
		// MainRenderer->SetRenderScale({ 200, 200 });
		// MainRenderer->SetSprite("Left_Player.bmp");

		//�ִϸ��̼��� �ε�� ��������Ʈ�� ������ �����.
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
		default:
			break;
		}
	}

	State = _State;
}


void Player::DirCheck()
{

	// �ڵ���� ���������� ����Ǳ� ������ 
	// D�� �������·� A������������ ������ȯ�� ����������
	// A�� �������·� D�� ������������ A�� ó���� ���� �̷������ ������ȯ�� �����ʱ⶧���� ������ �߻��ߴ�.

	//// ������ �����ϴ� Ű���� ��� ������� �׻��� �״�� ����. �Ʒ��� D�� �����϶� Left�� �Ǵ� ���� ����.
	//if (true == GameEngineInput::IsFree('A') && true == GameEngineInput::IsFree('D'))
	//{
	//	return;
	//}

	// A�� ���Ȱų� D�� �����̶�� Left�� ������ȯ �ε� �������־ Left�� �ٶ󺸴� ������ ����.
	if (true == GameEngineInput::IsDown('A') )
	{
		Dir = float4::LEFT;
		MainRenderer->FlipON();
	
		return;
	}

	// D�� ���Ȱų� A�� �����̸� Right�� ���� ��ȯ.
	if (true == GameEngineInput::IsDown('D'))
	{
		Dir = float4::RIGHT;
		MainRenderer->FlipOFF();
		
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
