#pragma once
#include "Obstacle.h"

// Ό³Έν :
class Rock : public Obstacle
{
public:
	// constrcuter destructer
	Rock();
	~Rock();

	// delete Function
	Rock(const Rock& _Other) = delete;
	Rock(Rock&& _Other) noexcept = delete;
	Rock& operator=(const Rock& _Other) = delete;
	Rock& operator=(Rock&& _Other) noexcept = delete;

	void Start() override;
	void TryMove(float4 _Dir);


protected:
	void MoveStart() override;

	void MoveUpdate(float _Delta)  override;

private:
	//void Init(float4 _Pos, int _TileX, int _TileY, int _TextureNum);

};

