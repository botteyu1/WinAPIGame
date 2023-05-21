#include "GameEngineWindowPNG.h"
#include "GameEngineWindow.h"

GameEngineWindowPNG::GameEngineWindowPNG() 
{
}

GameEngineWindowPNG::~GameEngineWindowPNG()
{
}

void GameEngineWindowPNG::ResLoadPng(const std::string& _Path)
{

	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	std::wstring wPath;
	wPath.assign(_Path.begin(), _Path.end());
	Image = Gdiplus::Image::FromFile(wPath.c_str());
	//Gdiplus::Graphics g(ImageDC);
	//g.DrawImage(Image, 0, 0);
}

void GameEngineWindowPNG::TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, bool _FlipCheck, int _TransColor)
{
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	HDC CopyImageDC = _CopyTexture->GetImageDC();
	HDC BackBufferImageDC = BackBuffer->GetImageDC();

	Gdiplus::Graphics g(BackBufferImageDC);
	g.DrawImage(Image, 
		_Pos.iX() - 1920,
		_Pos.iY() -1080,
		1920,
		1080);
}

