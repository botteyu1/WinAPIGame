#pragma once
#include "Dialog.h"
// Ό³Έν :
class DialogEnding : public Dialog
{
public:
	// constrcuter destructer
	DialogEnding();
	~DialogEnding();

	// delete Function
	DialogEnding(const DialogEnding& _Other) = delete;
	DialogEnding(DialogEnding&& _Other) noexcept = delete;
	DialogEnding& operator=(const DialogEnding& _Other) = delete;
	DialogEnding& operator=(DialogEnding&& _Other) noexcept = delete;
	void Start() override;
protected:

	//void Update(float _Delta) override;

private:
	//void OnStart() override;
	GameEngineRenderer* MainCutSceneBGRenderer = nullptr;

	void ConversationStart() override;
	void OnStart() override;
	void ConversationUpdate(float _Delta) override;
};

