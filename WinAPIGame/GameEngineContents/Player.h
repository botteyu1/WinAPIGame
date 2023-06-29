#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "VFX.h"

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


	class VFX* GetPlayerVFX()
	{
		return PlayerVFX;
	}

	void SetPlayerTilePos(int _X, int _Y)
	{
		TilePos = { static_cast<float>(_X),static_cast<float>(_Y) };
	}

	void SetHP(int _HP)
	{
		HP = _HP;
	}

	void SetPlayLevel(class PlayLevel* _PlayLevel)
	{
		PlayLevelPtr = _PlayLevel;
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
	void TrapChek(float4 _ObsTilePos);

	void ChangeState(PlayerState State);

	void KeyCheckOff()
	{
		KeyCheck = false;
	}
	void CameraFoucusOn()
	{
		CameraFoucus = true;
	}

protected:

	void IdleStart();
	void RunStart();
	void AttackStart();
	void SuccessStart();

	// Ŭ������ ���� �ǰ�.
	void IdleUpdate(float _Delta);
	void RunUpdate(float _Delta);
	void AttackUpdate(float _Delta);
	void SuccessUpdate(float _Delta);

	void StateUpdate(float _Delta);
	PlayLevel* PlayLevelPtr= nullptr;
	PlayerState State = PlayerState::Max;
	float4 Dir = float4::ZERO;
	float4 TilePos = float4::ZERO; //�÷��̾� Ÿ����ġ
	int HP = 0; // �̵�Ƚ�� ü��
	bool Moved = false; // �̹� �����ӿ� �̵��ߴ��� Ȯ��

	VFX* PlayerVFX = nullptr; // ������ VFX
	
	float MotionTime = 0.0f; // 100 = 0.1�� ����̵��ð� ����Ű�Էµ�����

	bool CameraFoucus = false; // ī�޶� ��Ŀ��
	
	//float EndPauseTime = 0;

private:
	void LevelStart() override;
	void Start() override;
	void Update(float _Delta) override;
	void Render(float _Delta) override;
	bool KeyCheck = false;
	void DirCheck();
	
};



