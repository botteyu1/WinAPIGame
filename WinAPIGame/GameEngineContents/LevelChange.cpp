#include "LevelChange.h"
#include <GameEngineCore/ResourcesManager.h>
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>

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
	}

	{
		MainRenderer = CreateRenderer(RenderOrder::Play);

		//�ִϸ��̼��� �ε�� ��������Ʈ�� ������ �����.3
		MainRenderer->CreateAnimation("leveltransition", "leveltransition", 0, 28, 0.07f, true);


		MainRenderer->ChangeAnimation("leveltransition");

		MainRenderer->SetRenderScaleToTexture();
	}
}

void LevelChange::Update(float _Delta)
{

	StateUpdate(_Delta);
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
