#include "Rock.h"
#include "ContentsEnum.h"
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/ResourcesManager.h>
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
		FilePath.MoveChild("ContentsResources\\Texture\\rock\\");

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
	ChanageState(ObstacleState::Idle);
}


void Rock::TryMove(float4 _Dir)
{
	Dir = _Dir;
	float4 nextTilePos = GetTilePos() + Dir;
	TTYPE NextTile = TileMap::GetLevelTileMap()->GetTileType(nextTilePos.iX(), nextTilePos.iY());
	switch (NextTile)
	{
	case TTYPE::NO:
		ChanageState(ObstacleState::Move);
		break;
	case TTYPE::WA:
	case TTYPE::PL:
	case TTYPE::NP:
	case TTYPE::UN:
	case TTYPE::RO:
	case TTYPE::LO:
	case TTYPE::KE:
		break;
	case TTYPE::SP:
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

	//기존  타일 위치 길로 다시 바꾸기
	float4 nextTilePos = GetTilePos();
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::NO, nullptr, nextTilePos);

	//이동할 타일 위치 바꾸기
	nextTilePos += Dir;
	TileMap::GetLevelTileMap()->SetTilePair(TTYPE::RO, this, nextTilePos);

	// 위치 업데이트
	TilePos = nextTilePos;
}


void Rock::MoveUpdate(float _Delta)
{
	//애니메이션에 맞게 100픽셀 이동

	//인자하나 만들어서 100픽셀 계산해서 이동후 완료하면 아이들로 전호나
	float Speed = 1000.0f * _Delta;

	//더한 후 픽셀을 벗어나면 타일사이즈로에 맞게  돌리고 그에맞게 스피드도 돌린다.
	PixelCount += Speed;
	if (PixelCount >= TILESIZE)
	{
		Speed -= (PixelCount - TILESIZE);
	}

	float4 MovePos = Dir * Speed;

	AddPos(MovePos);

	if (PixelCount >= TILESIZE)
	{
		ChanageState(ObstacleState::Idle);
	}

}
