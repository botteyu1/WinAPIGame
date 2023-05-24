#include "GameEngineWindowPNG.h"
#include "GameEngineWindow.h"
#include <GameEngineBase/GameEngineDebug.h>




GameEngineWindowPNG::GameEngineWindowPNG() 
{
}

GameEngineWindowPNG::~GameEngineWindowPNG()
{
}

void GameEngineWindowPNG::ResLoad(const std::string& _Path) 
{

	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	std::wstring wPath;
	wPath.assign(_Path.begin(), _Path.end());
	Image = Gdiplus::Image::FromFile(wPath.c_str());
	

	ScaleCheck();
}

float4 GameEngineWindowPNG::GetScale()
{
	
	return float4(static_cast<float>(Image->GetWidth()), static_cast<float>(Image->GetHeight()));
	
}

void GameEngineWindowPNG::TransCopy(const float4& _Pos, 
	const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor /*= RGB(255, 0, 255)*/, bool _FlipCheck/* = false*/)
{
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	HDC BackBufferImageDC = BackBuffer->GetImageDC();

	if (true == _FlipCheck)
	{
		Gdiplus::Graphics g(BackBufferImageDC);
		g.DrawImage(Image,
			_Pos.iX() + _Scale.ihX(),
			_Pos.iY() - _Scale.ihY(),
			- _Scale.iX(),
			 _Scale.iY());
	}
	else
	{
		Gdiplus::Graphics g(BackBufferImageDC);
		g.DrawImage(Image,
			_Pos.iX() - _Scale.ihX(),
			_Pos.iY() - _Scale.ihY(),
			_Scale.iX(),
			_Scale.iY());
	}
	
}

