// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
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

void UGrabber::PickUp()
{
	FHitResult HitResult;
	if(CheckHasLineTraceHit(HitResult))
	{
		AInteractableObject* InteractableObject = Cast<AInteractableObject>(HitResult.GetActor());
		if(InteractableObject)
		{
			UE_LOG(LogTemp, Display, TEXT("PickUp Actor: %s"), *InteractableObject->GetActorNameOrLabel());
			InteractableObject->Destroy();
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Actor Hit"));
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

