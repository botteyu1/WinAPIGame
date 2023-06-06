#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class UI : public GameEngineActor
{
public:
	// constrcuter destructer
	UI();
	~UI();

	// delete Function
	UI(const UI& _Other) = delete;
	UI(UI&& _Other) noexcept = delete;
	UI& operator=(const UI& _Other) = delete;
	UI& operator=(UI&& _Other) noexcept = delete;

	void Start() override;
	void Init(int _Stage) ;

protected:

private:
	void Update(float _Delta) override;

	GameEngineRenderer* UIRendererLT = nullptr;
	GameEngineRenderer* UIRendererLB = nullptr;
	GameEngineRenderer* UIRendererRT = nullptr;
	GameEngineRenderer* UIRendererRB = nullptr;

	GameEngineRenderer* UIRendererHP = nullptr;

};

