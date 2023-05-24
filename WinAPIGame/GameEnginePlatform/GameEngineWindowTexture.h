#pragma once
#include <string>
#include <Windows.h>
#include <GameEngineBase/GameEngineMath.h>


// Ό³Έν :
class GameEngineWindowTexture
{
	friend class GameEngineWindowPNG;
public:
	// constrcuter destructer
	GameEngineWindowTexture();
	~GameEngineWindowTexture();

	// delete Function
	GameEngineWindowTexture(const GameEngineWindowTexture& _Other) = delete;
	GameEngineWindowTexture(GameEngineWindowTexture&& _Other) noexcept = delete;
	GameEngineWindowTexture& operator=(const GameEngineWindowTexture& _Other) = delete;
	GameEngineWindowTexture& operator=(GameEngineWindowTexture&& _Other) noexcept = delete;

	virtual void ResLoad(const std::string& _Path);
	void ResCreate(HDC  _ImageDC)
	{
		ImageDC = _ImageDC;
		ScaleCheck();
	}

	void ResCreate(const float4& _Scale);


	HDC GetImageDC()
	{
		return ImageDC;
	}

	virtual float4 GetScale();

	void BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos);
	void BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale);

	virtual void TransCopy( const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor = RGB(255, 0, 255), bool _FlipCheck = false);
	
	unsigned int GetColor(unsigned int _DefaultColor, float4 _Pos);

protected:

private:
	HBITMAP BitMap = nullptr;
	HBITMAP OldBitMap = nullptr;
	HDC ImageDC = nullptr;

	BITMAP Info = { 0,0,0 };
	

	void ScaleCheck();
};

