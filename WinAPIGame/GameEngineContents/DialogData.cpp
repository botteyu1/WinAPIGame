#include "Dialog.h"
#include <GameEngineCore/GameEngineRenderer.h>

void Dialog::SetDialogData(int _StageLevel)
{
	Conversation Con;
	switch (_StageLevel)
	{
	case 1:
		NameTextRenderer->SetText("�� �ǰ��� �Ǹ� �ǵ����ī ��", 45, "��������üB", RGB(230, 77, 81));

		AnswerTextRenderer1->SetText("�츮 ���� ���� �� �� �ְ���.", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("�۽�, ���� �� ������߰ڴµ�?", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 2;

		Con = { "���� �������� �ǵ����ī��� �մϴ�. \n    ������ ���͵帱���?", "pand_idle"};
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		Con = { "�� ������ �����̿���. Ŀ�Ǹ� ���ð� �ͳ׿�.\n    �ǰ��ؼ� ������ �� �����ھ��.", "pand_flust"};
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "������ ��Ƽ� �������� �� �������� ������ �ž�? \n �޵� ũ�Ŷ�.", ""};
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "�ǵ����ī�� ����� ���� �վƱͷ� ���������� \n �������ٿ� �ε巯�� �������� ���� ���� ���ȴ�." };
		


		break;
	case 2:
		NameTextRenderer->SetText("�� ������ �Ǹ� �𵥿콺 ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "�ʶ� ����. ���� �ٷ�.", "mod_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		AnswerTextRenderer1->SetText("����. ���� ����.", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("�ð� ����. ���ھֵ� ������ �ٺ�.", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 2;

		Con = { "�Ǹ� �Ϸ�? �ҽ��� ��û��... �Ǹ����� �ʸ� ������ ���� ���� �ٵ�, �װ� ��ĥ �� ����.", "mod_close" };
		Con.EndOn();
		ConversationList.push_back(Con);
		
		Con = { "�ٵ� �׷��� ���ϰ�... ���߿� �������� �ϴ���.", "" };
		ConversationList.push_back(Con);
		
		Con = { "Ȥ�� �𸣴� ������ �ν� ������.", ""  };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "�𵥿콺�� Ŀ�ٶ� ��ġ�� ���´�. ���� ���� �� �� �� ����." };
		

		break;
	case 3:
		NameTextRenderer->SetText("�� �� �ֵ��� �Ǹ� �ɸ����ν� ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "�ΰ��̾�? ��¥ �ΰ��̾�? ���� ������ ��.", "cer_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		AnswerTextRenderer1->SetText("����. ���� ����.", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("�ʹ� ������ �ǽ��� ���µ�..", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 1;

		Con = { "����, ����! �ΰ����� Ÿ����Ű�� ����!", "cer_happy" };
		Con.EndOn();
		ConversationList.push_back(Con);
		
		Con = { "�������� ������ ���ؼ� �ΰ��� �ʿ��ؼ� �׷�. ���� �� ������ �ʿ�� ������.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "�ֵ��̵��� ��ģ ������ ��ſ��� �޷������. �Ϳ��� ������ �Ҹ��� �Բ� ����� ������ �����." };
		

		break;
	case 4:
		NameTextRenderer->SetText("�� ��ū���� �Ǹ� ������ ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "����ϳ�, �� �� �� ���밡�����̾�... \n �ʰ��� ������ ���� ó���ε�, �������� �� �ϰ� �־�?", "mal_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		AnswerTextRenderer1->SetText("�ʶ� ���� ��� ������.", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("��� ������. �� �ŵ��� ��.", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 1;

		Con = { "��... ����? �׷�, �� �� �� ��� �־�. ���� ���� ������ �����ٸ��.", "mal_puzzled" };
		Con.EndOn();
		ConversationList.push_back(Con);

		
		
		Con = { "�Ⱑ ������. ���� ������ �� ����.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "�������� ���� �ֵθ��� �ۻ� �� ��� �񿡼� �ǰ� �м�ó�� ���� ���Դ�." };
	
		break;
	case 5:
		NameTextRenderer->SetText("�� �󽺷��� �Ǹ� ����� ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "��. �Ϸ� �ٸ��ٰ� ����µ�. ���� ����.", "z_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		AnswerTextRenderer1->SetText("���. ���߿� ��ȸ�� �� ���� ����ε�.", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("��� �Ϸ����� �� ����ġ����. ���� ���� �����̳� �� �ž�.", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 1;

		Con = { "�� ������ �׷��� �� �ž�. ���� �׸� ���� ������.", "z_laugh" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "��� ��. �� ������ �����ٰ�.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "����� ���̿� �ڷ� ����� ���� Į�� ������ ����� �þߴ� �������." };
	
		break;
	
	case 6:
		NameTextRenderer->SetText("�� ȣ��� ���� õ�� ������ ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "�ϴ��� ���һ�! ����ִ� �ΰ��� �������� �� �ϰ� �ִ� ����? ��ġ ���� ���̳׿�.", "az_idle" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		AnswerTextRenderer1->SetText("�Ǹ��� ã�� �־�.", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("õ�縦 ã�� �־�.", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 1;

		Con = { "��, ���ʵ���? Ȥ��, ���� �˾� ���� ���ΰ���? �ƴϸ� �Ǹ���? ���� �ϴ� �� ���ھ��.", "az_note" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "���⼱ ã�� ����ſ���. ������ ���� ���� ���� �˰� ����. \n ��, ���� ��������.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "������ ������ õ���� ������� ���� �����̳� ������." };
		break;
	case 7:
		NameTextRenderer->SetText("�� �����ִ� �Ǹ� ����Ƽ�� ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "��, �� ������ Ǯ����? �����ִµ�!", "jus_curious" };
		Con.AnswerOn();
		Con.SetLeft(1);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		AnswerTextRenderer1->SetText("Ǫ���� �� �� ����. �Ϸ��� ���÷�?", 30, "��������üB", RGB(255, 255, 255));
		AnswerTextRenderer2->SetText("�޴����� �׳� �ǳʶپ���. �Ϸ��� ���÷�?", 30, "��������üB", RGB(255, 255, 255));
		CorrectAnswer = 1;

		Con = { "�� ���� �����. �� ��Ƽ�� �� ����.", "jus_idle" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "��� ��. �� ������ �����ٰ�.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "����� ���̿� �ڷ� ����� ���� Į�� ������ ����� �þߴ� �������." };
	
		break;
	default:
		//MsgBoxAssert("���̾�α� ������ �Է����� �ʾҰų� �߸��� �������� �����Դϴ�.")
		break;
	}
	
}