#include "UI.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
UI::UI() 
{
}

UI::~UI()
{
}

void UI::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("mainUI002.bmp"))
	{

		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\playUI\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mainUI000.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mainUI001.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mainUI002.bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mainUI003.bmp"));
	}
	UIRendererLT = CreateUIRenderer(RenderOrder::UI);
	UIRendererLB = CreateUIRenderer(RenderOrder::UI);
	UIRendererRT = CreateUIRenderer(RenderOrder::UI);
	UIRendererRB = CreateUIRenderer(RenderOrder::UI);

	float4 windowScale = GameEngineWindow::MainWindow.GetBackBuffer()->GetScale();

	UIRendererLT->SetTexture("mainUI002.bmp");
	float4 Scale = UIRendererLT->GetRenderScale().Half();
	UIRendererLT->SetRenderPos(Scale);

	UIRendererRT->SetTexture("mainUI003.bmp");
	Scale = UIRendererRT->GetRenderScale().Half();

	UIRendererRT->SetRenderPos({ windowScale.X - Scale .X, Scale.Y});
	

	UIRendererLB->SetTexture("mainUI001.bmp");
	Scale = UIRendererLB->GetRenderScale().Half();

	UIRendererLB->SetRenderPos({ Scale.X,windowScale.Y - Scale.Y });


	UIRendererRB->SetTexture("mainUI000.bmp");
	Scale = UIRendererRB->GetRenderScale().Half();

	UIRendererRB->SetRenderPos({ windowScale.X - Scale.X,  windowScale.Y - Scale.Y });
	//UIRendererRB->FlipON();

	GameEngineRenderer* Ptr = CreateUIRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 200, 900 });
	
	Ptr->SetText("26", 120, "양재참숯체B");
	UIRendererHP = Ptr;

	

	Ptr = CreateUIRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 720, 1050 });
	
	Ptr->SetText("●  인생조언[L키]  ●", 38, "양재참숯체B");

	Ptr = CreateUIRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 1150, 1050 });
	
	Ptr->SetText("●  재시작[R키]  ●", 38, "양재참숯체B");


}

void UI::Init(int _Stage)
{
	GameEngineRenderer* Ptr = CreateRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 1717, 900 });
	
	std::string str = "Ⅰ" ;
	str[1] += -1 + _Stage;
	Ptr->SetText(str, 150, "양재참숯체B");

}

void UI::Update(float _Delta)
{
	Player* playerptr = Player::GetMainPlayer();
	int HP = playerptr->GetHP();
	
	if (HP == 0)
	{
		UIRendererHP->SetText("X", 120, "양재참숯체B");
	}
	else
	{
		UIRendererHP->SetText(std::to_string(HP), 120, "양재참숯체B");
	}

	
}
