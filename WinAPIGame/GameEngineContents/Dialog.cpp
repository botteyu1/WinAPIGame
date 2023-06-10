#include "Dialog.h"
#include "ContentsEnum.h"
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "PlayLevel.h"
#include "LevelChange.h"
#include "Player.h"
Dialog::Dialog() 
{
}

Dialog::~Dialog()
{
}

void Dialog::Start()
{

	if (false == ResourcesManager::GetInst().IsLoadTexture("dialogueBG_hell.bmp"))
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
		FilePath.MoveChild("ContentsResources\\Texture\\dialog\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("dialogueBG_hell.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("button0001.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("button0002.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("pand\\pand_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("pand\\pand_flust.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("modeus\\mod_close.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("modeus\\mod_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cer\\cer_happy.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cer\\cer_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mal\\mal_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mal\\mal_puzzled.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("zdra\\z_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("zdra\\z_laugh.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("az\\az_note.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("az\\az_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("jus\\jus_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("jus\\jus_curious.png"));
		ResourcesManager::GetInst().CreateSpriteFolder("booper", FilePath.PlusFilePath("booper"));
		ResourcesManager::GetInst().CreateSpriteFolder("Success", FilePath.PlusFilePath("Success"));
		ResourcesManager::GetInst().CreateSpriteFolder("BadEnd", FilePath.PlusFilePath("BadEnd"));

		GameEngineWindowTexture* T = ResourcesManager::GetInst().TextureCreate("dialogueBG_Fade", { 1920, 1080 });
		T->FillTexture(RGB(2, 2, 27));
	}
		GameEngineRenderer* Render = CreateRenderer("dialogueBG_Fade", RenderOrder::Dialouge);
		float4 Scale = Render->GetRenderScale().Half();
		Render->SetRenderPos(Scale);
		
		Render = CreateRenderer("dialogueBG_hell.bmp", RenderOrder::Dialouge);
		Scale = Render->GetRenderScale().Half();
		Render->SetRenderPos(Scale+ float4{0.0f,170.0f});

		SuccessRenderer = CreateRenderer(RenderOrder::Dialouge);
		SuccessRenderer->CreateAnimation("Success", "Success", 0, 7, 0.07f, false);
		SuccessRenderer->ChangeAnimation("Success");
		SuccessRenderer->SetRenderPos({ 960, 970 });
		SuccessRenderer->Off();

		BadEndRenderer = CreateRenderer(RenderOrder::Dialouge);
		BadEndRenderer->CreateAnimation("BadEnd", "BadEnd", 0, 8, 0.07f, false);
		BadEndRenderer->ChangeAnimation("BadEnd");
		BadEndRenderer->SetRenderPos({ 960, 500 });
		BadEndRenderer->Off();

		NameTextRenderer = CreateRenderer(RenderOrder::Dialouge);
		NameTextRenderer->SetRenderPos({ 960, 780 });
		NameTextRenderer->SetText("26", 60, "양재참숯체B", RGB(230,77,81));

		MainTextRenderer = CreateRenderer(RenderOrder::Dialouge);
		MainTextRenderer->SetRenderPos({ 960, 830 });
		MainTextRenderer->SetText("26", 60, "양재참숯체B", RGB(0,0,0));

		AnswerRenderer1On = CreateRenderer("button0001.png",RenderOrder::Dialouge);
		AnswerRenderer1On->SetRenderPos({ 960, 920 });
		AnswerRenderer1On->Off();
		AnswerRenderer1Off = CreateRenderer("button0002.png",RenderOrder::Dialouge);
		AnswerRenderer1Off->SetRenderPos({ 960, 920 });
		AnswerRenderer1Off->Off();

		AnswerRenderer2On = CreateRenderer("button0001.png",RenderOrder::Dialouge);
		AnswerRenderer2On->SetRenderPos({ 960, 1010 });
		AnswerRenderer2On->Off();
		AnswerRenderer2Off = CreateRenderer("button0002.png",RenderOrder::Dialouge);
		AnswerRenderer2Off->SetRenderPos({ 960, 1010 });
		AnswerRenderer2Off->Off();

		AnswerTextRenderer1 = CreateRenderer(RenderOrder::Dialouge);
		AnswerTextRenderer1->SetRenderPos({ 960, 936 });
		AnswerTextRenderer1->Off();
		
		AnswerTextRenderer2 = CreateRenderer(RenderOrder::Dialouge);
		AnswerTextRenderer2->SetRenderPos({ 960, 1026 });
		AnswerTextRenderer2->Off();

		MainNPCRenderer = CreateRenderer(RenderOrder::Dialouge);
		MainNPCRenderer->SetRenderPos({ 960, 350 });
		
		
		Off();
}

void Dialog::Init(int _StageLevel)
{
	SetDialogData(_StageLevel);
}

void Dialog::ChangeState(DialogState _State)
{
	
	switch (_State)
	{
	case DialogState::Conversation:
		ConversationStart();
		break;
	case DialogState::Answer:
		AnswerStart();
		break;
	case DialogState::Success:
		SuccessStart();
		break;
	case DialogState::BadEnd:
		BadEndStart();
		break;
	case DialogState::On:
		OnStart();
		break;
	case DialogState::Off:
		OffStart();
		break;
	case DialogState::Max:
		break;
	default:
		break;
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
	case DialogState::Conversation:
		ConversationUpdate(_Delta);
		break;
	case DialogState::Answer:
		AnswerUpdate(_Delta);
		break;
	case DialogState::Success:
		SuccessUpdate(_Delta);
		break;
	case DialogState::BadEnd:
		BadEndUpdate(_Delta);
		break;
	case DialogState::On:
		OnUpdate(_Delta);
		break;
	case DialogState::Off:
		OffUpdate(_Delta);
		break;
	case DialogState::Max:
		break;
	default:
		break;
	}
}

void Dialog::ConversationStart()
{
	
	Conversation Con = ConversationList[CurConversationIndex];
	MainTextRenderer->SetText(Con.Text, 35, "양재참숯체B", RGB(255,255, 255));

	// npc스탠딩 이미지 변경
	if (Con.NPCStanding != "")
	{
		MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
	}

}

void Dialog::AnswerStart()
{
	AnswerRenderer1On->On();
	AnswerRenderer2Off->On();
	AnswerTextRenderer1->On();
	AnswerTextRenderer2->On();
	
}

void Dialog::SuccessStart()
{
	Conversation Con = ConversationList[CurConversationIndex];
	MainTextRenderer->SetText(Con.Text, 35, "양재참숯체B", RGB(255, 255, 255));

	SuccessRenderer->On();
	SuccessRenderer->ChangeAnimation("Success");

	// npc스탠딩 이미지 변경
	if (Con.NPCStanding != "")
	{
		MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
	}
}

void Dialog::BadEndStart()
{
	NameTextRenderer->Off();
	MainNPCRenderer->Off();
	MainTextRenderer->SetText(BadEndConversation.Text, 35, "양재참숯체B", RGB(205, 20, 16), 30);
	BadEndRenderer->On();
	BadEndRenderer->ChangeAnimation("BadEnd");
}

void Dialog::OnStart()
{
	On();
	CurAnswer = 1;
	CurConversationIndex = 0;
	NameTextRenderer->On();
	MainNPCRenderer->On();
	BadEndRenderer->Off();
}

void Dialog::OffStart()
{
	Off();
}




void Dialog::ConversationUpdate(float _Delta)
{
	if (true == GameEngineInput::IsDown('K'))
	{
		ChangeState(DialogState::Off);
	}
	if (true == GameEngineInput::IsDown(VK_RETURN))
	{
		Conversation Con = ConversationList[CurConversationIndex];
		
		

		// 대화가 끝났는지 정답인지 확인
		if (Con.IsEnd == true)
		{
			if (CurAnswer == CorrectAnswer)
			{
				ChangeState(DialogState::Success);
			}
			else
			{
				//CurConversationIndex = Con.Right;
				ChangeState(DialogState::BadEnd);
			}
		}
		//대답하는 상황인지 
		else if (Con.IsAnswer == true)
		{
			ChangeState(DialogState::Answer);
		}
		// 둘다아니면 대화 이어서 진행
		else if(Con.IsAnswer == false)
		{
			if (Con.Left == 0)
			{
				CurConversationIndex++;
			}
			else
			{
				CurConversationIndex = Con.Left;
			}
			ChangeState(DialogState::Conversation);
		}
		
	}
}

void Dialog::AnswerUpdate(float _Delta)
{
	if(true == GameEngineInput::IsDown('W'))
	{
		AnswerRenderer1On->On();
		AnswerRenderer1Off->Off();
		AnswerRenderer2On->Off();
		AnswerRenderer2Off->On();
		CurAnswer = 1;
		
	}
	
	if(true == GameEngineInput::IsDown('S'))
	{
		AnswerRenderer1On->Off();
		AnswerRenderer1Off->On();
		AnswerRenderer2On->On();
		AnswerRenderer2Off->Off();
		CurAnswer = 2;
	}

	if (true == GameEngineInput::IsDown(VK_RETURN))
	{
		AnswerRenderer1On->Off();
		AnswerRenderer1Off->Off();
		AnswerRenderer2On->Off();
		AnswerRenderer2Off->Off();
		AnswerTextRenderer1->Off();
		AnswerTextRenderer2->Off();

		Conversation Con = ConversationList[CurConversationIndex];
		if (CurAnswer == CorrectAnswer)
		{
			CurConversationIndex = Con.Left;
			
		}
		else
		{
			CurConversationIndex = Con.Right;
		}
		ChangeState(DialogState::Conversation);
	}
}

void Dialog::SuccessUpdate(float _Delta)
{
	if (true == SuccessRenderer->IsAnimationEnd() and true == GameEngineInput::IsDown(VK_RETURN))
	{
		Player* PlayerPtr = Player::GetMainPlayer();
		PlayerPtr->ChangeState(PlayerState::Success);

		SuccessRenderer->Off();
		ChangeState(DialogState::Off);
	}
}

void Dialog::BadEndUpdate(float _Delta)
{
	if (true == BadEndRenderer->IsAnimationEnd() and true == GameEngineInput::IsDown(VK_RETURN))
	{
		PlayLevel* PlayLevelPtr = static_cast<PlayLevel*>(GetLevel());
		
		PlayLevelPtr->GetLevelChange()->ChangeState(LevelState::Transition);
	}
}

void Dialog::OnUpdate(float _Delta)
{
	ChangeState(DialogState::Conversation);
}

void Dialog::OffUpdate(float _Delta)
{
	
}


