// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Components/CapsuleComponent.h"
#include "InteractableNPC.generated.h"

/**
 * 
 */
UCLASS()
class UE5_INVEN_DIALOGUE_API AInteractableNPC : public AInteractableActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* MeshComponent;

	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	UCapsuleComponent* CapsuleComponent;

protected:
	AInteractableNPC();
	
};
