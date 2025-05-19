#pragma once

#include "Components/Image.h"
#include "ObjectType.h"
#include "CoreMinimal.h"
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
	UTexture2D* ItemTexture;
	
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
