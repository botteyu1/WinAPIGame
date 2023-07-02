#include "Dialog.h"
#include "ContentsEnum.h"
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "PlayLevel.h"
#include "LevelChange.h"
#include "Player.h"
#include <GameEnginePlatform/GameEngineSound.h>
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
		// ���
		// ������ġ D:\Project\AR47\Winapi\AR47WinApi\Bin\x64\Debug
		// 
		// ������ġ D:\Project\AR47\Winapi\AR47WinApi\GameEngineApp
		// ������ġ D:\Project\AR47\Winapi\AR47WinApi\ContentsResources\Texture\Player
		GameEnginePath FilePath;
		// ������ġ D:\Project\AR47\Winapi\AR47WinApi\GameEngineApp
		FilePath.SetCurrentPath();
		// ������ġ D:\Project\AR47\Winapi\AR47WinApi

		// ContentsResources

		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\dialog\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("dialogueBG_hell.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("dialogueBG_abyss.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("dialogueBG_throne2.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("introTexture.bmp"));
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
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("beel\\beel_fly.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("beel\\dummy.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0002.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0003.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0004.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0005.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0006.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0007.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscene0008.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("cutscene\\cutscenebg_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("LH\\LH_swirl.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("LH\\LH_idle.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("LH\\LH_angry.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("LH\\LH_happy.png"));
		ResourcesManager::GetInst().CreateSpriteFolder("booper", FilePath.PlusFilePath("booper"));
		ResourcesManager::GetInst().CreateSpriteFolder("Success", FilePath.PlusFilePath("Success"));
		ResourcesManager::GetInst().CreateSpriteFolder("BadEnd", FilePath.PlusFilePath("BadEnd"));

		if (false == ResourcesManager::GetInst().IsLoadTexture("BG_Fade"))
		{
			GameEngineWindowTexture* Texture = ResourcesManager::GetInst().TextureCreate("BG_Fade", { 1920, 1080 });
			Texture->FillTexture(RGB(2, 2, 27));
		}
		GameEngineWindowTexture* Texture = ResourcesManager::GetInst().TextureCreate("cutscenebg", { 1280, 652 });
		Texture->FillTexture(RGB(116, 40, 54));

		// ����
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Audio\\");
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("dialogue_text_end_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("dialogue_success_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("dialogue_start_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("button_chapter_confirm_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("button_chapter_highlight_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("button_dialogue_confirm_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("button_dialogue_highlight_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("button_menu_confirm_01.wav"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("button_menu_highlight_01.wav"));
	
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("bad_end_screen_01.wav"));
		
	}
		GameEngineRenderer* Render = CreateUIRenderer("BG_Fade", RenderOrder::DialougeBG);
		float4 Scale = Render->GetRenderScale().Half();
		Render->SetRenderPos(Scale);
		
		MainBGRenderer = CreateUIRenderer("dialogueBG_hell.bmp", RenderOrder::DialougeBG);
		Scale = MainBGRenderer->GetRenderScale().Half();
		MainBGRenderer->SetRenderPos(Scale+ float4{0.0f,170.0f});

		SuccessRenderer = CreateUIRenderer(RenderOrder::Dialouge);
		SuccessRenderer->CreateAnimation("Success", "Success", 0, 7, 0.07f, false);
		SuccessRenderer->ChangeAnimation("Success");
		SuccessRenderer->SetRenderPos({ 960, 970 });
		SuccessRenderer->Off();

		BadEndRenderer = CreateUIRenderer(RenderOrder::Dialouge);
		BadEndRenderer->CreateAnimation("BadEnd", "BadEnd", 0, 8, 0.07f, false);
		BadEndRenderer->ChangeAnimation("BadEnd");
		BadEndRenderer->SetRenderPos({ 960, 500 });
		BadEndRenderer->Off();

		BooperRenderer = CreateUIRenderer(RenderOrder::Dialouge);
		BooperRenderer->CreateAnimation("booper", "booper", 0, 16, 0.04f, true);
		BooperRenderer->ChangeAnimation("booper");
		BooperRenderer->SetRenderPos({ 960, 950 });
		BooperRenderer->Off();

		//BooperTabRenderer = CreateRenderer(RenderOrder::Dialouge);
		//BooperTabRenderer->CreateAnimation("booper", "booper", 0, 10, 0.07f, false);
		//BooperTabRenderer->ChangeAnimation("booper");
		//BooperTabRenderer->SetRenderPos({ 960, 950 });
		//BooperTabRenderer->AnimationEndOff();
		//BooperTabRenderer->Off();

		NameTextRenderer = CreateUIRenderer(RenderOrder::Dialouge);
		NameTextRenderer->SetRenderPos({ 960, 780 });
		NameTextRenderer->SetText("26", 60, "��������üB", RGB(230,77,81));

		MainTextRenderer = CreateUIRenderer(RenderOrder::Dialouge);
		MainTextRenderer->SetRenderPos({ 960, 830 });
		MainTextRenderer->SetText("26", 60, "��������üB", RGB(0,0,0));

		AnswerRenderer1On = CreateUIRenderer("button0001.png",RenderOrder::Dialouge);
		AnswerRenderer1On->SetRenderPos({ 960, 920 });
		AnswerRenderer1On->Off();
		AnswerRenderer1Off = CreateUIRenderer("button0002.png",RenderOrder::Dialouge);
		AnswerRenderer1Off->SetRenderPos({ 960, 920 });
		AnswerRenderer1Off->Off();

		AnswerRenderer2On = CreateUIRenderer("button0001.png",RenderOrder::Dialouge);
		AnswerRenderer2On->SetRenderPos({ 960, 1010 });
		AnswerRenderer2On->Off();
		AnswerRenderer2Off = CreateUIRenderer("button0002.png",RenderOrder::Dialouge);
		AnswerRenderer2Off->SetRenderPos({ 960, 1010 });
		AnswerRenderer2Off->Off();

		AnswerTextRenderer1 = CreateUIRenderer(RenderOrder::Dialouge);
		AnswerTextRenderer1->SetRenderPos({ 960, 936 });
		AnswerTextRenderer1->Off();
		
		AnswerTextRenderer2 = CreateUIRenderer(RenderOrder::Dialouge);
		AnswerTextRenderer2->SetRenderPos({ 960, 1026 });
		AnswerTextRenderer2->Off();

		MainNPCRenderer = CreateUIRenderer(RenderOrder::Dialouge);
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
	MainTextRenderer->SetText(Con.Text, 35, "��������üB", RGB(255,255, 255));
	MainNPCRenderer->On();
	BooperRenderer->On();
	BooperRenderer->SetCurFrame(0);
	// npc���ĵ� �̹��� ����
	if (Con.NPCStanding != "" and Con.NPCStanding != "Fade")
	{
		
		MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
	}

}

void Dialog::AnswerStart()
{
	Conversation Con = AnswerList[CurAnswerIndex++];
	AnswerTextRenderer1->SetText(Con.Text, 30, "��������üB", RGB(255, 255, 255));
	 Con = AnswerList[CurAnswerIndex++];
	AnswerTextRenderer2->SetText(Con.Text, 30, "��������üB", RGB(255, 255, 255));
	AnswerRenderer1On->On();
	AnswerRenderer2Off->On();
	AnswerTextRenderer1->On();
	AnswerTextRenderer2->On();
	BooperRenderer->Off();

	
	
}

void Dialog::SuccessStart()
{
	Conversation Con = ConversationList[CurConversationIndex];
	MainTextRenderer->SetText(Con.Text, 35, "��������üB", RGB(255, 255, 255));

	SuccessRenderer->On();
	SuccessRenderer->ChangeAnimation("Success");
	BooperRenderer->Off();

	// npc���ĵ� �̹��� ����
	if (Con.NPCStanding != "")
	{
		MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
	}
	//GameEngineSound::SoundPlay("dialogue_success_01.wav");
	
}

void Dialog::BadEndStart()
{
	MainBGRenderer->Off();
	MainNPCRenderer->Off();
	NameTextRenderer->Off();
	MainNPCRenderer->Off();
	MainTextRenderer->SetText(BadEndConversation.Text, 35, "��������üB", RGB(205, 20, 16), 30);
	BadEndRenderer->On();
	BooperRenderer->Off();
	BadEndRenderer->ChangeAnimation("BadEnd");
	GameEngineSound::SoundPlay("bad_end_screen_01.wav");
}

void Dialog::OnStart()
{
	On();
	CurAnswer = 1;
	CurConversationIndex = 0;
	CurAnswerIndex = 0;
	NameTextRenderer->On();
	MainNPCRenderer->On();
	BadEndRenderer->Off();
	MainBGRenderer->On();
	MainNPCRenderer->On();
	GameEngineSound::SoundPlay("dialogue_start_01.wav");
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
		BooperRenderer->Off();
		Conversation Con = ConversationList[CurConversationIndex];
		
		// ��ȭ�� �������� �������� Ȯ��
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
		//����ϴ� ��Ȳ���� 
		else if (Con.IsAnswer == true)
		{
			GameEngineSound::SoundPlay("dialogue_text_end_01.wav");
			ChangeState(DialogState::Answer);
		}

		// �Ѵپƴϸ� ��ȭ �̾ ����
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
			GameEngineSound::SoundPlay("dialogue_text_end_01.wav");
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
		GameEngineSound::SoundPlay("button_menu_highlight_01.wav");
	}
	
	if(true == GameEngineInput::IsDown('S'))
	{
		AnswerRenderer1On->Off();
		AnswerRenderer1Off->On();
		AnswerRenderer2On->On();
		AnswerRenderer2Off->Off();
		CurAnswer = 2;
		GameEngineSound::SoundPlay("button_chapter_highlight_01.wav");
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

		// ������ ���� Ʋ���� ������
		if (CurAnswer == CorrectAnswer)
		{
			CurConversationIndex = Con.Left;
			GameEngineSound::SoundPlay("dialogue_success_01.wav");
		}
		else
		{
			
			CurConversationIndex = Con.Right;
			GameEngineSound::SoundPlay("button_dialogue_confirm_01.wav");
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


