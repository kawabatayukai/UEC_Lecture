// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEC_LectureGameMode.h"
#include "UEC_LectureCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUEC_LectureGameMode::AUEC_LectureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
