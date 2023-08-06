// Copyright Epic Games, Inc. All Rights Reserved.

#include "ControlGameMode.h"
#include "ControlCharacter.h"
#include "UObject/ConstructorHelpers.h"

AControlGameMode::AControlGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
