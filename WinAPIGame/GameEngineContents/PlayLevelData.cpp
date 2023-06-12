#include "PlayLevel.h"
#include "BackGround.h"
#include "Obj.h"

void PlayLevel::SetLevelData()
{
	//스테이지별로 차이점 세팅
	static int Stage = 0;
	Stage++;
	StageLevel =  Stage;

	std::vector<TTYPE> TileStartData;
	std::vector<OTYPE> TrapStartData;

	Obj* ObjPtr = nullptr;

	switch (Stage)
	{
	case 1:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0001.bmp");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::PL, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::UN, TTYPE::LO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::UN, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::NP, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,	TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};
		TrapStartData =
		{
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, 
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::KE, OTYPE::NO, OTYPE::NO, OTYPE::NO, 
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, 
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, 
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, 
		};
		TileMapStartData.Init(TileStartData, TrapStartData,{ 9.0f,8.0f }, { 510.0f,120.0f });

		

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 624.0f,270.0f }, 1);
		
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1226.0f,515.0f }, 1);
		
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 519.0f,559.0f }, 0);
		
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 917.0f,160.0f }, 0);

		StartHP = 24;

		break;
	case 2:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0002.bmp");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, 
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::UN, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::RO, TTYPE::RO, TTYPE::RO, TTYPE::WA,
			TTYPE::WA, TTYPE::PL, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NP, TTYPE::NO, TTYPE::UN, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, 
		};
		TrapStartData =
		{
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::SP, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::SP, OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::SP, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 9.0f,8.0f }, { 510.0f,120.0f });

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 615.0f,170.0f }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1125.0f,111.0f }, 0);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1330.0,515.0f }, 1);

		StartHP = 25;

		break;
	case 3:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0003.bmp");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NP, TTYPE::NP, TTYPE::NP, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::LO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::PL, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO,	TTYPE::NO, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,	TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};

		TrapStartData =
		{
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::SP, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::NO, OTYPE::SP, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::SP, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::KE, OTYPE::NO, OTYPE::SP, OTYPE::NO, OTYPE::SP, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,	OTYPE::NO,
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 10.0f,9.0f }, { 460.0f,60.0f });

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 666.0f,565.0f }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1275.0,215.0f }, 1);

		StartHP = 33;

		break;
	case 4:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0004.bmp");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::PL, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::RO, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::LO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::RO, TTYPE::NO, TTYPE::NP, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::RO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};
		TrapStartData =
		{
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::KE, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::SP, OTYPE::SP, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			 	
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 10.0f,7.0f }, { 460.0f,180.0f });

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 670.0f,212.0f }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1075.0f,165.0f }, 0);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1275.0f,170 }, 0);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1375.0,363 }, 1);


		StartHP = 24;

		break;
	case 5:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0005.bmp");

		TileStartData =
		{
			
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NP, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::LO, TTYPE::RO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::PL, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::UN, TTYPE::WA, TTYPE::RO, TTYPE::RO, TTYPE::RO, TTYPE::RO, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};
		TrapStartData =
		{
			
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::SF, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::SF, OTYPE::NO, OTYPE::SF, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, 	OTYPE::SF, OTYPE::NO, OTYPE::SF, OTYPE::NO, OTYPE::NO, OTYPE::SF, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::KE, OTYPE::NO,
			OTYPE::NO, 	OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 8.0f,9.0f }, { 560.0f,60.0f });

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 570,512 }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 770,465 }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1275,613 }, 0);

		StartHP = 24;
		

		break;
	case 6:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0006.bmp");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::PL, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::RO, TTYPE::RO, TTYPE::RO, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::UN, TTYPE::WA, TTYPE::RO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::UN, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::LO, TTYPE::RO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NP, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};
		TrapStartData =
		{
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::KE, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::SF, OTYPE::SF, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 9.0f,10.0f }, { 510.0f,20.0f });

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 613,163 }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1023,261 }, 0);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1127,219 }, 1);

		StartHP = 44;
		break;
	case 7:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0007.bmp");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NP, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::LO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::RO, TTYPE::RO, TTYPE::RO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::UN, TTYPE::RO, TTYPE::NO, TTYPE::UN, TTYPE::RO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::UN, TTYPE::NO, TTYPE::NO, TTYPE::PL, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};
		TrapStartData =
		{
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::KE, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::SO, OTYPE::NO, OTYPE::NO, OTYPE::SF, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::SF, OTYPE::SO, OTYPE::SF, OTYPE::SO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 9.0f,9.0f }, { 460.0f,60.0f });

		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 561,611 }, 1);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1175,112 }, 0);
		ObjPtr = CreateActor<Obj>();
		ObjPtr->Init({ 1281,166 }, 1);

		StartHP = 33;

		break;
	case 8:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterSketches_EXPORT_throne.bmp");

		TileStartData =
		{
			 
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, 
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::NP, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA, 
			TTYPE::WA, TTYPE::NO, TTYPE::UN, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::NO, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::PL, TTYPE::NO, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA
		};
		TrapStartData =
		{
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO,
			OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO, OTYPE::NO
		};
		TileMapStartData.Init(TileStartData, TrapStartData, { 5.0f,15.0f }, { 710.0f,470.0f });
		PlayerCameraFocus = true;
		break;
	default:
		break;
	}
	

}

