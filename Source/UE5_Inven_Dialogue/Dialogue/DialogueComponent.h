// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_INVEN_DIALOGUE_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDialogueComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dialogue")
	TArray<FString> DialogueList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dialogue")
	int CurrentDialogueIndex;

	// UFUNCTION(BlueprintCallable, Category="Dialogue")
	// void SetCurrentDialogue() {CurrentDialogue = DialogueMap[DialogueID];}
	//
	// UFUNCTION(BlueprintCallable, Category="Dialogue")
	// FString GetDialogueString(int DialogueID) {return DialogueMap[DialogueID];}

private:
	// void InitDialogueMap();
};
