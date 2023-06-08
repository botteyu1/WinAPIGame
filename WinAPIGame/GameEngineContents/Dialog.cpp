#include "Dialog.h"
#include "ContentsEnum.h"
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
Dialog::Dialog() 
{
}

Dialog::~Dialog()
{
}

void Dialog::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("dialogueBG_hell.png"))
	{
		// 무조건 자동으로 현재 실행중인 위치가 된다.
		// 경로
		// 시작위치 D:\Project\AR47\Winapi\AR47WinApi\Bin\x64\Debug
		// 
		// 시작위치 D:\Project\AR47\Winapi\AR47WinApi\GameEngineApp
		// 도착위치 D:\Project\AR47\Winapi\AR47WinApi\ContentsResources\Texture\Player
		GameEnginePath FilePath;
		// 시작위치 D:\Project\AR47\Winapi\AR47WinApi\GameEngineApp
		FilePath.SetCurrentPath();
		// 시작위치 D:\Project\AR47\Winapi\AR47WinApi

		// ContentsResources

		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\bg\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("dialogueBG_hell.png"));
		GameEngineWindowTexture* T = ResourcesManager::GetInst().TextureCreate("dialogueBG_Fade", { 1920, 1080 });
		T->FillTexture(RGB(2, 2, 27));

		GameEngineRenderer* Render = CreateRenderer("dialogueBG_Fade", RenderOrder::Dialouge);
		float4 Scale = Render->GetRenderScale().Half();
		Render->SetRenderPos(Scale);
		
		Render = CreateRenderer("dialogueBG_hell.png", RenderOrder::Dialouge);
		Scale = Render->GetRenderScale().Half();
		Render->SetRenderPos(Scale+ float4{0.0f,170.0f});

		Off();
	}
}

void Dialog::ChanageState(DialogeState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case DialogeState::Conversation:
			ConversationStart();
			break;
		case DialogeState::Answer:
			AnswerStart();
			break;
		case DialogeState::On:
			OnStart();
			break;
		case DialogeState::Off:
			OffStart();
			break;
		case DialogeState::Max:
			break;
		default:
			break;
		}
	}
	State = _State;
}

void Dialog::Update(float _Delta)
{
	
	StateUpdate(_Delta);
}

void Dialog::StateUpdate(float _Delta)
{
	switch (State)
	{
	case DialogeState::Conversation:
		ConversationUpdate(_Delta);
		break;
	case DialogeState::Answer:
		AnswerUpdate(_Delta);
		break;
	case DialogeState::On:
		OnUpdate(_Delta);
		break;
	case DialogeState::Off:
		OffUpdate(_Delta);
		break;
	case DialogeState::Max:
		break;
	default:
		break;
	}
}

void Dialog::ConversationStart()
{
	

}

void Dialog::AnswerStart()
{
}

void Dialog::OnStart()
{
	On();
	
}

void Dialog::OffStart()
{
	Off();
}


void Dialog::ConversationUpdate(float _Delta)
{
	if (true == GameEngineInput::IsDown('K'))
	{
		ChanageState(DialogeState::Off);
	}
}

void Dialog::AnswerUpdate(float _Delta)
{
}

void Dialog::OnUpdate(float _Delta)
{
	ChanageState(DialogeState::Conversation);
}

void Dialog::OffUpdate(float _Delta)
{
}


