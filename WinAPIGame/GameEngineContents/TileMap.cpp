#include "TileMap.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "ContentsEnum.h"

TileMap TileMap::LevelTileMap;

TileMap::TileMap() 
{
}

TileMap::~TileMap()
{
	
	
}

void TileMap::Init(std::vector<TTYPE>& _TileMapVector, float4 _Size, float4 _Pos)
{
	TileMapVector.resize(_TileMapVector.size());

	for (size_t i = 0; i < _TileMapVector.size(); i++)
	{
		TileMapVector[i] = std::make_pair(_TileMapVector[i], nullptr);
	}
	TileMapSize = _Size;
	TileMapPos = _Pos;
}

TTYPE TileMap::GetTileType(int _X, int _Y)
{
	int Pos = (TileMapSize.iX() * _Y) + _X;
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
		return TTYPE::EN;
	}

	return TileMapVector[Pos].first;
	
}
GameEngineActor* TileMap::GetTileActor(int _X, int _Y)
{
	int Pos = (TileMapSize.iX() * _Y) + _X;
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
		return nullptr;
	}

	return TileMapVector[Pos].second;
	
}

std::pair<TTYPE, GameEngineActor*>& TileMap::GetTilePair(int _X, int _Y)
{
	int Pos = (TileMapSize.iX() * _Y) + _X;
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
	}

	return TileMapVector[Pos];
}


float4 TileMap::GetTilePos(int _X, int _Y)
{
	float4 Pos = float4(_X * TILESIZE + TileMapPos.iX()+ (TILESIZE/2), _Y * TILESIZE + TileMapPos.iY()+(TILESIZE / 2));
	return Pos;
}

void TileMap::SetTileType(TTYPE _Type, float4 _Pos)
{
	int Pos = (TileMapSize.iX() * _Pos.iY()) + _Pos.iX();
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
		return;
	}

	TileMapVector[Pos].first = _Type;
}

void TileMap::SetTileActor(GameEngineActor* _Actor, float4 _Pos )
{
	int Pos = (TileMapSize.iX() * _Pos.iY()) + _Pos.iX();
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
		return;
	}

	TileMapVector[Pos].second = _Actor;
}

void TileMap::SetTileActor(GameEngineActor* _Actor, int _X, int _Y)
{
	int Pos = (TileMapSize.iX() * _Y) + _X;
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
		return;
	}

	TileMapVector[Pos].second = _Actor;
}

void TileMap::SetTilePair(TTYPE _Type, GameEngineActor* _Actor, int _X, int _Y)
{
	int Pos = (TileMapSize.iX() * _Y) + _X;
	if (TileMapVector.size() < Pos)
	{
		MsgBoxAssert("지정한 위치값이 타일값을 초과했습니다.");
		return;
	}

	TileMapVector[Pos].first = _Type;
	TileMapVector[Pos].second = _Actor;
}



