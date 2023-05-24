#pragma once
#include "TileMap.h"

// 설명 :
class TileMapData
{
	

public:
	// constrcuter destructer
	TileMapData();
	~TileMapData();

	// delete Function
	TileMapData(const TileMapData& _Other) = delete;
	TileMapData(TileMapData&& _Other) noexcept = delete;
	TileMapData& operator=(const TileMapData& _Other) = delete;
	TileMapData& operator=(TileMapData&& _Other) noexcept = delete;

protected:

private:
	// 플레이맵 스테이지별로 차이가 있는 변수를 저장할예정
	std::vector<TileMap*> TileMapVector;

};

