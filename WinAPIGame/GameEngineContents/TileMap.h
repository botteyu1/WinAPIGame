#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>
#include "Obstacle.h"
class Obstacle;

enum class TTYPE
{
	NO,//NE,
	WA,//LL,
	PL,//ayer
	NP,//C,
	UN,//dead,
	SP,//ike always,
	SO,//pike on,
	SF,// pike off,
	RO,//ck
	LO,//ckBox
	KE,//Y
	EN,//D
};
// ���� :
class TileMap	
{
	static TileMap LevelTileMap;
	

public:
	static TileMap*  GetLevelTileMap()  { return &LevelTileMap; }
	
	// constrcuter destructer
	TileMap();
	~TileMap();

	// delete Function
	TileMap(const TileMap& _Other) = delete;
	TileMap(TileMap&& _Other) noexcept = delete;
	TileMap& operator=(const TileMap& _Other) = delete;
	TileMap& operator=(TileMap&& _Other) noexcept = delete;
	void Init(std::vector< TTYPE>& _TileMapVector, float4 _Size, float4 _Pos);

	TTYPE GetTileType(int _X, int _Y);
	float4 GetTilePos(int _X, int _Y);
	
	GameEngineActor* GetTileActor(int _X, int _Y);
	std::pair<TTYPE, GameEngineActor*>& GetTilePair(int _X, int _Y);
	std::pair<TTYPE, GameEngineActor*>& GetTilePair(float4 _Pos)
	{
		return GetTilePair(_Pos.iX(), _Pos.iY());
	}
	
	

	float4 GetTileMapPos() { return TileMapPos; }
	float4 GetTileMapSize() { return TileMapSize; }


	void SetTileType(TTYPE _Type ,float4 _Pos);
	void SetTileActor(GameEngineActor* _Actor, int _X, int _Y);
	void SetTileActor(GameEngineActor* _Actor, float4 _Pos );
	void SetTilePair(TTYPE _Type, GameEngineActor* _Actor, float4 _Pos)
	{
		SetTilePair(_Type, _Actor, _Pos.iX(), _Pos.iY());
	}
	void SetTilePair(TTYPE _Type, GameEngineActor* _Actor, int _X, int _Y);

	void SetTileMapPos(float4 _Pos) { TileMapPos = _Pos; }
	void SetTileMapSize(float4 _Size) { TileMapSize = _Size; }


	Obstacle* GetTileTrapActor(int _X, int _Y);
	TTYPE GetTileTrapType(int _X, int _Y);
	std::pair<TTYPE, Obstacle*>& GetTileTrapPair(int _X, int _Y);
protected:

private:
	//Ÿ���� �ּұ��� �����ϰ� ���� ����
	
	std::vector<std::pair<TTYPE, GameEngineActor*>> TileMapVector; // Ÿ���� ���ͷ� ����
	std::vector<std::pair<TTYPE, Obstacle*>> TrapMapVector; // ������ũ�� ���ͷ� ����
	float4 TileMapPos = float4(0.0f, 0.0f, 0.0f, 0.0f); // Ÿ�ϸ� ��ǥ 0,0�� ȭ��� ��ġ�� ��ġ
	float4 TileMapSize = float4(0.0f, 0.0f, 0.0f, 0.0f); // Ÿ�ϸ��� �� ũ��
	

};

