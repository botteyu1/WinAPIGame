#include "Dialog.h"
#include <GameEngineCore/GameEngineRenderer.h>

void Dialog::SetDialogData(int _StageLevel)
{
	Conversation Con;
	switch (_StageLevel)
	{
	case 1:
		NameTextRenderer->SetText("● 피곤한 악마 판데모니카 ●", 45, "양재참숯체B", RGB(230, 77, 81));

		
		Con = { "우리 집에 가면 알 수 있겠지.", "" };
		AnswerList.push_back(Con);
		Con = { "글쎄, 내가 널 도와줘야겠는데?", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 2;

		Con = { "지옥 고객센터의 판데모니카라고 합니다. \n    무엇을 도와드릴까요?", "pand_idle"};
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		Con = { "참 달콤한 제안이에요. 커피를 마시고 싶네요.\n    피곤해서 정신을 못 차리겠어요.", "pand_flust"};
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "지옥을 살아서 빠져나갈 수 있으리라 생각한 거야? \n 꿈도 크셔라.", ""};
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "판데모니카는 당신의 얼굴을 손아귀로 가져가더니 \n 전문가다운 부드러운 동작으로 목을 꺾어 버렸다." };
		


		break;
	case 2:
		NameTextRenderer->SetText("● 음란한 악마 모데우스 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		
		Con = { "너랑 나랑. 지금 바로.", "mod_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

	
		Con = { "좋아. 이의 없어.", "" };
		AnswerList.push_back(Con);
		Con = { "시간 없어. 여자애들 모으기 바빠.", "" };
		AnswerList.push_back(Con);

		CorrectAnswer = 2;

		Con = { "악마 하렘? 불쌍한 멍청이... 악마들이 너를 갈가리 찢어 버릴 텐데, 그걸 놓칠 수 없지.", "mod_close" };
		Con.EndOn();
		ConversationList.push_back(Con);
		
		Con = { "다들 그렇게 말하곤... 나중에 도망가려 하더라.", "" };
		ConversationList.push_back(Con);
		
		Con = { "혹시 모르니 무릎을 부숴 놔야지.", ""  };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "모데우스는 커다란 망치를 꺼냈다. 좋은 꼴은 못 볼 것 같다." };
		

		break;
	case 3:
		NameTextRenderer->SetText("● 세 쌍둥이 악마 케르베로스 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		
		Con = { "인간이야? 진짜 인간이야? 같이 데려가 줘.", "cer_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		
		Con = { "좋아. 이의 없어.", "" };
		AnswerList.push_back(Con);
		Con = { "너무 쉬워서 의심이 가는데..", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 1;

		Con = { "좋아, 드디어! 인간들을 타락시키러 가자!", "cer_happy" };
		Con.EndOn();
		ConversationList.push_back(Con);
		
		Con = { "지옥문을 지나기 위해선 인간이 필요해서 그래. 굳이 한 조각일 필요는 없지만.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "쌍둥이들이 미친 개마냥 당신에게 달려들었다. 귀여운 강아지 소리와 함께 당신의 심장은 멈췄다." };
		

		break;
	case 4:
		NameTextRenderer->SetText("● 시큰둥한 악마 말리나 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		
		Con = { "대단하네, 또 골 빈 빡대가리들이야... \n 너같이 못생긴 놈은 처음인데, 지옥에서 뭘 하고 있어?", "mal_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		
		Con = { "너랑 같이 놀고 싶은데.", "" };
		AnswerList.push_back(Con);
		Con = { "기분 좋은데. 더 매도해 줘.", "" };
		AnswerList.push_back(Con);

		CorrectAnswer = 1;

		Con = { "뭐... 게임? 그래, 안 될 게 어디 있어. 턴제 전략 게임이 괜찮다면야.", "mal_puzzled" };
		Con.EndOn();
		ConversationList.push_back(Con);

		
		
		Con = { "기가 막히네. 마조 새끼나 또 보고.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "말리나가 팔을 휘두르자 작살 난 당신 목에서 피가 분수처럼 터져 나왔다." };
	
		break;
	case 5:
		NameTextRenderer->SetText("● 상스러운 악마 즈드라다 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		
		Con = { "야. 하렘 꾸린다고 들었는데. 나도 낄래.", "z_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		//AnswerTextRenderer1->SetText("잠깐만. 나중에 후회할 것 같은 기분인데.", 30, "양재참숯체B", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("사실 하렘같은 거 때려치웠어. 턴제 전략 게임이나 할 거야.", 30, "양재참숯체B", RGB(255, 255, 255));
		Con = { "잠깐만. 나중에 후회할 것 같은 기분인데.", "" };
		AnswerList.push_back(Con);
		Con = { "사실 하렘같은 거 때려치웠어. 턴제 전략 게임이나 할 거야.", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 1;

		Con = { "안 됐지만 그래도 낄 거야. 막을 테면 막아 보던가.", "z_laugh" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "어우 씨. 그 고통을 끝내줄게.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "갈비뼈 사이에 자루 깊숙이 박힌 칼을 끝으로 당신의 시야는 흐려졌다." };
	
		break;
	
	case 6:
		NameTextRenderer->SetText("● 호기심 많은 천사 아자젤 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		


		Con = { "하느님 맙소사! 살아있는 인간이 지옥에서 뭘 하고 있는 거죠? 흔치 않은 일이네요.", "az_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		//AnswerTextRenderer1->SetText("악마를 찾고 있어.", 30, "양재참숯체B", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("천사를 찾고 있어.", 30, "양재참숯체B", RGB(255, 255, 255));
		Con = { "악마를 찾고 있어.", "" };
		AnswerList.push_back(Con);
		Con = { "천사를 찾고 있어.", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 1;

		Con = { "아, 그쪽도요? 혹시, 현대 죄악 관련 논문인가요? 아니면 악마학? 같이 하는 게 좋겠어요.", "az_note" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "여기선 찾기 힘들거예요. 다행히 제가 좋은 곳을 알고 있죠. \n 자, 손을 잡으세요.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "거짓말 때문에 천국에 가리라고 누가 예상이나 했을까." };
		break;
	case 7:
		NameTextRenderer->SetText("● 끝내주는 악마 저스티스 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		
		Con = { "야, 저 퍼즐을 풀었어? 끝내주는데!", "jus_curious" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		//AnswerTextRenderer1->SetText("푸느라 손 좀 갔지. 하렘에 들어올래?", 30, "양재참숯체B", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("메뉴에서 그냥 건너뛰었어. 하렘에 들어올래?", 30, "양재참숯체B", RGB(255, 255, 255));
		Con = { "푸느라 손 좀 갔지. 하렘에 들어올래?", "" };
		AnswerList.push_back(Con);
		Con = { "메뉴에서 그냥 건너뛰었어. 하렘에 들어올래?", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 1;

		Con = { "뭘 굳이 물어봐. 난 파티엔 안 빠져.", "jus_idle" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "어우 씨. 그 고통을 끝내줄게.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "갈비뼈 사이에 자루 깊숙이 박힌 칼을 끝으로 당신의 시야는 흐려졌다." };
	
		break;

		case 8:
		NameTextRenderer->SetText("● 지옥의 CEO 루시퍼 ●", 45, "양재참숯체B", RGB(230, 77, 81));
		
		Con = { "이제야 만나네. 넌 시련들을 통과하며 가치를 증명했어.", "LH_swirl" };
		ConversationList.push_back(Con);

		//문제
		Con = { "영혼을 바치면 아끼는 종으로 삼아 주마.", "LH_idle" };
		Con.AnswerOn();
		Con.SetLeft(4);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		//AnswerTextRenderer1->SetText("네, 여왕님!", 30, "양재참숯체B", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("사양할게. 내 하렘에 들어와라.", 30, "양재참숯체B", RGB(255, 255, 255));

		//답변1 
		Con = { "네, 여왕님!", "" };
		AnswerList.push_back(Con);
		Con = { "사양할게. 내 하렘에 들어와라.", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 2;


		Con = { "절절하고 어린 영혼이로고...", "" };
		ConversationList.push_back(Con);

		Con = { "당신이 무릎을 꿇자 루시퍼는 당신의 이마에 입을 맞췄다. 당신의 생명은 그대로 녹아내렸다.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		//문제2
		Con = { "뭘 하려는 거지? 악마를 굴복시킬 수 있을 거라고 생각해?", "LH_angry" };
		Con.AnswerOn();
		Con.SetLeft(6);
		Con.SetRight(5);
		ConversationList.push_back(Con);

		//답변2
		Con = { "주인님이라고 불러라. 그리고 말을 꺼내기 전에 허락을 구해라.", "" };
		AnswerList.push_back(Con);
		Con = { "커피, 턴제 전략 게임과 초콜렛 팬케이크를 제공할 수 있지.", "" };
		AnswerList.push_back(Con);


		Con = { "네 주제를 가르쳐 줘야겠구나.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "정말? 그게 다야? 여기까지 와 놓고선, 날 고작 팬케이크로 사려고?", "" };
		ConversationList.push_back(Con);

		Con = { "내가 펜케이크를 좋아하니 운 좋은 줄 알아라.", "LH_happy" };
		ConversationList.push_back(Con);

		Con = { "그럼 설득된 것 같네. 어쩌면 네 하렘이라는 게 재밌을 수도 있겠어.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "루시퍼의 손짓에, 당신의 피는 모조리 식초로 변해 버렸다. 참으로 형언하기 어려운 느낌이다." };
	
		break;
	default:
		//MsgBoxAssert("다이얼로그 정보를 입력하지 않았거나 잘못된 스테이지 레벨입니다.")
		break;
	}
	
}