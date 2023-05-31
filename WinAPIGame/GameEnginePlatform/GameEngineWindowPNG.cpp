#include "GameEngineWindowPNG.h"
#include "GameEngineWindow.h"
#include <GameEngineBase/GameEngineDebug.h>


ULONG_PTR GameEngineWindowPNG::Token;
Gdiplus::GdiplusStartupInput GameEngineWindowPNG::Input;


class GDIPlusInit
{
public:
	GDIPlusInit()
	{
		Gdiplus::Status Result = Gdiplus::GdiplusStartup(&GameEngineWindowPNG::Token, &GameEngineWindowPNG::Input, nullptr);

		if (Result != Gdiplus::Status::Ok)
		{
			int a = 0;
		}
	}
	~GDIPlusInit()
	{
		Gdiplus::GdiplusShutdown(GameEngineWindowPNG::Token);
	}
};

GDIPlusInit InitInstance;

/////////////////////// GIDPLUSInit

GameEngineWindowPNG::GameEngineWindowPNG() 
{
}

GameEngineWindowPNG::~GameEngineWindowPNG()
{
}

void GameEngineWindowPNG::ResLoad(const std::string& _Path) 
{



	std::wstring wPath;
	wPath.assign(_Path.begin(), _Path.end());
	Image = Gdiplus::Image::FromFile(wPath.c_str());
	
	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	HDC BackBufferImageDC = BackBuffer->GetImageDC();

	graphics = new Gdiplus::Graphics(BackBufferImageDC);



	ScaleCheck();
}

float4 GameEngineWindowPNG::GetScale()
{
	
	return float4(static_cast<float>(Image->GetWidth()), static_cast<float>(Image->GetHeight()));
	
}

void GameEngineWindowPNG::TransCopy(const float4& _Pos, 
	const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor /*= RGB(255, 0, 255)*/, bool _FlipCheck/* = false*/)
{

	//GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	//HDC BackBufferImageDC = BackBuffer->GetImageDC();

	if (true == _FlipCheck)
	{
		//Gdiplus::Graphics g(BackBufferImageDC);

		graphics->DrawImage(Image,
			_Pos.iX() + _Scale.ihX(),
			_Pos.iY() - _Scale.ihY(),
			- _Scale.iX(),
			 _Scale.iY());
	}
	else
	{
		//Gdiplus::Graphics g(BackBufferImageDC);
		graphics->DrawImage(Image,
			_Pos.iX() - _Scale.ihX(),
			_Pos.iY() - _Scale.ihY());
	}
}

