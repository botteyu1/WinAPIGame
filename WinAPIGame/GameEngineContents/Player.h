#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PlayerState
{
	Idle,
	Run,
	Attack,
	Success,
	Max, // �Ϲ������� ������� �ʴ� ��.
};



// ���� :
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

protected:
	



	void IdleStart();
	void RunStart(float _Delta);
	void AttackStart(float _Delta);

	// Ŭ������ ���� �ǰ�.
	void IdleUpdate(float _Delta);
	void RunUpdate(float _Delta);
	void AttackUpdate(float _Delta);

	void ChanageState(float _Delta,PlayerState State);
	void StateUpdate(float _Delta);
	PlayerState State = PlayerState::Max;
	float4 Dir = float4::ZERO;
	
	float4 TilePos = float4::ZERO; //�÷��̾� Ÿ����ġ

	
	float PixelCount = 0.0f;

	void DirCheck();

	

private:
	void LevelStart() override;
	void Start() override;
	void Update(float _Delta) override;
	
};



