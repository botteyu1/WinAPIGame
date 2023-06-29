#include "VFX.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineRandom.h>
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
		
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0001.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0002.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0003.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0004.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0005.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0006.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0007.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0001_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0002_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0003_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0004_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0005_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0006_mask.bmp"));
		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("bone\\bone0007_mask.bmp"));
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

	vecBoneRenderer.reserve(16);


	BoneRenderer Renderer;
	Renderer.Renderer = CreateRenderer("bone0001.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0001_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0001.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0001_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0002.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0002_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0002.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0002_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0003.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0003_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0003.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0003_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0003.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0003_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0003.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0003_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0004.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0004_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0004.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0004_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0005.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0005_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0005.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0005_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0006.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0006_mask.bmp");
	vecBoneRenderer.push_back(Renderer);
	Renderer.Renderer = CreateRenderer("bone0007.bmp", RenderOrder::VFX3);
	Renderer.Renderer->SetMaskTexture("bone0007_mask.bmp");
	vecBoneRenderer.push_back(Renderer);

	for (size_t i = 0; i < vecBoneRenderer.size(); i++)
	{
		vecBoneRenderer[i].Renderer->Off();
	}
	
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
	LovePlosionRenderer->On();
	float4 Pos = TileMap::GetLevelTileMap()->GetTilePos(_TilePos);
	LovePlosionRenderer->SetRenderPos(Pos + float4{ 0.0f,40.0f });
	LovePlosionRenderer->ChangeAnimation("lovePlosion_vfx");
}

void VFX::UndeadDie_VFXOn(float4 _TilePos)
{
	for (size_t i = 0; i < vecBoneRenderer.size(); i++)
	{
		vecBoneRenderer[i].Renderer->On();
		float4 Pos = TileMap::GetLevelTileMap()->GetTilePos(_TilePos);
		vecBoneRenderer[i].Renderer->SetRenderPos(Pos);
		vecBoneRenderer[i].Renderer->SetAngle(GameEngineRandom::MainRandom.RandomFloat(0.0f, 360.0f));
		float Y= GameEngineRandom::MainRandom.RandomFloat(-2500.0f, -1000.0f);
		float X = GameEngineRandom::MainRandom.RandomFloat(-700.0f, 700.0f);
		
		vecBoneRenderer[i].vec = float4{X , Y };

		
	}
	
	// 랜덤 받아야하는 것 위쪽 힘 오른쪽 힘, 시작 각도
	//
	// 뼈 bmp 처리 
	//위치는 타일포스 위치
	

}

void VFX::Update(float _Delta)
{	
	for (size_t i = 0; i < vecBoneRenderer.size(); i++)
	{
		vecBoneRenderer[i].vec += {0.0f, 6000.0f * _Delta};
		vecBoneRenderer[i].Renderer->AddRenderPos(vecBoneRenderer[i].vec * _Delta);
		vecBoneRenderer[i].Renderer->AddAngle(60.0f * _Delta);
	}

	// 중력작용으로 힘이 밑으로 받음 
	// 화면벗어나면 off

	// 델타에 맞게 각도 돌림 시계방향
}


	// x축이동이 점점 줄어듬 xxx
