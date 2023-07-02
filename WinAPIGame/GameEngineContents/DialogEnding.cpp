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
	NameTextRenderer->SetText("● 위대한 파리 베엘제붑 ●", 45, "양재참숯체B", RGB(230, 77, 81));

	Con = { "...", "Fade" };
	ConversationList.push_back(Con);
	Con = { "그리하여 헬테이커의 이야기는 끝이 났지.", "cutscene0005" };
	ConversationList.push_back(Con);
	Con = { "오랜 친구 베엘제붑이 들려주었다네.", "" };
	ConversationList.push_back(Con);
	Con = { "나도 등신같은 이야기인 건 알지만.", "cutscene0006" };
	ConversationList.push_back(Con);
	Con = { "솔직히 말하자면... 사실 불쾌하고 혐오스러운 이야기지.", "" };
	ConversationList.push_back(Con);
	Con = { "불쾌한 사람들에 대한 불쾌한 이야기.", "cutscene0007" };
	ConversationList.push_back(Con);
	Con = { "솔직히 말하자면... 사실 불쾌하고 혐오스러운 이야기지.", "" };
	ConversationList.push_back(Con);
	Con = { "하지만 어쩌면... 일말의 행복은 찾을 수 있지 않을까.", "cutscene0008" };
	ConversationList.push_back(Con);
	Con = { "한 두번 정도는 웃을 수 있겠지?", "" };
	ConversationList.push_back(Con);
	Con = { "그럼... 늙은 파리와 함께 해줘서 고마웠네.", "" };
	ConversationList.push_back(Con);
	Con = { "그럼 다음에.", "" };
	ConversationList.push_back(Con);
	Con = { "THE END", "" };
	Con.EndOn();
	ConversationList.push_back(Con);

	ChangeState(DialogState::On);
}

void DialogEnding::ConversationStart()
{
	Conversation Con = ConversationList[CurConversationIndex];
	MainTextRenderer->SetText(Con.Text, 35, "양재참숯체B", RGB(255, 255, 255));
	MainNPCRenderer->On();
	BooperRenderer->On();
	BooperRenderer->SetCurFrame(0);

	// npc스탠딩 이미지 변경
	if (Con.NPCStanding != "" and Con.NPCStanding != "Fade")
	{
		//컷씬인 경우 컷씬 배경 생성
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

		// 대화가 끝났는지 정답인지 확인
		if (Con.IsEnd == true)
		{
			GameEngineWindow::WindowLoopOff();
		}
		//대답하는 상황인지 
		else if (Con.IsAnswer == true)
		{
			GameEngineSound::SoundPlay("dialogue_text_end_01.wav");
			ChangeState(DialogState::Answer);
		}
		// 둘다아니면 대화 이어서 진행
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

