// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorInventory.h"

// Sets default values for this component's properties
UActorInventory::UActorInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

FItemData UActorInventory::GetInventoryItemByID(int id) const
{
	if (InventoryItems.Contains(id))
	{
		return InventoryItems[id];
	}
	return FItemData();
}

void UActorInventory::AddInventoryItem(AInteractableObject* OBJ)
{
	if (OBJ)
	{
		for (auto& Item : InventoryItems)
		{
			// There is the same type of object in the inventory
			if(Item.Value.ID == OBJ->ItemData.ID)
			{
				Item.Value.Quantity += OBJ->ItemData.Quantity;
				UE_LOG(LogTemp, Warning, TEXT("Added %s to inventory"), *OBJ->ItemData.ItemName.ToString());
				OnItemAddedToInventory.Broadcast(OBJ->ItemData);
				OBJ->Destroy();
				return;
			}
		}
		// If the object is not in the inventory, add it
		InventoryItems.Add(InventoryItems.Num(), OBJ->ItemData);
		UE_LOG(LogTemp, Warning, TEXT("Added %s to inventory"), *OBJ->ItemData.ItemName.ToString());
		OnItemAddedToInventory.Broadcast(OBJ->ItemData);
		OBJ->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No object to add to inventory"));
	}
}



