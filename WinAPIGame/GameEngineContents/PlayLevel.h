#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "TileMap.h"

// ���� :
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

	class LevelChange* GetLevelChange() const { return PlayLevelChange; }
	class Dialog* GetDialog() const { return PlayDialog; }
	
	float4 GetNPCPos() const { return NPCPos; }

	void AddStageLevel(int _Num) { StageLevel += _Num; }

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
	
	LevelChange* PlayLevelChange = nullptr; // ȭ����ȯ�� ������ �ִϸ��̼�
	class UI* PlayUI = nullptr; // ������ UI
	Dialog* PlayDialog = nullptr; // ��ȭâ

	//std::vector<TTYPE> TileStartData;
	class TileMap TileMapStartData;

	int StageLevel = 0; // ���� �������� ����
	float4 NPCPos = float4::ZERO; // NPC��ġ

	void BatchActor(); // ���� �����G ��ġ
	void ResetActor(); // ���� ��ġ �ʱ�ȭ �� ������Ʈ ��

	void SetLevelData(); // �� �������� �� ������ ������ �ҷ�����
};

