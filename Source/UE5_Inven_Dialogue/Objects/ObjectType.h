#pragma once

#include "CoreMinimal.h"
#include "ObjectType.generated.h"

UENUM(BlueprintType)
enum class ObjectType : uint8
{
	Item2D      UMETA(DisplayName = "Item 2D"),
	Item3D		UMETA(DisplayName = "Item 3D")
};
