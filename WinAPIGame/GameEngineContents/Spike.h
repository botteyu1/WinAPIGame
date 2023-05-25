#pragma once
#include "Obstacle.h"
class Spike :
    public Obstacle
{    
	
public:
	// constrcuter destructer
	Spike();
	~Spike();

	// delete Function
	Spike(const Spike& _Other) = delete;
	Spike(Spike&& _Other) noexcept = delete;
	Spike& operator=(const Spike& _Other) = delete;
	Spike& operator=(Spike&& _Other) noexcept = delete;

	void Start() override;

protected:
	void IdleStart() override;
	void AttackStart() override;

	void IdleUpdate(float _delta) override;
	void AttackUpdate(float _delta) override;

private:

	
};
