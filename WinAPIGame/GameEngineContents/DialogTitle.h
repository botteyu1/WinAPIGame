#pragma once
#include "Dialog.h"
// 설명 :
class DialogTitle : public Dialog
{

	// 시작시 나오는 대화
public:
	// constrcuter destructer
	DialogTitle();
	~DialogTitle();

	// delete Function
	DialogTitle(const DialogTitle& _Other) = delete;
	DialogTitle(DialogTitle&& _Other) noexcept = delete;
	DialogTitle& operator=(const DialogTitle& _Other) = delete;
	DialogTitle& operator=(DialogTitle&& _Other) noexcept = delete;

	void Start() override;

protected:
	void Update(float _Delta) override;

	void ConversationUpdate(float _Delta) override;
	void SuccessUpdate(float _Delta) override;
	void OnUpdate(float _Delta) override;
	void AnswerUpdate(float _Delta) override;

	void ConversationStart() override;
	void SuccessStart() override;
	void BadEndStart() override;
	void OnStart() override;

	GameEngineRenderer* MainBGRenderer2 = nullptr;
	GameEngineRenderer* MainCutSceneBGRenderer = nullptr;
	GameEngineRenderer* IntroRenderer = nullptr;

private:

	

	//GameEngineRenderer* AnswerRenderer0On = nullptr;
	//GameEngineRenderer* AnswerRenderer0Off = nullptr;

};

