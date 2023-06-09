#pragma once
#include "GameEngineActorSubObject.h"
#include <GameEngineBase/GameEngineMath.h>
#include <string>
#include <map>
#include <vector>

enum class CameraType
{
	MAIN,
	UI,
};

// 설명 :
class GameEngineSprite;
class GameEngineActor;
class GameEngineWindowTexture;
class GameEngineRenderer : public GameEngineActorSubObject
{
	friend class GameEngineCamera;
	friend class GameEngineActor;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	void SetAngle(float _Angle);

	void SetAlpha(unsigned char _Alpha);


	void AddAlpha(unsigned char _Alpha);

	void AddAngle(float _Angle);


	void SetSprite(const std::string& _Name, size_t _Index = 0);

	void SetTexture(const std::string& _Name);

	void SetMaskTexture(const std::string& _Name);

	void SetRenderPos(const float4& _Value)
	{
		RenderPos = _Value;
		//int a = 0;
	}
	void SetRenderScale(const float4& _Value)
	{
		RenderScale = _Value;
		ScaleCheck = true;
	}
	void AddRenderScale(const float4& _Value)
	{
		RenderScale += _Value;
		ScaleCheck = true;
	}

	void SetCopyPos(const float4& _Value)
	{
		CopyPos = _Value;
	}

	void SetCopyScale(const float4& _Value)
	{
		CopyScale = _Value;
	}

	void SetScaleRatio(const float& _Scale)
	{
		ScaleRatio = _Scale;
	}

	float4 GetRenderPos()
	{
		return RenderPos;
	}

	float4 GetRenderScale()
	{
		return RenderScale;
	}
	float4 GetCopyPos()
	{
		return CopyPos;
	}

	float4 GetCopyScale()
	{
		return CopyScale;
	}

	CameraType GetCameraType()
	{
		return CameraTypeValue;
	}

	void AddRenderPos(const float4& _Value)
	{
		RenderPos += _Value;
	}


	void SetRenderScaleToTexture();

	void SetOrder(int _Order) override;


	void Flip()
	{
		FlipCheck = !FlipCheck;
	}
	void FlipON()
	{
		FlipCheck = true;
	}
	void FlipOFF()
	{
		FlipCheck = false;
	}

protected:
	void Start() override;

private:
	GameEngineCamera* Camera = nullptr;
	GameEngineWindowTexture* Texture = nullptr;

	GameEngineWindowTexture* MaskTexture = nullptr;

	GameEngineSprite* Sprite = nullptr;
	float ScaleRatio = 1.0f;
	bool FlipCheck = false;
	bool ScaleCheck = false;

	float4 RenderPos; //객체와 렌더사이의 거리값
	float4 RenderScale;

	float4 CopyPos; // 이미지의 위치값
	float4 CopyScale;
	CameraType CameraTypeValue = CameraType::MAIN;
	std::string Text;

	float Angle = 0.0f;
	unsigned char Alpha = 255;

	void TextRender(float _DeltaTime);

	void Render(float _DeltaTime);


private:
	class Animation
	{
	public:
		std::string Name = "";
		GameEngineSprite* Sprite = nullptr;
		size_t CurFrame = 0;
		size_t StartFrame = -1;
		size_t EndFrame = -1;
		float CurInter = 0.0f;
		std::vector<size_t> Frames;
		std::vector<float> Inters;
		bool Loop = true;
		bool IsEnd = false;
		 
	};

public:
	Animation* FindAnimation(const std::string& _AniamtionName);

	/// <summary>
	/// 애니메이션 생성함수
	/// </summary>
	/// <param name="_AniamtionName">애니메이션 이름</param>
	/// <param name="_SpriteName">스프라이트 이름</param>
	/// <param name="_Start">시작 프레임</param>
	/// <param name="_End">끝 프레임</param>
	/// <param name="_Inter">애니메이션 시간</param>
	/// <param name="_Loop">애니메이션 반복</param>
	void CreateAnimation(
		const std::string& _AniamtionName,
		const std::string& _SpriteName,
		size_t _Start = -1, size_t _End = -1,
		float _Inter = 0.1f,
		bool _Loop = true);

	void ChangeAnimation(const std::string& _AniamtionName, bool _ForceChange = false);
	void CreateAnimationToFrame(
		const std::string& _AniamtionName,
		const std::string& _SpriteName,
		const std::vector<size_t>& _Frame,
		float _Inter = 0.1f,
		bool _Loop = true);

	void MainCameraSetting();
	void UICameraSetting();

	//void Update(float _Delta) override;

	int GetCurFrame()
	{
		return static_cast<int>(CurAnimation->CurFrame);
	}
	 
	void SetCurFrame(size_t _Frame)
	{
		CurAnimation->IsEnd = false;
		CurAnimation->CurFrame = _Frame;
	}

	bool IsAnimationEnd()
	{
		return CurAnimation->IsEnd;
	}

	void AnimationEndOff()
	{
		IsAnimationEndOff = true;
	}

	bool IsAnimation(const std::string& _Name)
	{
		return CurAnimation->Name == _Name;
	}

private:
	std::map<std::string, Animation> AllAnimation;
	Animation* CurAnimation = nullptr;
	bool IsAnimationEndOff= false;//애니메이션이 끝날때 렌더러를 끌지 여부.
	

	/////////////////////////////////// Text관련
public:
	void SetText(const std::string& _Text, int _TextScale = 20, const std::string& _Face = "굴림", unsigned int _TextColor = RGB(255, 255, 255), int _TextSize = 50)
	{
		Text = _Text;
		TextScale = _TextScale;
		TextSize = _TextSize;
		TextColor = _TextColor;
		Face = _Face;
	}

private:
	std::string Face;
	int TextScale;
	int TextSize;
	unsigned int TextColor = RGB(255, 255, 255);
};