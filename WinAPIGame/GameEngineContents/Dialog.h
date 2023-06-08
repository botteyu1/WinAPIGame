#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <string>
#include <vector>

enum class DialogState
{
	Conversation,
	Answer,
	Success,
	BadEnd,
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
	void Init(int _StageLevel);
	void ChangeState(DialogState _State);

protected:
	void Update(float _Delta) override;

private:

	class Conversation
	{
	public:
		std::string Text;
		std::string NPCStanding = "";
		bool IsAnswer = false;
		bool IsEnd = false;
	};

	void StateUpdate(float _Delta);

	DialogState State = DialogState::Max;
	std::vector<Conversation> ConversationList;  // 대화 목록
	int CorrectAnswer = 1;
	int CurAnswer = 1;
	int CurConversationIndex = 0;
	Conversation BadEndConversation;  // BadEnd가 발생할때 대화 인덱스
	Conversation SuccessConversation;  // Success가 발생할때 대화 인덱스

	GameEngineRenderer* MainTextRenderer = nullptr;
	GameEngineRenderer* MainNPCRenderer = nullptr;
	GameEngineRenderer* NameTextRenderer = nullptr;
	GameEngineRenderer* AnswerRenderer1On = nullptr;
	GameEngineRenderer* AnswerRenderer1Off = nullptr;
	GameEngineRenderer* AnswerRenderer2On = nullptr;
	GameEngineRenderer* AnswerRenderer2Off = nullptr;
	GameEngineRenderer* AnswerTextRenderer1 = nullptr;
	GameEngineRenderer* AnswerTextRenderer2 = nullptr;
	GameEngineRenderer* SuccessRenderer = nullptr;
	GameEngineRenderer* BadEndRenderer = nullptr;

	void SetDialogData(int _StageLevel);

	void ConversationUpdate(float _Delta);
	void AnswerUpdate(float _Delta);
	void SuccessUpdate(float _Delta);
	void BadEndUpdate(float _Delta);

	void OnUpdate(float _Delta);
	void OffUpdate(float _Delta);

	void ConversationStart();
	void AnswerStart();
	void SuccessStart();
	void BadEndStart();
	void OnStart();
	void OffStart();


};

