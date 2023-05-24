#pragma once
#include "TileMap.h"

// ���� :
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
	// �÷��̸� ������������ ���̰� �ִ� ������ �����ҿ���
	std::vector<TileMap*> TileMapVector;

};

