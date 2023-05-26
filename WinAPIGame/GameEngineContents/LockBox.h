#pragma once
#include "Obstacle.h"

// Ό³Έν :
class LockBox : public Obstacle
{
public:
	// constrcuter destructer
	LockBox();
	~LockBox();

	// delete Function
	LockBox(const LockBox& _Other) = delete;
	LockBox(LockBox&& _Other) noexcept = delete;
	LockBox& operator=(const LockBox& _Other) = delete;
	LockBox& operator=(LockBox&& _Other) noexcept = delete;

	void Start() override;
	void Obtained();

protected:

	void DeathStart()  override;
private:

};

