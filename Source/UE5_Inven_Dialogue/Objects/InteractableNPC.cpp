#include "InteractableNPC.h"

AInteractableNPC::AInteractableNPC()
{
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	RootComponent = MeshComponent;
	MeshComponent->bCastDynamicShadow = false;
	MeshComponent->CastShadow = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetupAttachment(MeshComponent);

	DialogueComponent = CreateDefaultSubobject<UDialogueComponent>(TEXT("DialogueComponent"));
	
}
