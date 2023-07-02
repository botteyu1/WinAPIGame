#include "EndingLevel.h"
#include "LevelChange.h"
#include "DialogEnding.h"
#include "ContentsEnum.h"

EndingLevel::EndingLevel() 
{
}

EndingLevel::~EndingLevel()
{
	
}

void EndingLevel::Start()
{
	EndingLevelChange = CreateActor<LevelChange>();
	EndingDialog = CreateActor<DialogEnding, UpdateOrder>(UpdateOrder::PlayerUI);
}

void EndingLevel::Update(float _DeltaTime)
{
}

