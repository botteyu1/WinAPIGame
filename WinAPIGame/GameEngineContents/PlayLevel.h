#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "TileMap.h"

// 설명 :
class PlayLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;


	

protected:
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	void Start() override;
	void Update(float _Delta) override;
	void Render(float _Delta) override;
	void Release() override;

	class BackGround* BackGroundPtr = nullptr;
	class Player* LevelPlayer = nullptr;
	int StageLevel = 0;
	
	class LevelChange* PlayLevelChange = nullptr; // 화면전환시 나오는 애니메이션

	//std::vector<TTYPE> TileStartData;
	class TileMap TileMapStartData;

	void BatchActor(); // 액터 생성밎 배치
	void ResetActor(); // 액터 위치 초기화 및 업데이트 온

	void SetLevelData(); // 각 스테이지 별 저장한 데이터 불러오기
};

