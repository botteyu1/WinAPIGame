#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <string>

enum class DialogeState
{
	Conversation,
	Answer,
	On,
	Off,
	Max, // 일반적으로 사용하지 않는 값.
};

// 설명 :
class Dialog : public GameEngineActor
{

public:
	// constrcuter destructer
	Dialog();
	~Dialog();

	// delete Function
	Dialog(const Dialog& _Other) = delete;
	Dialog(Dialog&& _Other) noexcept = delete;
	Dialog& operator=(const Dialog& _Other) = delete;
	Dialog& operator=(Dialog&& _Other) noexcept = delete;

	void Start() override;
	void ChanageState(DialogeState _State);

protected:
	void Update(float _Delta) override;

private:
	void StateUpdate(float _Delta);

	DialogeState State = DialogeState::Max;

	void ConversationUpdate(float _Delta);
	void AnswerUpdate(float _Delta);
	void OnUpdate(float _Delta);
	void OffUpdate(float _Delta);

	void ConversationStart();
	void AnswerStart();
	void OnStart();
	void OffStart();


};

