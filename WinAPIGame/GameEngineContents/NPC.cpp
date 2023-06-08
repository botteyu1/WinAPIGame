#include "NPC.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "VFX.h"
#include "Player.h"
NPC::NPC() 
{
}

NPC::~NPC()
{
}

void NPC::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadSprite("pandemonica"))
	{
		GameEnginePath FolderPath;
		FolderPath.SetCurrentPath();
		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\npc\\");

		ResourcesManager::GetInst().CreateSpriteFolder("pandemonica", FolderPath.PlusFilePath("pandemonica"));
		ResourcesManager::GetInst().CreateSpriteFolder("azazel", FolderPath.PlusFilePath("azazel"));
		ResourcesManager::GetInst().CreateSpriteFolder("cerberus", FolderPath.PlusFilePath("cerberus"));
		ResourcesManager::GetInst().CreateSpriteFolder("justice", FolderPath.PlusFilePath("justice"));
		ResourcesManager::GetInst().CreateSpriteFolder("lucy", FolderPath.PlusFilePath("lucy"));
		ResourcesManager::GetInst().CreateSpriteFolder("lucyh", FolderPath.PlusFilePath("lucyh"));
		ResourcesManager::GetInst().CreateSpriteFolder("malina", FolderPath.PlusFilePath("malina"));
		ResourcesManager::GetInst().CreateSpriteFolder("modeus", FolderPath.PlusFilePath("modeus"));


		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\lovesign\\");

		ResourcesManager::GetInst().TextureLoad(FolderPath.PlusFilePath("lovesign.png"));
	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	LoveSignRenderer = CreateRenderer(RenderOrder::VFX2);
	LoveSignRenderer->SetTexture("lovesign.png");
	ChangeState(ObstacleState::Idle);

	
}

void NPC::Init(float4 _TilePos, int _Custom)
{
	Obstacle::Init(_TilePos, _Custom);
	// 스테이지 별 다른npc 렌더러
	switch (_Custom)
	{
	case 1:
		MainRenderer->CreateAnimation("pandemonica", "pandemonica", 0, 11, 0.07f, true);
		MainRenderer->ChangeAnimation("pandemonica");
		break;
	case 2:
		MainRenderer->CreateAnimation("modeus", "modeus", 0, 11, 0.07f, true);
		MainRenderer->ChangeAnimation("modeus");
		break;
	case 3:
		MainRenderer->CreateAnimation("cerberus", "cerberus", 0, 11, 0.07f, true);
		MainRenderer->ChangeAnimation("cerberus");
		break;

	default:
		break;
	}
}

void NPC::Update(float _Delta)
{
	Obstacle::Update(_Delta);
	static float LoveSignY = -30.0f;

	

	LoveSignY += LoveSignSpeed * _Delta;
	if (LoveSignY > -25.0f)
	{
		LoveSignY = -25.0f;
		LoveSignSpeed = -LoveSignSpeed;
	}
	else if (LoveSignY < -35.0f)
	{
		LoveSignY = -35.0f;
		LoveSignSpeed = -LoveSignSpeed;
	}

	LoveSignRenderer->SetRenderPos({ -50.0f, LoveSignY });
}

void NPC::DeathStart()
{
	if (IsUpdate() == true)
	{
		Player::GetMainPlayer()->GetPlayerVFX()->LovePlosion_VFXOn(GetTilePos());
	}
	
	Off();
	//TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
}

