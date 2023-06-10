#include "Dialog.h"
#include <GameEngineCore/GameEngineRenderer.h>

void Dialog::SetDialogData(int _StageLevel)
{
	Conversation Con;
	switch (_StageLevel)
	{
	case 1:
		NameTextRenderer->SetText("● 피곤한 악마 판데모니카 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		NameTextRenderer->On();
		AnswerTextRenderer1->SetText("우리 집에 가면 알 수 있겠지.", 35, "양재참숯체B", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("글쎄, 내가 널 도와줘야겠는데?", 35, "양재참숯체B", RGB(255, 255, 255));
		Con = { "지옥 고객센터의 판데모니카라고 합니다. \n    무엇을 도와드릴까요?", "pand_idle",true};
		ConversationList.push_back(Con);
		Con = { "지옥을 살아서 빠져나갈 수 있으리라 생각한 거야? \n 꿈도 크셔라.", "" ,false,true};
		ConversationList.push_back(Con);

		BadEndConversation = { "판데모니카는 당신의 얼굴을 손아귀로 가져가더니 \n 전문가다운 부드러운 동작으로 목을 꺾어 버렸다." };
		SuccessConversation = { "참 달콤한 제안이에요. 커피를 마시고 싶네요.\n    피곤해서 정신을 못 차리겠어요.", "pand_flust"};

		CorrectAnswer = 2;

		break;
	case 2:
		break;
	default:
		//MsgBoxAssert("다이얼로그 정보를 입력하지 않았거나 잘못된 스테이지 레벨입니다.")
		break;
	}
	
}