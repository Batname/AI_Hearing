// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AI_HearingGameMode.h"
#include "AI_HearingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_HearingGameMode::AAI_HearingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
