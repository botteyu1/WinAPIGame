#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineCore/GameEngineCore.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �ʸ����
	// ���� �����
	// ����

	// �ڱ� ���Ǵ�� ����ڴٴ� ���̰� xxxxx
	// Player* NewPlayer = new Player();

	CreateActor<Player>();
}


void PlayLevel::Update(float _Delta)
{
}
void PlayLevel::Render()
{
}
void PlayLevel::Release()
{
}