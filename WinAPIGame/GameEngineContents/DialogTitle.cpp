#include "DialogTitle.h"
#include "Dialog.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include "ContentsEnum.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCore.h>
#include "TitleLevel.h"
#include "LevelChange.h"
#include <GameEnginePlatform/GameEngineWindow.h>

DialogTitle::DialogTitle() 
{
}

DialogTitle::~DialogTitle()
{
}

void DialogTitle::Start()
{
	Dialog::Start();


	
	MainBGRenderer->SetTexture("dialogueBG_abyss.bmp");
	MainBGRenderer2 = CreateUIRenderer("dialogueBG_abyss.bmp", RenderOrder::DialougeBG);
	float4 Scale = MainBGRenderer2->GetRenderScale();
	MainBGRenderer->SetRenderPos(Scale.Half() + float4{ 0.0f,170.0f } );
	MainBGRenderer2->SetRenderPos(Scale.Half() + float4{ 0.0f,170.0f }+ float4{ -Scale.X, 0.0f });


	MainCutSceneBGRenderer = CreateUIRenderer("cutscenebg", RenderOrder::DialougeBG);
	MainCutSceneBGRenderer->SetRenderPos({ 960, 400 });
	MainCutSceneBGRenderer->SetMaskTexture("cutscenebg_mask.bmp");
	MainCutSceneBGRenderer->Off();

	IntroRenderer = CreateUIRenderer("introTexture.bmp", RenderOrder::DialougeBG);
	Scale = IntroRenderer->GetRenderScale();
	IntroRenderer->SetRenderPos(Scale.Half());
	IntroRenderer->Off();


	Conversation Con;
	NameTextRenderer->SetText("�� ������ �ĸ� �������� ��", 45, "��������üB", RGB(230, 77, 81));

	Con = { "����� ���㿡 �۽��� ���� ������. \n ��� �Ϸ���[ENTER]Ű�� �����ÿ�.", "dummy" };
	ConversationList.push_back(Con);


	Con = { "�ݰ��� �ΰ��̿�. ���� ����ġ ����. \n    ���� ���� ģ�� ���������ϼ�. ", "beel_fly" };
	Con.AnswerOn();
	Con.SetLeft(2);
	Con.SetRight(8);
	ConversationList.push_back(Con);


	Con = { "�� ����", "" };
	AnswerList.push_back(Con);
	Con = { "������", "" };
	AnswerList.push_back(Con);

	CorrectAnswer = 1;

	Con = { "�� ������Ŀ�� �̾߱⸦ ����޶��? ����ֱ�...", "" };
	ConversationList.push_back(Con);

	Con = { "Ȥ�� �ؼ��ڰ� �ʿ����� ������?", "" };
	ConversationList.push_back(Con);

	Con = { "������شٸ� �� ���ھ�.", "Fade" };
	ConversationList.push_back(Con);

	Con = { "����� ����� �Ǹ���� ������ �Ϸ��� \n �޲ٰ� �Ͼ��.", "cutscene0002" };
	ConversationList.push_back(Con);
	Con = { "������ ���� �̷�� ���� ���� ������. \n ��¼�� �� ����� �Ѿư����� �𸣰�.", "cutscene0003" };
	ConversationList.push_back(Con);
	Con = { "�Ǹ� �Ϸ��� �޷ȴٸ�, �� � �밡�� ����.\n �׸��Ͽ� ����� �������� ������ ������.", "cutscene0004" };

	Con.EndOn();
	ConversationList.push_back(Con);



	Con = { "���� �� ���� �õ� �غ����� ���� ����� ������ ���� ����.", "" };
	Con.EndOn();
	ConversationList.push_back(Con);

	BadEndConversation = { "�ǵ����ī�� ����� ���� �վƱͷ� ���������� \n �������ٿ� �ε巯�� �������� ���� ���� ���ȴ�." };

	

	//AnswerRenderer1On = CreateRenderer("button0001.png", RenderOrder::Dialouge);
	//AnswerRenderer1On->SetRenderPos({ 960, 920 });
	//AnswerRenderer0On->Off();
	//AnswerRenderer0Off = CreateRenderer("button0002.png", RenderOrder::Dialouge);
	//AnswerRenderer0Off->SetRenderPos({ 960, 920 });
	//AnswerRenderer0Off->Off();

	ChangeState(DialogState::On);
}

