#include "PlayLevel.h"
#include "BackGround.h"

void PlayLevel::SetLevelData()
{
	std::vector<TTYPE> TileStartData;
	switch (StageLevel)
	{
	case 1:
		BackGroundPtr = CreateActor<BackGround>();
		BackGroundPtr->Init("chapterBG0002.png");

		TileStartData =
		{
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::KE, TTYPE::PL, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::SP, TTYPE::NO, TTYPE::UN, TTYPE::LO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::SO, TTYPE::UN, TTYPE::NO, TTYPE::UN, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::SF, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::WA, TTYPE::WA,
			TTYPE::WA, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::RO, TTYPE::NO, TTYPE::NO, TTYPE::NP, TTYPE::WA,
			TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,	TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA, TTYPE::WA,
		};
		TileMapStartData.Init(TileStartData, { 9.0f,8.0f }, { 510.0f,120.0f });

	default:
		break;
	}
	

}

