#include "GameEngineRenderer.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include "GameEngineCamera.h"
#include "ResourcesManager.h"
#include "GameEngineActor.h"
#include "GameEngineSprite.h"
#include "GameEngineLevel.h"
#include <math.h>

GameEngineRenderer::GameEngineRenderer()
{
}

GameEngineRenderer::~GameEngineRenderer()
{
}

void GameEngineRenderer::SetSprite(const std::string& _Name, size_t _Index/* = 0*/)
{
	Sprite = ResourcesManager::GetInst().FindSprite(_Name);

	if (nullptr == Sprite)
	{
		MsgBoxAssert("존재하지 않는 스프라이트를 세팅하려고 했습니다." + _Name);
	}

	const GameEngineSprite::Sprite& SpriteInfo = Sprite->GetSprite(_Index);

	Texture = SpriteInfo.BaseTexture;

	SetCopyPos(SpriteInfo.RenderPos);
	SetCopyScale(SpriteInfo.RenderScale);

}

void GameEngineRenderer::SetTexture(const std::string& _Name)
{
	Texture = ResourcesManager::GetInst().FindTexture(_Name);

	if (nullptr == Texture)
	{
		MsgBoxAssert("존재하지 않는 텍스처를 세팅하려고 했습니다." + _Name);
	}

	SetCopyPos(float4::ZERO);
	SetCopyScale(Texture->GetScale());

	if (false == ScaleCheck)
	{
		SetRenderScaleToTexture();
	}
}

void GameEngineRenderer::SetRenderScaleToTexture()
{
	if (nullptr != Texture)
	{
		RenderScale = Texture->GetScale();
	}
	ScaleCheck = false;
}

void GameEngineRenderer::Render( float _DeltaTime)
{
	if (nullptr != CurAnimation)
	{
	
		CurAnimation->IsEnd = false;
		

		CurAnimation->CurInter -= _DeltaTime;
		if (0.0f >= CurAnimation->CurInter)
		{
			++CurAnimation->CurFrame;

			// 2 8 
			// 2 - 2 0
			// 3 - 2 1

			if (CurAnimation->CurFrame > CurAnimation->EndFrame)
			{
				CurAnimation->IsEnd = true;
				if (true == CurAnimation->Loop)
				{
					CurAnimation->CurFrame = CurAnimation->StartFrame;
				}
				else
				{
					--CurAnimation->CurFrame;
				}
			}

			CurAnimation->CurInter
				= CurAnimation->Inters[CurAnimation->CurFrame - CurAnimation->StartFrame];
		}

		Sprite = CurAnimation->Sprite;
		const GameEngineSprite::Sprite& SpriteInfo = Sprite->GetSprite(CurAnimation->CurFrame);
		Texture = SpriteInfo.BaseTexture;
		SetCopyPos(SpriteInfo.RenderPos);
		SetCopyScale(SpriteInfo.RenderScale);

		if (true/*false == ScaleCheck*/)
		{
			SetRenderScale(SpriteInfo.RenderScale * ScaleRatio);
		}
	}
	//앞 애니메이션에서 크기가 저장되면 다음 애니메이션도 그대로 재생되는 문제 있음.
	if (nullptr == Texture)
	{
		MsgBoxAssert("이미지를 세팅하지 않은 랜더러 입니다.");
	}

	//백버퍼가 아닌 자신의 함수로 그린다.
	Texture->TransCopy( GetActor()->GetPos() + RenderPos - Camera->GetPos(), RenderScale, CopyPos, CopyScale, RGB(255, 0, 255), FlipCheck);

}



GameEngineRenderer::Animation* GameEngineRenderer::FindAnimation(const std::string& _AniamtionName)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_AniamtionName);

	std::map<std::string, Animation>::iterator FindIter = AllAnimation.find(UpperName);

	if (FindIter == AllAnimation.end())
	{
		return nullptr;
	}

	return &FindIter->second;
}


void GameEngineRenderer::CreateAnimation(
	const std::string& _AniamtionName,
	const std::string& _SpriteName,
	size_t _Start /*= -1*/, size_t _End /*= -1*/,
	float _Inter /*= 0.1f*/,
	bool _Loop /*= true*/)
{
	std::string UpperName = GameEngineString::ToUpperReturn(_AniamtionName);

	if (nullptr != FindAnimation(UpperName))
	{
		MsgBoxAssert("이미 존재하는 애니메이션 네임입니다." + UpperName);
		return;
	}

	GameEngineSprite* Sprite = ResourcesManager::GetInst().FindSprite(_SpriteName);

	if (nullptr == Sprite)
	{
		MsgBoxAssert("존재하지 않는 스프라이트로 애니메이션을 만들려고 했습니다." + _SpriteName);
		return;
	}

	GameEngineRenderer::Animation& Animation = AllAnimation[UpperName];

	Animation.Sprite = Sprite;

	if (_Start != -1)
	{
		Animation.StartFrame = _Start;
	}
	else
	{
		Animation.StartFrame = 0;
	}

	if (_End != -1)
	{
		Animation.EndFrame = _End;
	}
	else
	{
		Animation.EndFrame = Animation.Sprite->GetSpriteCount() - 1;
	}

	// 0, 0
	Animation.Inters.resize((Animation.EndFrame - Animation.StartFrame) + 1);

	for (size_t i = 0; i < Animation.Inters.size(); i++)
	{
		Animation.Inters[i] = _Inter;
	}

	Animation.Loop = _Loop;

}


void GameEngineRenderer::ChangeAnimation(const std::string& _AniamtionName, bool _ForceChange)
{
	Animation* ChangeAni = FindAnimation(_AniamtionName);

	if (ChangeAni == CurAnimation && false == _ForceChange)
	{
		return;
	}

	CurAnimation = FindAnimation(_AniamtionName);

	CurAnimation->CurInter = CurAnimation->Inters[0];
	CurAnimation->CurFrame = CurAnimation->StartFrame;

	if (nullptr == CurAnimation)
	{
		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다." + _AniamtionName);
		return;
	}
}

void GameEngineRenderer::MainCameraSetting()
{
	Camera = GetActor()->GetLevel()->GetMainCamera();
}

void GameEngineRenderer::UICameraSetting()
{
	Camera = GetActor()->GetLevel()->GetUICamera();
}

void GameEngineRenderer::Start()
{
}

void GameEngineRenderer::SetOrder(int _Order)
{
	if (nullptr == Camera)
	{
		MsgBoxAssert("카메라가 세팅되지 않았는데 오더를 지정했습니다.");
	}

	// 0 => 5번으로 바꾸고 싶다.

	// 오더를 변경하는건 마구잡이로 쓸만한건 아니다. 
	// 0번 랜더 그룹
	// 0번그룹에서는 삭제가 된다.
	std::list<GameEngineRenderer*>& PrevRenders = Camera->Renderers[GetOrder()];
	PrevRenders.remove(this);

	GameEngineObject::SetOrder(_Order);

	std::list<GameEngineRenderer*>& NextRenders = Camera->Renderers[GetOrder()];
	NextRenders.push_back(this);

}