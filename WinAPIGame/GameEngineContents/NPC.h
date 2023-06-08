#pragma once
#include "Obstacle.h"
// Ό³Έν :
class NPC : public Obstacle
{
public:
	// constrcuter destructer
	NPC();
	~NPC();

	// delete Function
	NPC(const NPC& _Other) = delete;
	NPC(NPC&& _Other) noexcept = delete;
	NPC& operator=(const NPC& _Other) = delete;
	NPC& operator=(NPC&& _Other) noexcept = delete;

	void Start() override;

	void Init(float4 _TilePos, int _Custom = 0) override;
	void Update(float _Delta) override;

protected:
private:

	GameEngineRenderer* LoveSignRenderer = nullptr;
	float LoveSignSpeed = 50.0f;
};

