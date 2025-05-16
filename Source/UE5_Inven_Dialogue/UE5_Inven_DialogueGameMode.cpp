// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_Inven_DialogueGameMode.h"
#include "UE5_Inven_DialogueCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_Inven_DialogueGameMode::AUE5_Inven_DialogueGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
