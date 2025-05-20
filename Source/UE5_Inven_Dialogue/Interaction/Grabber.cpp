// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "UE5_Inven_Dialogue/UE5_Inven_DialogueCharacter.h"
#include "UE5_Inven_Dialogue/Objects/InteractableNPC.h"
#include "UE5_Inven_Dialogue/Objects/InteractableObject.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrabber::InteractWithActor()
{
	FHitResult HitResult;
	if(CheckHasLineTraceHit(HitResult))
	{
		AInteractableNPC* NPC = Cast<AInteractableNPC>(HitResult.GetActor());
		AInteractableObject* Object = Cast<AInteractableObject>(HitResult.GetActor());

		if(NPC)
		{
			TalkToNPC(NPC);
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

void UGrabber::TalkToNPC(AInteractableNPC* InteractableNPC)
{
	if(InteractableNPC)
	{
		UE_LOG(LogTemp, Display, TEXT("Talk to NPC: %s"), *InteractableNPC->GetActorNameOrLabel());
		//AUE5_Inven_DialogueCharacter* Player = Cast<AUE5_Inven_DialogueCharacter>(GetOwner());
		// Display the dialogue UI
	}
}

void UGrabber::PickUp(AInteractableObject* InteractableObject)
{
	if(InteractableObject)
	{
		UE_LOG(LogTemp, Display, TEXT("PickUp Actor: %s"), *InteractableObject->GetActorNameOrLabel());
		AUE5_Inven_DialogueCharacter* Player = Cast<AUE5_Inven_DialogueCharacter>(GetOwner());
		Player->Inventory->AddInventoryItem(InteractableObject);
	}
}

bool UGrabber::CheckHasLineTraceHit(FHitResult& HitResult)
{
	UWorld* World = GetWorld();
	FVector Start = GetComponentLocation();
	FVector End = GetComponentLocation() + GetForwardVector() * MaxGrabDistance;
	
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	return World->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity,
	ECC_GameTraceChannel2, Sphere,
	FCollisionQueryParams(), FCollisionResponseParams());
}

