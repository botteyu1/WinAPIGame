#pragma once
#include <GameEngineCore/GameEngineActor.h>



// Ό³Έν :
class Obj
: public GameEngineActor
{
public:
	// constrcuter destructer
	Obj();
	~Obj();

	// delete Function
	Obj(const Obj& _Other) = delete;
	Obj(Obj&& _Other) noexcept = delete;
	Obj& operator=(const Obj& _Other) = delete;
	Obj& operator=(Obj&& _Other) noexcept = delete;

	void Start() override;
	void Init(float4 _Pos, int _FireOn);

protected:

private:

};

