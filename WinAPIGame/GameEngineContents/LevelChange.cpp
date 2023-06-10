#include "LevelChange.h"
#include <GameEngineCore/ResourcesManager.h>
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>



LevelChange::LevelChange()
{
	
}

LevelChange::~LevelChange()
{
}

void LevelChange::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("transition0002.png"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");

		FolderPath.MoveChild("ContentsResources\\Texture\\");
		//�ε��ϸ鼭 ��������Ʈ�� �����Ѵ�
		ResourcesManager::GetInst().CreateSpriteFolder("leveltransition", FolderPath.PlusFilePath("leveltransition"));
		ResourcesManager::GetInst().CreateSpriteFolder("leveldeath", FolderPath.PlusFilePath("leveldeath"));

	}

	{
		DeathRenderer = CreateRenderer(RenderOrder::LevelChange);
		MainRenderer = CreateRenderer(RenderOrder::LevelChange);
		//GameEngineRenderer* Render = CreateRenderer(_FileName, RenderOrder::BackGround);

		//�ִϸ��̼��� �ε�� ��������Ʈ�� ������ �����.3
		MainRenderer->CreateAnimation("leveltransition", "leveltransition", 0, 28, 0.05f, false);
		DeathRenderer->CreateAnimation("leveldeath", "leveldeath", 0, 17, 0.05f, false);

		MainRenderer->ChangeAnimation("leveltransition");
		DeathRenderer->ChangeAnimation("leveldeath");

		float4 Scale = GameEngineWindow::MainWindow.GetScale().Half();
		MainRenderer->SetRenderPos(Scale);
		DeathRenderer->SetRenderPos(Scale);

		State = LevelState::Transition; 
		
		MainRenderer->SetCurFrame(15);

		MainRenderer->SetRenderScaleToTexture();

		DeathRenderer->Off();
	}
}

void LevelChange::Update(float _Delta)
{

	StateUpdate(_Delta);
}

void LevelChange::ChangeState(LevelState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case LevelState::Idle:
			IdleStart();
			break;
		case LevelState::Transition:
			TransitionStart();
			break;
		case LevelState::Death:
			DeathStart();
			break;
		case LevelState::Max:
			break;
		default:
			break;
		}
	}
	State = _State;
}

void LevelChange::StateUpdate(float _Delta)
{
	switch (State)
	{
	case LevelState::Idle:
		IdleUpdate(_Delta);
		break;
	case LevelState::Transition:
		TransitionUpdate(_Delta);
		break;
	case LevelState::Death:
		DeathUpdate(_Delta);
		break;
	case LevelState::Max:
		break;
	default:
		break;
	}
}


void LevelChange::IdleStart()
{
	CoverFullScreen = false;
	Off();
	MainRenderer->Off();
	DeathRenderer->Off();
}

void LevelChange::TransitionStart()
{
	MainRenderer->ChangeAnimation("leveltransition");
	MainRenderer->SetCurFrame(0);
	On();
	MainRenderer->On();

}

void LevelChange::DeathStart()
{
	DeathRenderer->ChangeAnimation("leveldeath");
	DeathRenderer->SetCurFrame(0);
	On();
	DeathRenderer->On();
}

void LevelChange::IdleUpdate(float _Delta)
{
}

void LevelChange::TransitionUpdate(float _Delta)
{
	if (MainRenderer->GetCurFrame() == 14)
	{
		CoverFullScreen = true;
		DeathRenderer->Off();
	}

	if (MainRenderer->IsAnimationEnd())
	{
		MainRenderer->Off();
		ChangeState(LevelState::Idle);
	}
}

void LevelChange::DeathUpdate(float _Delta)
{
	

	if (DeathRenderer->IsAnimationEnd())
	{
		ChangeState(LevelState::Transition);
	}
}
