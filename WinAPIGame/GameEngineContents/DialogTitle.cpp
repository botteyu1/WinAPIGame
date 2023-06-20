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

	Conversation Con;
	NameTextRenderer->SetText("�� ������ �ĸ� �������� ��", 45, "��������üB", RGB(230, 77, 81));

	
	MainBGRenderer->SetTexture("dialogueBG_abyss.bmp");

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

	//AnswerTextRenderer1->SetText("�� ����", 30, "��������üB", RGB(255, 255, 255));
	//AnswerTextRenderer2->SetText("������", 30, "��������üB", RGB(255, 255, 255));
	CorrectAnswer = 1;

	Con = { "�� ������Ŀ�� �̾߱⸦ ����޶��? ����ֱ�...", "" };
	ConversationList.push_back(Con);

	Con = { "Ȥ�� �ؼ��ڰ� �ʿ����� ������?", "" };
	ConversationList.push_back(Con);

	Con = { "������شٸ� �� ���ھ�.", "Fade" };
	ConversationList.push_back(Con);

	Con = { "����� ����� �Ǹ���� ������ �Ϸ��� \n �޲ٰ� �Ͼ��.", "cutscene_0002_Group-2" };
	ConversationList.push_back(Con);
	Con = { "������ ���� �̷�� ���� ���� ������. \n ��¼�� �� ����� �Ѿư����� �𸣰�.", "cutscene_0003_Group-3-copy-2" };
	ConversationList.push_back(Con);
	Con = { "�Ǹ� �Ϸ��� �޷ȴٸ�, �� � �밡�� ����.\n �׸��Ͽ� ����� �������� ������ ������.", "cutscene_0004_Layer-273-copy" };

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

void DialogTitle::ConversationStart()
{
	Conversation Con = ConversationList[CurConversationIndex];
	Dialog::ConversationStart();
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
		MainNPCRenderer->SetTexture(Con.NPCStanding + ".PNG");
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
	CurAnswer = 1;
	CurConversationIndex = 0;
	NameTextRenderer->Off();
	BadEndRenderer->Off();
	MainBGRenderer->On();
	MainNPCRenderer->On();
}

void DialogTitle::ConversationUpdate(float _Delta)
{
	// �������� ���� �ִϸ��̼��� ������ �⺻ �ִϸ��̼����� ����
	//if (BooperTabRenderer->IsUpdate() == false and BooperRenderer->IsUpdate() == false)
	//{
	//	BooperRenderer->ChangeAnimation("booper");
	//	BooperRenderer->On();
	//}
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

			
			ChangeState(DialogState::Conversation);
		}
	}
}

void DialogTitle::SuccessUpdate(float _Delta)
{
	
}



