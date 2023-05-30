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
		//로드하면서 스프라이트를 생성한다
		ResourcesManager::GetInst().CreateSpriteFolder("leveltransition", FolderPath.PlusFilePath("leveltransition"));
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::LevelChange);
		//GameEngineRenderer* Render = CreateRenderer(_FileName, RenderOrder::BackGround);

		//애니메이션은 로드된 스프라이트를 가지고 만든다.3
		MainRenderer->CreateAnimation("leveltransition", "leveltransition", 0, 28, 0.07f, false);
		MainRenderer->ChangeAnimation("leveltransition");
		float4 Scale = GameEngineWindow::MainWindow.GetScale().Half();
		MainRenderer->SetRenderPos(Scale);

		MainRenderer->Off();
		//MainRenderer->SetRenderScaleToTexture();
	}
}

void LevelChange::Update(float _Delta)
{

	//StateUpdate(_Delta);
}

void LevelChange::ChanageState(LevelState _State)
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
	
}


void LevelChange::IdleStart()
{

}

void LevelChange::TransitionStart()
{
	MainRenderer->ChangeAnimation("leveltransition");
	MainRenderer->On();

}

void LevelChange::DeathStart()
{
}

void LevelChange::IdleUpdate(float _Delta)
{
}

void LevelChange::TransitionUpdate(float _Delta)
{

}

void LevelChange::DeathUpdate(float _Delta)
{
}
