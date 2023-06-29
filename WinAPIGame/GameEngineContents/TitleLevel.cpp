#include "TitleLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include "ContentsEnum.h"
#include "DialogTitle.h"
#include "LevelChange.h"
#include <GameEnginePlatform/GameEngineSound.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Start()
{
	
		TitleLevelChange = CreateActor<LevelChange>();
		TitleLevelChange->MainRenderer->Off();
		TitleLevelChange->State = LevelState::Max;

		TitleDialog = CreateActor<DialogTitle, UpdateOrder>(UpdateOrder::PlayerUI);
	if (nullptr == GameEngineSound::FindSound("Apropos.wav"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		
		FilePath.MoveChild("ContentsResources\\Audio\\");
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("Apropos.wav"));
		
	}

}


void TitleLevel::Update(float _DeltaTime)
{
	if (TitleLevelChange->State == LevelState::Transition && TitleLevelChange->CoverFullScreen == true)
	{
		std::string ResetLevel = "PlayLevel1";
		TitleLevelChange->CoverFullScreen = false;
		TitleDialog->ChangeState(DialogState::Off); // 다이얼로그가 켜져있으면 꺼줌
		GameEngineCore::ChangeLevel(ResetLevel);

		Bgm.Stop();
	}

	if (BgmOn == false and TitleDialog->GetDialogState() == DialogState::Conversation)
	{
		Bgm = GameEngineSound::SoundPlay("Apropos.wav");
		BgmOn = true;
	}
	
}