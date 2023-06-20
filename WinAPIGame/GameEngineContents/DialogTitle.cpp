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
	NameTextRenderer->SetText("● 위대한 파리 베엘제붑 ●", 45, "양재참숯체B", RGB(230, 77, 81));

	
	MainBGRenderer->SetTexture("dialogueBG_abyss.bmp");

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

	//AnswerTextRenderer1->SetText("새 게임", 30, "양재참숯체B", RGB(255, 255, 255));
	//AnswerTextRenderer2->SetText("나가기", 30, "양재참숯체B", RGB(255, 255, 255));
	CorrectAnswer = 1;

	Con = { "또 헬테이커의 이야기를 들려달라고? 재미있군...", "" };
	ConversationList.push_back(Con);

	Con = { "혹시 해설자가 필요하진 않은가?", "" };
	ConversationList.push_back(Con);

	Con = { "허락해준다면 참 고맙겠어.", "Fade" };
	ConversationList.push_back(Con);

	Con = { "어느날 당신은 악마들로 가득찬 하렘을 \n 꿈꾸고 일어났네.", "cutscene_0002_Group-2" };
	ConversationList.push_back(Con);
	Con = { "하지만 결코 이루기 쉽지 않은 꿈이지. \n 어쩌면 네 목숨을 앗아갈지도 모르고.", "cutscene_0003_Group-3-copy-2" };
	ConversationList.push_back(Con);
	Con = { "악마 하렘이 달렸다면, 그 어떤 대가도 싸지.\n 그리하여 당신은 지옥으로 모험을 떠났네.", "cutscene_0004_Layer-273-copy" };

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

	// npc스탠딩 이미지 변경
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
	// 눌렀을때 부퍼 애니메이션이 끝나면 기본 애니메이션으로 변경
	//if (BooperTabRenderer->IsUpdate() == false and BooperRenderer->IsUpdate() == false)
	//{
	//	BooperRenderer->ChangeAnimation("booper");
	//	BooperRenderer->On();
	//}
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



