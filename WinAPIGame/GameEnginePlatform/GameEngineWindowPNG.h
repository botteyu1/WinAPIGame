#pragma once
#include "GameEngineWindowTexture.h"
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")

// Ό³Έν :
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

	void ResLoadPng(const std::string& _Path);

	float4 GetScale() override;
	

	void TransCopy( const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, bool _FlipCheck, int _TransColor = RGB(255, 0, 255)) override;



protected:

private:
	Gdiplus::Image* Image = nullptr;

};

