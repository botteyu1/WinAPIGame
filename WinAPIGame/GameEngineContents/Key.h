#pragma once
#include "Obstacle.h"

// Ό³Έν :
class Key : public Obstacle
{
public:
	// constrcuter destructer
	Key();
	~Key();

	// delete Function
	Key(const Key& _Other) = delete;
	Key(Key&& _Other) noexcept = delete;
	Key& operator=(const Key& _Other) = delete;
	Key& operator=(Key&& _Other) noexcept = delete;

	void Start() override;

	void Obtained();

protected:

	void DeathStart()  override;

	void DeathUpdate(float _Delta)  override;

private:

};