void DialogTitle::Update(float _Delta)
{
	Dialog::Update(_Delta);

	// ���ȭ���� �����̸鼭 ȭ����� ����� ó������ ���ƿ�
	float4 Scale = MainBGRenderer->GetRenderScale();
	MainBGRenderer->AddRenderPos(float4{ 100.0f * _Delta,0.0f });
	if (MainBGRenderer->GetRenderPos().X >= (Scale.Half().X + Scale.X))
	{
		MainBGRenderer->AddRenderPos(float4{ -Scale.X * 2, 0.0f});
	}
	MainBGRenderer2->AddRenderPos(float4{ 100.0f * _Delta,0.0f });
	if (MainBGRenderer2->GetRenderPos().X >= (Scale.Half().X + Scale.X))
	{
		MainBGRenderer2->AddRenderPos(float4{ -Scale.X * 2, 0.0f});
	}

	//���ȭ�� ������ ������ ���� ���ش�.
	if (MainBGRenderer->IsUpdate() == true)
	{
		MainBGRenderer2->On();
	}
	if (MainBGRenderer->IsUpdate() == false)
	{
		MainBGRenderer2->Off();
	}
}

void DialogTitle::ConversationStart()
{
	
	Conversation Con = ConversationList[CurConversationIndex];
	MainTextRenderer->SetText(Con.Text, 35, "��������üB", RGB(255, 255, 255));
	MainNPCRenderer->On();
	BooperRenderer->On();
	BooperRenderer->SetCurFrame(0);

	// npc���ĵ� �̹��� ����
	if (Con.NPCStanding != "" and Con.NPCStanding != "Fade")
	{
		//�ƾ��� ��� �ƾ� ��� ����
		if (Con.NPCStanding.find("cutscene") != std::string::npos)
		{
			MainNPCRenderer->SetTexture(Con.NPCStanding + ".BMP");
			MainNPCRenderer->SetRenderPos({ 960, 400 });
			MainNPCRenderer->Off();
			
			static bool SwitchAngle = true;
			if (SwitchAngle == true)
			{
				MainCutSceneBGRenderer->SetAngle(-3.0f);
			}
			else
			{
				MainCutSceneBGRenderer->SetAngle(3.0f);
			}
			SwitchAngle = !SwitchAngle;
			MainCutSceneBGRenderer->On();
			float4 Scale = MainCutSceneBGRenderer->GetCopyScale();
			MainCutSceneBGRenderer->SetRenderScale(Scale * 0.2f);

		}
		else
		{
			MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
			MainNPCRenderer->SetRenderPos({ 960, 350 });
		}
		
	}
	if (Con.NPCStanding == "Fade")
	{
		MainBGRenderer->Off();
		MainNPCRenderer->Off();
		NameTextRenderer->Off();
	}
}

void DialogTitle::SuccessStart()
{
	Conversation Con = ConversationList[CurConversationIndex];

	// npc���ĵ� �̹��� ����
	if (Con.NPCStanding != "" and Con.NPCStanding != "Fade")
	{
		if (Con.NPCStanding.find("cutscene") != std::string::npos)
		{
			MainNPCRenderer->SetTexture(Con.NPCStanding + ".BMP");
			MainNPCRenderer->SetRenderPos({ 960, 400 });
		}
		else
		{
			MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
			MainNPCRenderer->SetRenderPos({ 960, 350 });
			
		}

	}

	TitleLevel* TitleLevelPtr = static_cast<TitleLevel*>(GetLevel());

	TitleLevelPtr->GetTitleLevelChange()->ChangeState(LevelState::Transition);
}

void DialogTitle::BadEndStart()
{
	GameEngineWindow::WindowLoopOff();
	
}

