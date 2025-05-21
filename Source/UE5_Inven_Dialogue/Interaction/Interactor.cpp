#include "Interactor.h"
#include "Engine/World.h"
#include "UE5_Inven_Dialogue/UE5_Inven_DialogueCharacter.h"
#include "UE5_Inven_Dialogue/Objects/InteractableNPC.h"
#include "UE5_Inven_Dialogue/Objects/InteractableObject.h"

UInteractor::UInteractor()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UInteractor::InteractWithActor()
{
	FHitResult HitResult;
	if(CheckHasLineTraceHit(HitResult))
	{
		AInteractableNPC* NPC = Cast<AInteractableNPC>(HitResult.GetActor());
		AInteractableObject* Object = Cast<AInteractableObject>(HitResult.GetActor());

		if(NPC)
		{
			OnTalkedToNPC.Broadcast(NPC);
		}
		if(Object)
		{
			PickUp(Object);
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Actor Hit"));
	}
}

void UInteractor::PickUp(AInteractableObject* InteractableObject)
{
	if(InteractableObject)
	{
		UE_LOG(LogTemp, Display, TEXT("PickUp Actor: %s"), *InteractableObject->GetActorNameOrLabel());
		AUE5_Inven_DialogueCharacter* Player = Cast<AUE5_Inven_DialogueCharacter>(GetOwner());
		Player->Inventory->AddInventoryItem(InteractableObject);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No object to pick up"));
	}
}

bool UInteractor::CheckHasLineTraceHit(FHitResult& HitResult)
{
	UWorld* World = GetWorld();
	FVector Start = GetComponentLocation();
	FVector End = GetComponentLocation() + GetForwardVector() * MaxInteractDistance;
	
	FCollisionShape Sphere = FCollisionShape::MakeSphere(InteractRadius);
	return World->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity,
	ECC_GameTraceChannel2, Sphere,
	FCollisionQueryParams(), FCollisionResponseParams());
}

