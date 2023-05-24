#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>

enum class TTYPE
{
	NO,//NE, // 0
	WA,//LL, // 1
	PL,//ayer, //2
	NP,//C, // 3
	UN,//dead,// 4 
	SP,//ike, // 5
	RO,//ck,// 6
	LO,//ckBox,// 7
	KE,//Y,// 8
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

	float4 GetTileMapPos() { return TileMapPos; }
	float4 GetTileMapSize() { return TileMapSize; }

	void SetTileType(float4 _Pos , TTYPE _Type);
	void SetTileMapPos(float4 _Pos) { TileMapPos = _Pos; }
	void SetTileMapSize(float4 _Size) { TileMapSize = _Size; }
	

protected:

private:

	std::vector<TTYPE> TileMapVector; // Ÿ���� ���ͷ� ����
	float4 TileMapPos = float4(0.0f, 0.0f, 0.0f, 0.0f); // Ÿ�ϸ� ��ǥ 0,0�� ȭ��� ��ġ�� ��ġ
	float4 TileMapSize = float4(0.0f, 0.0f, 0.0f, 0.0f); // Ÿ�ϸ��� �� ũ��
	

};

