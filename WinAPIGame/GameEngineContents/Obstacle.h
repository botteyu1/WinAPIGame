#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>

enum class ObstacleState
{
	Idle,
	Move,
	Death,
	Attack,
	Max, // 일반적으로 사용하지 않는 값.
};

// 설명 :
class Obstacle : public GameEngineActor
{
private:
	//static std::vector<Obstacle*> AllObstacle;
public:
	/*static std::vector<Obstacle*>& GetAllObstacle()
	{
		return AllObstacle;
	}*/
	// constrcuter destructer
	Obstacle();
	~Obstacle();

	// delete Function
	Obstacle(const Obstacle& _Other) = delete;
	Obstacle(Obstacle&& _Other) noexcept = delete;
	Obstacle& operator=(const Obstacle& _Other) = delete;
	Obstacle& operator=(Obstacle&& _Other) noexcept = delete;
	virtual void Init(float4 _TilePos, int _Custom = 0);

	void Update(float _Delta) override;

	float4 GetTilePos()
	{
		return TilePos;
	}

	void SetTilePos(int _X, int _Y)
	{
		TilePos = { static_cast<float>(_X),static_cast<float>(_Y) };
	}
	ObstacleState GetState()
	{
		return State;
	}

protected:
	GameEngineRenderer* MainRenderer = nullptr;
	float4 TilePos = float4::ZERO;
	float4 Dir = float4::ZERO;
	float PixelCount = 0.0f; 

	void ChanageState(ObstacleState _State);
	void StateUpdate(float _Delta);
	ObstacleState State = ObstacleState::Max;

	virtual void IdleStart() {}
	virtual void MoveStart() {}
	virtual void DeathStart() {}
	virtual void AttackStart() {}

	// 클래스로 만들어도 되고.
	virtual void IdleUpdate(float _Delta) {}
	virtual void MoveUpdate(float _Delta) {}
	virtual void DeathUpdate(float _Delta) {}
	virtual void AttackUpdate(float _Delta) {}

	

	


private:


};

