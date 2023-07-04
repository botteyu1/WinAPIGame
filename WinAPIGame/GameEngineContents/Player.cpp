#include "Player.h"
#include "ContentsEnum.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "Obstacle.h"
#include "TileMap.h"
#include "PlayLevel.h"
#include "LevelChange.h"


Player* Player::MainPlayer = nullptr;

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("player_idle"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");

		FolderPath.MoveChild("ContentsResources\\Texture\\player\\");
		//로드하면서 스프라이트를 생성한다
		ResourcesManager::GetInst().CreateSpriteFolder("player_idle", FolderPath.PlusFilePath("player_idle"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_run", FolderPath.PlusFilePath("player_run"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_attack", FolderPath.PlusFilePath("player_attack"));
		ResourcesManager::GetInst().CreateSpriteFolder("player_success", FolderPath.PlusFilePath("player_success"));
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::Play);

		//애니메이션은 로드된 스프라이트를 가지고 만든다.3
		MainRenderer->CreateAnimation("player_idle", "player_idle", 0, 11, 0.06f, true);
			
		MainRenderer->CreateAnimation("player_run", "player_run", 0, 5, 0.06f, false);
		MainRenderer->CreateAnimation("player_attack", "player_attack", 0, 12, 0.06f, false);
		MainRenderer->CreateAnimation("player_success", "player_success", 0, 18, 0.12f, false);

		MainRenderer->ChangeAnimation("player_idle");
		//MainRenderer->Flip();
		MainRenderer->SetRenderScaleToTexture();
	}

	//이펙트 추가
	GameEngineLevel* Level = GetLevel();
	PlayerVFX = Level->CreateActor<VFX>();

	ChangeState(PlayerState::Idle);
	Dir = float4::RIGHT;

}

void Player::Update(float _Delta)
{
	
	Moved = false; // 이동 초기화
	StateUpdate(_Delta);
	//카메라 포커스가 온이면 카메라를 따라가게 한다
	if (true == CameraFoucus)
	{
		float4 WindowScale = GameEngineWindow::MainWindow.GetScale();
		GetLevel()->GetMainCamera()->SetPos(float4{ 0.0f, GetPos().Y} + float4{0, -(WindowScale.hY()+ TILESIZE*3)});
	}
	
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

void Player::ChangeState(PlayerState _State)
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


void Player::TrapChek(float4 _ObsTilePos)
{
	
	if (_ObsTilePos == GetPlayerTilePos())
	{
		PlayerVFX->Blood_VFXOn(TilePos);
		HP--;
		GameEngineSound::SoundPlay("spikes_damage_01.wav");
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
	if (HP == -1 and GodMode == false)
	{
		PlayLevelPtr->GetLevelChange()->ChangeState(LevelState::Death);
	}
}

void Player::Render(float _Delta)
{
	std::string Text = "";
	Text += "플레이어 테스트 값 : ";
	Text += std::to_string(1.0f / _Delta);
	HDC dc = GameEngineWindow::MainWindow.GetBackBuffer()->GetImageDC();
	TextOutA(dc, 2, 3, Text.c_str(), static_cast<int>(Text.size()));
}