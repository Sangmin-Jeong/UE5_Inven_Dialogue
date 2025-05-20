#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interactor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTalkedToNPC, AInteractableNPC*, InteractableNPC);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_INVEN_DIALOGUE_API UInteractor : public USceneComponent
{
	GENERATED_BODY()

public:
	UInteractor();

	UFUNCTION(BlueprintCallable)
	void InteractWithActor();
	
	UFUNCTION(BlueprintCallable)
	void PickUp(AInteractableObject* InteractableObject);

	// Events
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Dialogue")
	FOnTalkedToNPC OnTalkedToNPC;
	
private:
	UPROPERTY(EditAnywhere)
	float MaxInteractDistance = 400.f;

	UPROPERTY(EditAnywhere)
	float InteractRadius = 50.f;
	
	bool CheckHasLineTraceHit(FHitResult& HitResult);
};
