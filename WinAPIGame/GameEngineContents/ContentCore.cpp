#include "ContentCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>

ContentCore::ContentCore()
{
}

ContentCore::~ContentCore()
{
}

void ContentCore::Start()
{
	GameEngineWindow::MainWindow.SetPosAndScale({ 100, 100 }, { 1920, 1080 });

	//GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel1");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel2");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel3");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel4");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel5");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel6");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel7");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel8");
	GameEngineCore::CreateLevel<EndingLevel>("EndingLevel");

	// �� ������ ȭ�鿡 ������.
	GameEngineCore::ChangeLevel("PlayLevel4");
}

// �ൿ�Ѱ�.
void ContentCore::Update(float _Delta)
{
}

// �׷�����.
void ContentCore::Render(float _Delta)
{
}

// �����ȴ�.
void ContentCore::Release()
{
}