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

	DialogState GetDialogState()
	{
		return State;
	}

protected:
	void Update(float _Delta) override;


	class Conversation
	{
	public:
		std::string Text;
		std::string NPCStanding = "";
		bool IsAnswer = false;
		bool IsEnd = false;
		int Left = 0; // 기본적으로 대화가 왼쪽으로 진행 기본값 인경우 ++가된다.
		int Right = 0; // 틀렸을 때 오른쪽으로 진행

		void SetNPCStanding(const std::string& _NPCStanding)
		{
			NPCStanding = _NPCStanding;
		}
		void AnswerOn()
		{
			IsAnswer = true;
		}
		
		void EndOn()
		{
			IsEnd = true;
		}
		void SetLeft(int _Left)
		{
			Left = _Left;
		}

		void SetRight(int _Right)
		{
			Right = _Right;
		}


	};

	void StateUpdate(float _Delta);

	DialogState State = DialogState::Max;
	std::vector<Conversation> ConversationList;  // 대화 목록
	std::vector<Conversation> AnswerList; // 대답 목록
	int CorrectAnswer = 1; //정답
	int CurAnswer = 1; // 현재 선택중인 답
	int CurConversationIndex = 0;
	int CurAnswerIndex = 0; 
	Conversation BadEndConversation;  // BadEnd가 발생할때 대화 인덱스
	

	GameEngineRenderer* MainTextRenderer = nullptr;
	GameEngineRenderer* MainBGRenderer = nullptr;
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
	GameEngineRenderer* BooperRenderer = nullptr;
	//GameEngineRenderer* BooperTabRenderer = nullptr;

	//float AnswerAnimationPixel = 0.0f;


	void SetDialogData(int _StageLevel);

	virtual void ConversationUpdate(float _Delta);
	virtual void AnswerUpdate(float _Delta);
	virtual void SuccessUpdate(float _Delta);
	void BadEndUpdate(float _Delta);

	virtual void OnUpdate(float _Delta);
	void OffUpdate(float _Delta);

	virtual void ConversationStart();
	void AnswerStart();
	virtual void SuccessStart();
	virtual void BadEndStart();
	virtual void OnStart();
	void OffStart();

private:

};

