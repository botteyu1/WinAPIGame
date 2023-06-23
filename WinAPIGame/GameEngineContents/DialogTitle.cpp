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
	NameTextRenderer->SetText("● 위대한 파리 베엘제붑 ●", 45, "양재참숯체B", RGB(230, 77, 81));

	Con = { "당신은 공허에 휩싸인 것을 느꼈다. \n 계속 하려면[ENTER]키를 누르시오.", "dummy" };
	ConversationList.push_back(Con);


	Con = { "반갑네 인간이여. 나를 괘념치 말게. \n    그저 오랜 친구 베엘제붑일세. ", "beel_fly" };
	Con.AnswerOn();
	Con.SetLeft(2);
	Con.SetRight(8);
	ConversationList.push_back(Con);


	Con = { "새 게임", "" };
	AnswerList.push_back(Con);
	Con = { "나가기", "" };
	AnswerList.push_back(Con);

	CorrectAnswer = 1;

	Con = { "또 헬테이커의 이야기를 들려달라고? 재미있군...", "" };
	ConversationList.push_back(Con);

	Con = { "혹시 해설자가 필요하진 않은가?", "" };
	ConversationList.push_back(Con);

	Con = { "허락해준다면 참 고맙겠어.", "Fade" };
	ConversationList.push_back(Con);

	Con = { "어느날 당신은 악마들로 가득찬 하렘을 \n 꿈꾸고 일어났네.", "cutscene0002" };
	ConversationList.push_back(Con);
	Con = { "하지만 결코 이루기 쉽지 않은 꿈이지. \n 어쩌면 네 목숨을 앗아갈지도 모르고.", "cutscene0003" };
	ConversationList.push_back(Con);
	Con = { "악마 하렘이 달렸다면, 그 어떤 대가도 싸지.\n 그리하여 당신은 지옥으로 모험을 떠났네.", "cutscene0004" };

	Con.EndOn();
	ConversationList.push_back(Con);



	Con = { "나도 수 없이 시도 해봤지만 아직 제대로 성공한 적이 없지.", "" };
	Con.EndOn();
	ConversationList.push_back(Con);

	BadEndConversation = { "판데모니카는 당신의 얼굴을 손아귀로 가져가더니 \n 전문가다운 부드러운 동작으로 목을 꺾어 버렸다." };

	

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

	// 배경화면이 움직이면서 화면밖을 벗어나면 처음으로 돌아옴
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

	//배경화면 한쪽이 꺼지만 같이 꺼준다.
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

void DialogTitle::SuccessStart()
{
	Conversation Con = ConversationList[CurConversationIndex];

	// npc스탠딩 이미지 변경
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
		else if (Con.IsAnswer == false)
		{
			//첫 시작화면에서 넘어갈때 이름을 킨다.
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
	IntroRenderer->AddRenderScale(Scale * _Delta * 0.03f);

	if (400.0f <= Time)
	{
		IntroRenderer->Off();
		MainTextRenderer->On();
		MainNPCRenderer->On();
		MainBGRenderer->On();
		ChangeState(DialogState::Conversation);
	}
}



