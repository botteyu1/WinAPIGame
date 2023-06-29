#include "NPC.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include "TileMap.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "VFX.h"
#include "Player.h"
#include <GameEnginePlatform/GameEngineSound.h>
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
		ResourcesManager::GetInst().CreateSpriteFolder("zdrada", FolderPath.PlusFilePath("zdrada"));


		FolderPath.MoveParentToExistsChild("ContentsResources");
		FolderPath.MoveChild("ContentsResources\\Texture\\npc\\lovesign\\");

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
		if (nullptr == MainRenderer->FindAnimation("pandemonica"))
		{
			MainRenderer->CreateAnimation("pandemonica", "pandemonica", 0, 11, 0.06f, true);
		}
		MainRenderer->ChangeAnimation("pandemonica");
		break;
	case 2:
		if (nullptr == MainRenderer->FindAnimation("modeus")) {
		MainRenderer->CreateAnimation("modeus", "modeus", 0, 11, 0.06f, true);

		}
		MainRenderer->ChangeAnimation("modeus");
		break;
	case 3:
		if (nullptr == MainRenderer->FindAnimation("cerberus"))
		{
			MainRenderer->CreateAnimation("cerberus", "cerberus", 0, 11, 0.06f, true);
		}
		MainRenderer->ChangeAnimation("cerberus");
		break;
	case 4:
		if (nullptr == MainRenderer->FindAnimation("malina"))
		{
			MainRenderer->CreateAnimation("malina", "malina", 0, 11, 0.06f, true);
		}
		MainRenderer->ChangeAnimation("malina");
		break;
	case 5:
		if (nullptr == MainRenderer->FindAnimation("zdrada"))
		{
			MainRenderer->CreateAnimation("zdrada", "zdrada", 0, 11, 0.06f, true);
		}
		MainRenderer->ChangeAnimation("zdrada");
		break;
	case 6:
		if (nullptr == MainRenderer->FindAnimation("azazel"))
		{
			MainRenderer->CreateAnimation("azazel", "azazel", 0, 11, 0.06f, true);
		}
		MainRenderer->ChangeAnimation("azazel");
		break;
	case 7:
		if (nullptr == MainRenderer->FindAnimation("justice"))
		{
			MainRenderer->CreateAnimation("justice", "justice", 0, 11, 0.07f, true);
		}

		MainRenderer->ChangeAnimation("justice");
		break;
	case 8:
		if (nullptr == MainRenderer->FindAnimation("lucy"))
		{
			MainRenderer->CreateAnimation("lucy", "lucy", 0, 11, 0.07f, true);
		}
		MainRenderer->ChangeAnimation("lucy");
		SetPos(TileMap::GetLevelTileMap()->GetTilePos(_TilePos.iX(), _TilePos.iY() - 1));
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
	GameEngineSound::SoundPlay("succub_capture_01.wav");
	
	Off();
	//TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, TilePos);
}

