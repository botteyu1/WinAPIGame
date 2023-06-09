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
	RO,//ck
	LO,//ckBox
	
	EN,//D
};
// 트랩타일
enum class OTYPE
{
	NO,//NE,
	SP,//ike always,
	SO,//pike on,
	SF,// pike off,
	KE,//Y
	EN,//D
};
// 설명 :
class TileMap	
{
	static TileMap LevelTileMap;
	

public:

	static TileMap*  GetLevelTileMap()  { return &LevelTileMap; }
	static void SetLevelTileMap(TileMap* _LevelTileMap) {
		LevelTileMap.TileMapVector = _LevelTileMap->TileMapVector;
		LevelTileMap.TrapMapVector = _LevelTileMap->TrapMapVector;
		LevelTileMap.TileMapPos = _LevelTileMap->TileMapPos;
		LevelTileMap.TileMapSize = _LevelTileMap->TileMapSize;

	}
	// constrcuter destructer
	TileMap();
	~TileMap();

	// delete Function
	//TileMap(const TileMap& _Other) = delete;
	//TileMap(TileMap&& _Other) noexcept = delete;
	//TileMap& operator=(const TileMap& _Other) = delete;
	//TileMap& operator=(TileMap&& _Other) noexcept = delete;
	void Init(std::vector< TTYPE>& _TileMapVector, std::vector<OTYPE>& _TrapMapVector, float4 _Size, float4 _Pos); //타일 설정 밑 타일 렌더 시작 기준점 설정
	void Reset(std::vector< TTYPE>& _TileMapVector, std::vector<OTYPE>& _TrapMapVector);

	TTYPE GetTileType(int _X, int _Y);
	float4 GetTilePos(float4 _TilePos)
	{
		return GetTilePos(_TilePos.iX(), _TilePos.iY());
	}
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
	OTYPE GetTileTrapType(int _X, int _Y);
	std::pair<OTYPE, Obstacle*>& GetTileTrapPair(int _X, int _Y);
	std::pair<OTYPE, Obstacle*>& GetTileTrapPair(float4 _Pos)
	{
		return GetTileTrapPair(_Pos.iX(), _Pos.iY());
	}
protected:

private:
	//타입을 주소까지 저장하게 페어로 변경
	
	std::vector<std::pair<TTYPE, GameEngineActor*>> TileMapVector; // 타일을 벡터로 저장
	std::vector<std::pair<OTYPE, Obstacle*>> TrapMapVector; // 스파이크을 벡터로 저장
	float4 TileMapPos = float4(0.0f, 0.0f, 0.0f, 0.0f); // 타일맵 좌표 0,0이 화면상에 배치될 위치
	float4 TileMapSize = float4(0.0f, 0.0f, 0.0f, 0.0f); // 타일맵의 총 크기
	

};

