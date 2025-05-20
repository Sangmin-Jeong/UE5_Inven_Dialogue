// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Components/CapsuleComponent.h"
#include "UE5_Inven_Dialogue/Dialogue/DialogueComponent.h"
#include "InteractableNPC.generated.h"

/**
 * 
 */
UCLASS()
class UE5_INVEN_DIALOGUE_API AInteractableNPC : public AInteractableActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category="Component")
	USkeletalMeshComponent* MeshComponent;

	UPROPERTY(VisibleDefaultsOnly, Category="Component")
	UCapsuleComponent* CapsuleComponent;

protected:
	AInteractableNPC();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	UDialogueComponent* DialogueComponent;
	
	
};
