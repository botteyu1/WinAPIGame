#include "DialogEnding.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEnginePlatform/GameEngineWindow.h>

DialogEnding::DialogEnding() 
{
}

DialogEnding::~DialogEnding()
{
}

void DialogEnding::Start()
{
	Dialog::Start();

	MainCutSceneBGRenderer = CreateUIRenderer("cutscenebg", RenderOrder::DialougeBG);
	MainCutSceneBGRenderer->SetRenderPos({ 960, 400 });
	MainCutSceneBGRenderer->SetMaskTexture("cutscenebg_mask.bmp");
	MainCutSceneBGRenderer->Off();

	Conversation Con;
	NameTextRenderer->SetText("�� ������ �ĸ� �������� ��", 45, "��������üB", RGB(230, 77, 81));

	Con = { "...", "Fade" };
	ConversationList.push_back(Con);
	Con = { "�׸��Ͽ� ������Ŀ�� �̾߱�� ���� ����.", "cutscene0005" };
	ConversationList.push_back(Con);
	Con = { "���� ģ�� ���������� ����־��ٳ�.", "" };
	ConversationList.push_back(Con);
	Con = { "���� ��Ű��� �̾߱��� �� ������.", "cutscene0006" };
	ConversationList.push_back(Con);
	Con = { "������ �����ڸ�... ��� �����ϰ� ���������� �̾߱���.", "" };
	ConversationList.push_back(Con);
	Con = { "������ ����鿡 ���� ������ �̾߱�.", "cutscene0007" };
	ConversationList.push_back(Con);
	Con = { "������ �����ڸ�... ��� �����ϰ� ���������� �̾߱���.", "" };
	ConversationList.push_back(Con);
	Con = { "������ ��¼��... �ϸ��� �ູ�� ã�� �� ���� ������.", "cutscene0008" };
	ConversationList.push_back(Con);
	Con = { "�� �ι� ������ ���� �� �ְ���?", "" };
	ConversationList.push_back(Con);
	Con = { "�׷�... ���� �ĸ��� �Բ� ���༭ ������.", "" };
	ConversationList.push_back(Con);
	Con = { "�׷� ������.", "" };
	ConversationList.push_back(Con);
	Con = { "THE END", "" };
	Con.EndOn();
	ConversationList.push_back(Con);

	ChangeState(DialogState::On);
}

void DialogEnding::ConversationStart()
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

void DialogEnding::ConversationUpdate(float _Delta)
{
	if (MainCutSceneBGRenderer->GetCopyScale().X > MainCutSceneBGRenderer->GetRenderScale().X)
	{
		float4 Scale = MainCutSceneBGRenderer->GetCopyScale();
		MainCutSceneBGRenderer->AddRenderScale(Scale * 4.0f * _Delta);
	}
	else if (MainCutSceneBGRenderer->IsUpdate() == true)
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
			GameEngineWindow::WindowLoopOff();
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

//void DialogEnding::Update(float _Delta)
//{
//}

