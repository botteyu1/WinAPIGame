#include "Dialog.h"
#include <GameEngineCore/GameEngineRenderer.h>

void Dialog::SetDialogData(int _StageLevel)
{
	Conversation Con;
	switch (_StageLevel)
	{
	case 1:
		NameTextRenderer->SetText("�� �ǰ��� �Ǹ� �ǵ����ī ��", 45, "��������üB", RGB(230, 77, 81));
		NameTextRenderer->On();
		AnswerTextRenderer1->SetText("�츮 ���� ���� �� �� �ְ���.", 35, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("�۽�, ���� �� ������߰ڴµ�?", 35, "��������üB", RGB(255, 255, 255));
		Con = { "���� �������� �ǵ����ī��� �մϴ�. \n    ������ ���͵帱���?", "pand_idle",true};
		ConversationList.push_back(Con);
		Con = { "������ ��Ƽ� �������� �� �������� ������ �ž�? \n �޵� ũ�Ŷ�.", "" ,false,true};
		ConversationList.push_back(Con);

		BadEndConversation = { "�ǵ����ī�� ����� ���� �վƱͷ� ���������� \n �������ٿ� �ε巯�� �������� ���� ���� ���ȴ�." };
		SuccessConversation = { "�� ������ �����̿���. Ŀ�Ǹ� ���ð� �ͳ׿�.\n    �ǰ��ؼ� ������ �� �����ھ��.", "pand_flust"};

		CorrectAnswer = 2;

		break;
	case 2:
		break;
	default:
		//MsgBoxAssert("���̾�α� ������ �Է����� �ʾҰų� �߸��� �������� �����Դϴ�.")
		break;
	}
	
}