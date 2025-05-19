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


// Called when the game starts
void UActorInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActorInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AInteractableObject* UActorInventory::GetInventoryItemByID(int id) const
{
	if (InventoryItems.Contains(id))
	{
		return InventoryItems[id];
	}
	return nullptr;
}

void UActorInventory::AddInventoryItem(AInteractableObject* OBJ)
{
	if (OBJ)
	{
		for (const auto& Item : InventoryItems)
		{
			// There is the same type of object in the inventory
			if(Item.Value->ID == OBJ->ID)
			{
				Item.Value->Amount += OBJ->Amount;
				UE_LOG(LogTemp, Warning, TEXT("Added %s to inventory"), *OBJ->ObjectName);
				OBJ->Destroy();
				return;
			}
		}
		// If the object is not in the inventory, add it
		InventoryItems.Add(InventoryItems.Num(), OBJ);
		UE_LOG(LogTemp, Warning, TEXT("Added %s to inventory"), *OBJ->ObjectName);
		OBJ->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No object to add to inventory"));
	}
}



