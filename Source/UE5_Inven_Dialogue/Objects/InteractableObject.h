// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "ItemData.h"
#include "InteractableObject.generated.h"

UCLASS()
class UE5_INVEN_DIALOGUE_API AInteractableObject : public AInteractableActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItemData ItemData;
};