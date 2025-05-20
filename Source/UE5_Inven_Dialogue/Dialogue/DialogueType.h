#pragma once

#include "CoreMinimal.h"
#include "DialogueType.generated.h"

UENUM(BlueprintType)
enum class DialogueType : uint8
{
	Intro			UMETA(DisplayName = "Intro"),
	Info			UMETA(DisplayName = "Info"),
	Tutorial		UMETA(DisplayName = "Tutorial"),
	General			UMETA(DisplayName = "General"),
};
