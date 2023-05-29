#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class LevelState
{
	Idle,
	Transition,
	Death,
	Max, // 일반적으로 사용하지 않는 값.
};

// 설명 :
class LevelChange : public GameEngineActor
{
	
public:
	// constrcuter destructer
	LevelChange();
	~LevelChange();

	// delete Function
	LevelChange(const LevelChange& _Other) = delete;
	LevelChange(LevelChange&& _Other) noexcept = delete;
	LevelChange& operator=(const LevelChange& _Other) = delete;
	LevelChange& operator=(LevelChange&& _Other) noexcept = delete;

	void Update(float _Delta) override;

protected:

private:
	GameEngineRenderer* MainRenderer = nullptr;

	void ChanageState(LevelState _State);
	void StateUpdate(float _Delta);
	LevelState State = LevelState::Max;

	void Start() override;

	void IdleStart();
	void TransitionStart();
	void DeathStart();


	// 클래스로 만들어도 되고.
	void IdleUpdate(float _Delta);
	void TransitionUpdate(float _Delta);
	void DeathUpdate(float _Delta);
	

};

