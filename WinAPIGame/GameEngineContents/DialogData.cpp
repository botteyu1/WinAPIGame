#include "Dialog.h"
#include <GameEngineCore/GameEngineRenderer.h>

void Dialog::SetDialogData(int _StageLevel)
{
	Conversation Con;
	switch (_StageLevel)
	{
	case 1:
		NameTextRenderer->SetText("�� �ǰ��� �Ǹ� �ǵ����ī ��", 45, "��������üB", RGB(230, 77, 81));

		
		Con = { "�츮 ���� ���� �� �� �ְ���.", "" };
		AnswerList.push_back(Con);
		Con = { "�۽�, ���� �� ������߰ڴµ�?", "" };
		AnswerList.push_back(Con);
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

	
		Con = { "����. ���� ����.", "" };
		AnswerList.push_back(Con);
		Con = { "�ð� ����. ���ھֵ� ������ �ٺ�.", "" };
		AnswerList.push_back(Con);

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

		
		Con = { "����. ���� ����.", "" };
		AnswerList.push_back(Con);
		Con = { "�ʹ� ������ �ǽ��� ���µ�..", "" };
		AnswerList.push_back(Con);
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

		
		Con = { "�ʶ� ���� ��� ������.", "" };
		AnswerList.push_back(Con);
		Con = { "��� ������. �� �ŵ��� ��.", "" };
		AnswerList.push_back(Con);

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

		//AnswerTextRenderer1->SetText("���. ���߿� ��ȸ�� �� ���� ����ε�.", 30, "��������üB", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("��� �Ϸ����� �� ����ġ����. ���� ���� �����̳� �� �ž�.", 30, "��������üB", RGB(255, 255, 255));
		Con = { "���. ���߿� ��ȸ�� �� ���� ����ε�.", "" };
		AnswerList.push_back(Con);
		Con = { "��� �Ϸ����� �� ����ġ����. ���� ���� �����̳� �� �ž�.", "" };
		AnswerList.push_back(Con);
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

		//AnswerTextRenderer1->SetText("�Ǹ��� ã�� �־�.", 30, "��������üB", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("õ�縦 ã�� �־�.", 30, "��������üB", RGB(255, 255, 255));
		Con = { "�Ǹ��� ã�� �־�.", "" };
		AnswerList.push_back(Con);
		Con = { "õ�縦 ã�� �־�.", "" };
		AnswerList.push_back(Con);
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

		//AnswerTextRenderer1->SetText("Ǫ���� �� �� ����. �Ϸ��� ���÷�?", 30, "��������üB", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("�޴����� �׳� �ǳʶپ���. �Ϸ��� ���÷�?", 30, "��������üB", RGB(255, 255, 255));
		Con = { "Ǫ���� �� �� ����. �Ϸ��� ���÷�?", "" };
		AnswerList.push_back(Con);
		Con = { "�޴����� �׳� �ǳʶپ���. �Ϸ��� ���÷�?", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 1;

		Con = { "�� ���� �����. �� ��Ƽ�� �� ����.", "jus_idle" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "��� ��. �� ������ �����ٰ�.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "����� ���̿� �ڷ� ����� ���� Į�� ������ ����� �þߴ� �������." };
	
		break;

		case 8:
		NameTextRenderer->SetText("�� ������ CEO ����� ��", 45, "��������üB", RGB(230, 77, 81));
		
		Con = { "������ ������. �� �÷õ��� ����ϸ� ��ġ�� �����߾�.", "LH_swirl" };
		ConversationList.push_back(Con);

		//����
		Con = { "��ȥ�� ��ġ�� �Ƴ��� ������ ��� �ָ�.", "LH_idle" };
		Con.AnswerOn();
		Con.SetLeft(4);
		Con.SetRight(2);
		ConversationList.push_back(Con);

		//AnswerTextRenderer1->SetText("��, ���մ�!", 30, "��������üB", RGB(255, 255, 255));
		//AnswerTextRenderer2->SetText("����Ұ�. �� �Ϸ��� ���Ͷ�.", 30, "��������üB", RGB(255, 255, 255));

		//�亯1 
		Con = { "��, ���մ�!", "" };
		AnswerList.push_back(Con);
		Con = { "����Ұ�. �� �Ϸ��� ���Ͷ�.", "" };
		AnswerList.push_back(Con);
		CorrectAnswer = 2;


		Con = { "�����ϰ� � ��ȥ�̷ΰ�...", "" };
		ConversationList.push_back(Con);

		Con = { "����� ������ ���� ����۴� ����� �̸��� ���� �����. ����� ������ �״�� ��Ƴ��ȴ�.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		//����2
		Con = { "�� �Ϸ��� ����? �Ǹ��� ������ų �� ���� �Ŷ�� ������?", "LH_angry" };
		Con.AnswerOn();
		Con.SetLeft(6);
		Con.SetRight(5);
		ConversationList.push_back(Con);

		//�亯2
		Con = { "���δ��̶�� �ҷ���. �׸��� ���� ������ ���� ����� ���ض�.", "" };
		AnswerList.push_back(Con);
		Con = { "Ŀ��, ���� ���� ���Ӱ� ���ݷ� ������ũ�� ������ �� ����.", "" };
		AnswerList.push_back(Con);


		Con = { "�� ������ ������ ��߰ڱ���.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		Con = { "����? �װ� �پ�? ������� �� ����, �� ���� ������ũ�� �����?", "" };
		ConversationList.push_back(Con);

		Con = { "���� ������ũ�� �����ϴ� �� ���� �� �˾ƶ�.", "LH_happy" };
		ConversationList.push_back(Con);

		Con = { "�׷� ����� �� ����. ��¼�� �� �Ϸ��̶�� �� ����� ���� �ְھ�.", "" };
		Con.EndOn();
		ConversationList.push_back(Con);

		BadEndConversation = { "������� ������, ����� �Ǵ� ������ ���ʷ� ���� ���ȴ�. ������ �����ϱ� ����� �����̴�." };
	
		break;
	default:
		//MsgBoxAssert("���̾�α� ������ �Է����� �ʾҰų� �߸��� �������� �����Դϴ�.")
		break;
	}
	
}