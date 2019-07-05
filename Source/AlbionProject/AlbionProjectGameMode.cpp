// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AlbionProjectGameMode.h"
#include "AlbionProjectPlayerController.h"
#include "AlbionProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAlbionProjectGameMode::AAlbionProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAlbionProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}