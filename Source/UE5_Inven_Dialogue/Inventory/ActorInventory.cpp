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

FItemData UActorInventory::GetInventoryItemByID(int id)
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
				UE_LOG(LogTemp, Display, TEXT("%s's Quantity has increased"), *OBJ->ItemData.ItemName.ToString());
				OnItemChangedInventory.Broadcast(OBJ->ItemData);
				OBJ->Destroy();
				return;
			}
		}
		// Check if the inventory is full
		if(InventoryItems.Num() >= InventorySize)
		{
			UE_LOG(LogTemp, Warning, TEXT("Inventory is full"));
			return;
		}
		// If the object is not in the inventory, add it
		InventoryItems.Add(OBJ->ItemData.ID, OBJ->ItemData);
		UE_LOG(LogTemp, Display, TEXT("Added %s to inventory"), *OBJ->ItemData.ItemName.ToString());
		OnItemChangedInventory.Broadcast(OBJ->ItemData);
		OBJ->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No object to add to inventory"));
	}
}

void UActorInventory::Remove2DInventoryItem()
{
	for (auto& Item : InventoryItems)
	{
		if(Item.Value.Type == ObjectType::Item2D)
		{
			FItemData data = Item.Value;
			UE_LOG(LogTemp, Display, TEXT("Removed %s from inventory"), *Item.Value.ItemName.ToString());
			InventoryItems.Remove(Item.Key);
			InventoryItems.Shrink();
			OnItemChangedInventory.Broadcast(data);
			break;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("No 2D object in the inventory"));
}



