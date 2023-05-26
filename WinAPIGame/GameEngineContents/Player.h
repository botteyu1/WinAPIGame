#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PlayerState
{
	Idle,
	Run,
	Attack,
	Success,
	Max, // 일반적으로 사용하지 않는 값.
};



// 설명 :
class Player : public GameEngineActor
{
private:
	static Player* MainPlayer;

public:
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	GameEngineRenderer* MainRenderer = nullptr;

	float4 GetPlayerTilePos()
	{
		return TilePos;
	}

	void SetPlayerTilePos(int _X, int _Y)
	{
		TilePos = { static_cast<float>(_X),static_cast<float>(_Y) };
	}

	void SetHP(int _HP)
	{
		HP = _HP;
	}

	int GetHP()
	{
		return HP;
	}
	
	void Move();

	bool IsMoved()
	{
		return Moved;
	}

protected:

	void IdleStart();
	void RunStart();
	void AttackStart();
	void SuccessStart();

	// 클래스로 만들어도 되고.
	void IdleUpdate(float _Delta);
	void RunUpdate(float _Delta);
	void AttackUpdate(float _Delta);
	void SuccessUpdate(float _Delta);

	void ChanageState(PlayerState State);
	void StateUpdate(float _Delta);
	PlayerState State = PlayerState::Max;
	float4 Dir = float4::ZERO;
	float4 TilePos = float4::ZERO; //플레이어 타일위치
	int HP = 0; // 이동횟수 체력
	bool Moved = false; // 이번 프레임에 이동했는지 확인

	void TrapChek();

	
	float MotionTime = 0.0f; // 100 = 0.1초 모션이동시간 연속키입력딜레이

	void DirCheck();

	

private:
	void LevelStart() override;
	void Start() override;
	void Update(float _Delta) override;

	bool KeyCheck = false;
	
};



