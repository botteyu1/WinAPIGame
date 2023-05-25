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

protected:

private:

};

