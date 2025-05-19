#pragma once

#include "CoreMinimal.h"
#include "UE5_Inven_Dialogue/Objects/ObjectType.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	ObjectType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	UMaterialInstance* MaterialInstance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	int32 Quantity;			

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordingData")
	FVector CameraPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordingData")
	float MaxPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordingData")
	float MinPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordingData")
	float HeightOffset;
};
