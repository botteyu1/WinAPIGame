#include "Rock.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Player.h"
#include "TileMap.h"

Rock::Rock() 
{
}

Rock::~Rock()
{
}


void Rock::Start()
{
	static int RockNum = 1;
	if (false == ResourcesManager::GetInst().IsLoadTexture("Rock001.png"))
	{

		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\obstacle\\rock\\");

		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock001.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock002.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock003.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock004.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock005.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock006.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock007.png"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Rock008.png"));
	}
	MainRenderer = CreateRenderer(RenderOrder::Obstacle);
	std::string RockName = "Rock00" + std::to_string(RockNum) + ".png";
	MainRenderer->SetTexture(RockName);

	RockNum++;
	if (RockNum > 8)
	{
		RockNum = 1;
	}
	ChangeState(ObstacleState::Idle);
	//����Ʈ �߰�
	GameEngineLevel* Level = GetLevel();
	RockVFX = Level->CreateActor<VFX>();

}


void Rock::TryMove(float4 _Dir)
{
	Dir = _Dir;
	float4 nextTilePos = GetTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(nextTilePos.iX(), nextTilePos.iY());
	switch (NextTile)
	{
	case TTYPE::NO:
		ChangeState(ObstacleState::Move);
		break;
	case TTYPE::WA:
	case TTYPE::PL:
	case TTYPE::NP:
	case TTYPE::UN:
	case TTYPE::RO:
	case TTYPE::LO:
	
		break;
	case TTYPE::EN:
		break;
	default:
		break;
	}
}


void Rock::MoveStart()
{
	PixelCount = 0.0f;

	//����Ʈ Ȱ��ȭ
	RockVFX->Small_VFXOn(GetTilePos());

	//����  Ÿ�� ��ġ ��� �ٽ� �ٲٱ�
	float4 nextTilePos = GetTilePos();
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, nextTilePos);

	//�̵��� Ÿ�� ��ġ �ٲٱ�
	nextTilePos += Dir;
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::RO, this, nextTilePos);

	// ��ġ ������Ʈ
	TilePos = nextTilePos;
}


void Rock::MoveUpdate(float _Delta)
{
	//�ִϸ��̼ǿ� �°� 100�ȼ� �̵�

	//�����ϳ� ���� 100�ȼ� ����ؼ� �̵��� �Ϸ��ϸ� ���̵�� ��ȣ��
	float Speed = 1000.0f * _Delta;

	//���� �� �ȼ��� ����� Ÿ�ϻ�����ο� �°�  ������ �׿��°� ���ǵ嵵 ������.
	PixelCount += Speed;
	if (PixelCount >= TILESIZE)
	{
		Speed -= (PixelCount - TILESIZE);
	}

	float4 MovePos = Dir * Speed;

	AddPos(MovePos);

	if (PixelCount >= TILESIZE)
	{
		ChangeState(ObstacleState::Idle);
	}

}
