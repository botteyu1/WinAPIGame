#include "VFX.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TileMap.h"

VFX::VFX() 
{
}

VFX::~VFX()
{
}

void VFX::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("small_VFX1"))
	{

		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\VFX\\");

		ResourcesManager::GetInst().CreateSpriteFolder("small_VFX1", FolderPath.PlusFilePath("small_VFX1"));
		ResourcesManager::GetInst().CreateSpriteFolder("small_VFX2", FolderPath.PlusFilePath("small_VFX2"));
		ResourcesManager::GetInst().CreateSpriteFolder("small_VFX3", FolderPath.PlusFilePath("small_VFX3"));
		ResourcesManager::GetInst().CreateSpriteFolder("hit_vfx1", FolderPath.PlusFilePath("hit_vfx1"));
		ResourcesManager::GetInst().CreateSpriteFolder("hit_vfx2", FolderPath.PlusFilePath("hit_vfx2"));
		ResourcesManager::GetInst().CreateSpriteFolder("blood_vfx1", FolderPath.PlusFilePath("blood_vfx1"));
		ResourcesManager::GetInst().CreateSpriteFolder("blood_vfx2", FolderPath.PlusFilePath("blood_vfx2"));
		ResourcesManager::GetInst().CreateSpriteFolder("blood_vfx3", FolderPath.PlusFilePath("blood_vfx3"));
		ResourcesManager::GetInst().CreateSpriteFolder("huge_vfx", FolderPath.PlusFilePath("huge_vfx"));
		ResourcesManager::GetInst().CreateSpriteFolder("lovePlosion_vfx", FolderPath.PlusFilePath("lovePlosion_vfx"));
		

	}

	SmallRenderer = CreateRenderer(RenderOrder::VFX);
	SmallRenderer->CreateAnimation("small_VFX1", "small_VFX1", 0, 2, 0.14f, false);
	SmallRenderer->CreateAnimation("small_VFX2", "small_VFX2", 0, 2, 0.14f, false);
	SmallRenderer->CreateAnimation("small_VFX3", "small_VFX3", 0, 2, 0.14f, false);
	SmallRenderer->ChangeAnimation("small_VFX2");
	SmallRenderer->AnimationEndOff();
	SmallRenderer->Off();

	HitRenderer = CreateRenderer(RenderOrder::VFX2);
	HitRenderer->CreateAnimation("hit_vfx1", "hit_vfx1", 0, 3, 0.07f, false);
	HitRenderer->CreateAnimation("hit_vfx2", "hit_vfx2", 0, 3, 0.07f, false);
	HitRenderer->ChangeAnimation("hit_vfx2");
	HitRenderer->AnimationEndOff();
	HitRenderer->Off();
	HitRenderer->SetRenderScale({ 200.0f,200.0f });

	BloodRenderer = CreateRenderer(RenderOrder::VFX2);
	BloodRenderer->CreateAnimation("blood_vfx1", "blood_vfx1", 0, 5, 0.07f, false);
	BloodRenderer->CreateAnimation("blood_vfx2", "blood_vfx2", 0, 5, 0.07f, false);
	BloodRenderer->CreateAnimation("blood_vfx3", "blood_vfx3", 0, 5, 0.07f, false);
	BloodRenderer->ChangeAnimation("blood_vfx1");
	BloodRenderer->AnimationEndOff();
	BloodRenderer->Off();

	HugeRenderer = CreateRenderer(RenderOrder::VFX2);
	HugeRenderer->CreateAnimation("huge_vfx", "huge_vfx", 0, 8, 0.07f, false);
	HugeRenderer->ChangeAnimation("huge_vfx");
	HugeRenderer->AnimationEndOff();
	HugeRenderer->Off();
	
	LovePlosionRenderer = CreateRenderer(RenderOrder::VFX2);
	LovePlosionRenderer->CreateAnimation("lovePlosion_vfx", "lovePlosion_vfx", 0, 14, 0.07f, false);
	LovePlosionRenderer->ChangeAnimation("lovePlosion_vfx");
	LovePlosionRenderer->AnimationEndOff();
	LovePlosionRenderer->Off();
	
}

void VFX::Small_VFXOn(float4 _TilePos)
{
	static int VFXCycle = 1;

	SmallRenderer->On();
	float4 Pos = TileMap::GetLevelTileMap()->GetTilePos(_TilePos);
	SmallRenderer->SetRenderPos(Pos + float4 {0.0f,20.0f});

	std::string VFXName = "small_VFX" + std::to_string(VFXCycle);
	SmallRenderer->ChangeAnimation(VFXName);

	VFXCycle++;
	if (VFXCycle > 3)
	{
		VFXCycle = 1;
	}
}

void VFX::Hit_VFXOn(float4 _TilePos)
{
	static int VFXCycle = 1;

	HitRenderer->On();
	float4 Pos = TileMap::GetLevelTileMap()->GetTilePos(_TilePos);
	HitRenderer->SetRenderPos(Pos + float4{ 0.0f,20.0f });

	std::string VFXName = "hit_vfx" + std::to_string(VFXCycle);
	HitRenderer->ChangeAnimation(VFXName);
	VFXCycle++;
	if (VFXCycle > 2)
	{
		VFXCycle = 1;
	}
}

void VFX::Blood_VFXOn(float4 _TilePos)
{
	static int VFXCycle = 1;

	BloodRenderer->On();
	float4 Pos = TileMap::GetLevelTileMap()->GetTilePos(_TilePos);
	BloodRenderer->SetRenderPos(Pos + float4{ 0.0f,40.0f });

	std::string VFXName = "blood_vfx" + std::to_string(VFXCycle);
	BloodRenderer->ChangeAnimation(VFXName);
	VFXCycle++;
	if (VFXCycle > 3)
	{
		VFXCycle = 1;
	}
}

void VFX::Huge_VFXOn(float4 _TilePos)
{
	HugeRenderer->On();
	float4 Pos = TileMap::GetLevelTileMap()->GetTilePos(_TilePos);
	HugeRenderer->SetRenderPos(Pos + float4{ 0.0f,40.0f });
	HugeRenderer->ChangeAnimation("huge_vfx");
}

void VFX::LovePlosion_VFXOn(float4 _TilePos)
{
}


