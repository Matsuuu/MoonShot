// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoonShotGameMode.h"
#include "MoonShotPlayerController.h"
#include "MoonShotCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMoonShotGameMode::AMoonShotGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMoonShotPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}