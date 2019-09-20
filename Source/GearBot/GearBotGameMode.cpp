// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GearBotGameMode.h"
#include "GearBotCharacter.h"
#include "CircleMesh.h"
#include "UObject/ConstructorHelpers.h"

AGearBotGameMode::AGearBotGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
