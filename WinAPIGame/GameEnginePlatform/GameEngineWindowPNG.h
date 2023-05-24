#pragma once
#include "GameEngineWindowTexture.h"
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")

// 설명 :
// 현재 png로는 CreateSpriteSheet, 픽셀충돌이 불가능하다.

class GameEngineWindowPNG : public GameEngineWindowTexture
{
public:
	// constrcuter destructer
	GameEngineWindowPNG();
	~GameEngineWindowPNG();

	// delete Function
	GameEngineWindowPNG(const GameEngineWindowPNG& _Other) = delete;
	GameEngineWindowPNG(GameEngineWindowPNG&& _Other) noexcept = delete;
	GameEngineWindowPNG& operator=(const GameEngineWindowPNG& _Other) = delete;
	GameEngineWindowPNG& operator=(GameEngineWindowPNG&& _Other) noexcept = delete;

	void ResLoad(const std::string& _Path) override;

	float4 GetScale() override;
	

	void TransCopy( const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor = RGB(255, 0, 255) , bool _FlipCheck = false) override;



protected:

private:
	Gdiplus::Image* Image = nullptr;

};

