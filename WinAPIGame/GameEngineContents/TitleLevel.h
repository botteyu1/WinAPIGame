#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>



// Ό³Έν :
class TitleLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

	class DialogTitle* GetTitleDialog()
	{
		return TitleDialog;
	}

	class LevelChange* GetTitleLevelChange()
	{
		return TitleLevelChange;
	}

	void Start() override;

	GameEngineSoundPlayer* GetBgm()
	{
		return &Bgm;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	DialogTitle* TitleDialog = nullptr;
	LevelChange* TitleLevelChange = nullptr;
	GameEngineSoundPlayer Bgm;
	bool BgmOn = false;
	
};

