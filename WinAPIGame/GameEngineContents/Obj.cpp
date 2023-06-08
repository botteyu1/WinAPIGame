#include "Obj.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>

Obj::Obj() 
{
}

Obj::~Obj()
{
}

void Obj::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("fire"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\fire");

		ResourcesManager::GetInst().CreateSpriteFolder("fire", FolderPath.PlusFilePath("fire"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("FLAMEbase0001.png"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("FLAMEbase0002.png"));
	}
}

void Obj::Init(float4 _Pos, int _FireOn)
{
	if (_FireOn == 0)
	{
		GameEngineRenderer* ptr = CreateRenderer(RenderOrder::BackGroundObject);
		ptr->SetTexture("FLAMEbase0002.png");
		

		float4 Scale = ptr->GetRenderScale().Half();
		ptr->SetRenderPos(_Pos + Scale);
	}
	else
	{
		GameEngineRenderer* ptr;
		float4 Scale;
		ptr = CreateRenderer(RenderOrder::BackGroundObject);
		ptr->SetTexture("FLAMEbase0001.png");

		Scale = ptr->GetRenderScale().Half();
		ptr->SetRenderPos(_Pos + Scale);

		ptr = CreateRenderer(RenderOrder::BackGroundObject2);

		ptr->CreateAnimation("fire", "fire", 0, 11, 0.07f, true);
		ptr->ChangeAnimation("fire"); 
		ptr->SetRenderScale({ 68.0f,68.0f });
		Scale = ptr->GetRenderScale().Half();
		ptr->SetRenderPos(_Pos + Scale + float4{7.0f,-35.0f});
	}

}

