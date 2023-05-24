#pragma once

#include <vector>
#include "Obstacle.h"

// ���� :
class Undead : public Obstacle
{

public:
	// constrcuter destructer
	Undead();
	~Undead();

	// delete Function
	Undead(const Undead& _Other) = delete;
	Undead(Undead&& _Other) noexcept = delete;
	Undead& operator=(const Undead& _Other) = delete;
	Undead& operator=(Undead&& _Other) noexcept = delete;
	void Start() override;

protected:

private:
	
};