void DialogTitle::OnStart()
{
	On();
	IntroRenderer->On();
	//IntroRenderer->SetAlpha(250);
	CurAnswer = 1;
	CurConversationIndex = 0;
	MainTextRenderer->Off();
	MainNPCRenderer->Off();
	BooperRenderer->Off();
	MainBGRenderer->Off();
	NameTextRenderer->Off();
	BadEndRenderer->Off();

}

void DialogTitle::ConversationUpdate(float _Delta)
{
	if (MainCutSceneBGRenderer->GetCopyScale().X > MainCutSceneBGRenderer->GetRenderScale().X)
	{
		float4 Scale = MainCutSceneBGRenderer->GetCopyScale();
		MainCutSceneBGRenderer->AddRenderScale(Scale * 4.0f * _Delta);
	}
	else if(MainCutSceneBGRenderer->IsUpdate() == true)
	{
		float4 Scale = MainCutSceneBGRenderer->GetCopyScale();
		MainCutSceneBGRenderer->SetRenderScale(Scale);
		MainNPCRenderer->On();
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
		else if (Con.IsAnswer == false)
		{
			//ù ����ȭ�鿡�� �Ѿ�� �̸��� Ų��.
			if (CurConversationIndex == 0)
			{
				NameTextRenderer->On();
			}
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

void DialogTitle::SuccessUpdate(float _Delta)
{
	
}

void DialogTitle::OnUpdate(float _Delta)
{
	//Dialog::OnUpdate(_Delta);
	static float Time = 50; 
	Time += _Delta * 100;
	float AlphaValue;
	if (255.0f <= Time)
	{
		AlphaValue = 255.0f;
	}
	else
	{
		AlphaValue = Time;
	}
	IntroRenderer->SetAlpha(static_cast<unsigned char>(AlphaValue));
	float4 Scale = IntroRenderer->GetCopyScale();
	IntroRenderer->AddRenderScale(Scale * _Delta * 0.04f);

	if (300.0f <= Time)
	{
		IntroRenderer->Off();
		MainTextRenderer->On();
		MainNPCRenderer->On();
		MainBGRenderer->On();
		
		ChangeState(DialogState::Conversation);
	}
}

void DialogTitle::AnswerUpdate(float _Delta)
{
	if (AnswerTextRenderer1->GetRenderPos().Y > 936.0f)
	{
		AnswerTextRenderer1->AddRenderPos(float4{ 0.0f,-1000.0f * _Delta });
		AnswerTextRenderer2->AddRenderPos(float4{ 0.0f,-1000.0f * _Delta });
		AnswerRenderer1Off->AddRenderPos(float4{ 0.0f,-1000.0f * _Delta });
		AnswerRenderer2Off->AddRenderPos(float4{ 0.0f,-1000.0f * _Delta });
		return;
	}
	else if (AnswerTextRenderer1->GetRenderPos().Y < 936.0f)
	{
		AnswerTextRenderer1->SetRenderPos({ 960, 936 });
		AnswerTextRenderer2->SetRenderPos({ 960, 1026 });
		AnswerRenderer1Off->SetRenderPos({ 960, 920 });
		AnswerRenderer1Off->Off();
		AnswerRenderer1On->On();
		AnswerRenderer2Off->SetRenderPos({ 960, 1010 });

	}
	if (true == GameEngineInput::IsDown('W'))
	{
		AnswerRenderer1On->On();
		AnswerRenderer1Off->Off();
		AnswerRenderer2On->Off();
		AnswerRenderer2Off->On();
		CurAnswer = 1;
		GameEngineSound::SoundPlay("button_menu_highlight_01.wav");
	}

	if (true == GameEngineInput::IsDown('S'))
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

		if (CurAnswer == CorrectAnswer)
		{
			CurConversationIndex = Con.Left;
			GameEngineSound::SoundPlay("button_menu_confirm_01.wav");
		}
		else
		{

			CurConversationIndex = Con.Right;
			GameEngineSound::SoundPlay("button_menu_confirm_01.wav");
		}
		ChangeState(DialogState::Conversation);
	}
}



