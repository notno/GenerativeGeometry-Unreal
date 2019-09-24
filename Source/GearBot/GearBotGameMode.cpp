// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GearBotGameMode.h"
#include "GearBotCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGearBotGameMode::AGearBotGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
