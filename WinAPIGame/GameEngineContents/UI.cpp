#include "UI.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
UI::UI() 
{
}

UI::~UI()
{
}

void UI::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("mainUI001.png"))
	{

		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\playUI\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mainUI001.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("mainUI002.png"));
	}
	UIRendererLT = CreateRenderer(RenderOrder::UI);
	UIRendererLB = CreateRenderer(RenderOrder::UI);
	UIRendererRT = CreateRenderer(RenderOrder::UI);
	UIRendererRB = CreateRenderer(RenderOrder::UI);

	float4 windowScale = GameEngineWindow::MainWindow.GetBackBuffer()->GetScale();

	UIRendererLT->SetTexture("mainUI002.png");
	float4 Scale = UIRendererLT->GetRenderScale().Half();
	UIRendererLT->SetRenderPos(Scale);

	UIRendererRT->SetTexture("mainUI002.png");
	Scale = UIRendererRT->GetRenderScale().Half();

	UIRendererRT->SetRenderPos({ windowScale.X - Scale .X, Scale.Y});
	UIRendererRT->FlipON();

	UIRendererLB->SetTexture("mainUI001.png");
	Scale = UIRendererLB->GetRenderScale().Half();

	UIRendererLB->SetRenderPos({ Scale.X,windowScale.Y - Scale.Y });


	UIRendererRB->SetTexture("mainUI001.png");
	Scale = UIRendererRB->GetRenderScale().Half();

	UIRendererRB->SetRenderPos({ windowScale.X - Scale.X,  windowScale.Y - Scale.Y });
	UIRendererRB->FlipON();

	GameEngineRenderer* Ptr = CreateRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 145, 770 });
	Ptr->SetRenderScale({ 200, 40 });
	Ptr->SetText("26", 120, "양재참숯체B");
	UIRendererHP = Ptr;

	

	Ptr = CreateRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 580, 985 });
	Ptr->SetRenderScale({ 200, 40 });
	Ptr->SetText("●  인생조언[L키]  ●", 35, "양재참숯체B");

	Ptr = CreateRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 1030, 985 });
	Ptr->SetRenderScale({ 200, 40 });
	Ptr->SetText("●  재시작[R키]  ●", 35, "양재참숯체B");


}

void UI::Init(int _Stage)
{
	GameEngineRenderer* Ptr = CreateRenderer(RenderOrder::UI);
	Ptr->SetRenderPos({ 1695, 770 });
	Ptr->SetRenderScale({ 200, 40 });
	
	std::string str = "Ⅰ" ;
	str[1] += -1 + _Stage;
	Ptr->SetText(str, 120, "양재참숯체B");

}

void UI::Update(float _Delta)
{
	Player* playerptr = Player::GetMainPlayer();
	int HP = playerptr->GetHP();
	
	UIRendererHP->SetText(std::to_string(HP), 120, "양재참숯체B");
}
