// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UE5_Inven_Dialogue/Objects/InteractableObject.h"
#include "ActorInventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAddedToInventory, FItemData, ItemData);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_INVEN_DIALOGUE_API UActorInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorInventory();

	// Events
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Inventory")
	FOnItemAddedToInventory OnItemAddedToInventory;

protected:
	
	// Inventory Items
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory")
	TMap<int, FItemData> InventoryItems;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	int InventorySize = 4;

public:	
	UFUNCTION(BlueprintCallable)
	TMap<int, FItemData> GetInventoryItems() const { return InventoryItems; }

	UFUNCTION(BlueprintCallable)
	FItemData GetInventoryItemByID(int id) const;

	UFUNCTION(BlueprintCallable)
	void AddInventoryItem(AInteractableObject* OBJ);

	UFUNCTION(BlueprintCallable)
	int GetMaxInventorySize() const {return InventorySize; }

		
};
