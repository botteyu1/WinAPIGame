#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>
// Ό³Έν :
class Obstacle : public GameEngineActor
{
private:
	static std::vector<Obstacle*> AllObstacle;
public:
	static std::vector<Obstacle*>& GetAllObstacle()
	{
		return AllObstacle;
	}
	// constrcuter destructer
	Obstacle();
	~Obstacle();

	// delete Function
	Obstacle(const Obstacle& _Other) = delete;
	Obstacle(Obstacle&& _Other) noexcept = delete;
	Obstacle& operator=(const Obstacle& _Other) = delete;
	Obstacle& operator=(Obstacle&& _Other) noexcept = delete;
	void Init(float4 _Pos);

protected:
	GameEngineRenderer* MainRenderer = nullptr;

private:

};

