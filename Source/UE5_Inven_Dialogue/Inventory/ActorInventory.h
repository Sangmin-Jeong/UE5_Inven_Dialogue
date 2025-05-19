// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UE5_Inven_Dialogue/Objects/InteractableObject.h"
#include "ActorInventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_INVEN_DIALOGUE_API UActorInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Inventory Items
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	TMap<int, AInteractableObject*> InventoryItems;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	TMap<int, AInteractableObject*> GetInventoryItems() const { return InventoryItems; }

	UFUNCTION(BlueprintCallable)
	AInteractableObject* GetInventoryItemByID(int id) const;

	UFUNCTION(BlueprintCallable)
	void AddInventoryItem(AInteractableObject* OBJ);

		
};
