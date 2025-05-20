#include "DialogueComponent.h"

UDialogueComponent::UDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// InitDialogueMap();
}

// void UDialogueComponent::InitDialogueMap()
// {
// 	DialogueMap.Add(0, TEXT("Hello! How are you? My name is Sangmin who develops this game."));
// 	DialogueMap.Add(1, TEXT("I will explain how to test out and what the key points are in this game."));
// 	DialogueMap.Add(2, TEXT("Are you ready to hear my explanation?"));
// 	DialogueMap.Add(3, TEXT("You already noticed that you can interact with me pressing the 'E' key."));
// 	DialogueMap.Add(4, TEXT("The 'E' key can be used to interact with any object in the game."));
// 	DialogueMap.Add(5, TEXT("Also, you can open the inventory by pressing the 'I' key."));
// 	DialogueMap.Add(6, TEXT("The \"W, A, S, D\" keys are used to move around the world."));
// 	DialogueMap.Add(7, TEXT("Are you feeling bored already?"));
//
// 	DialogueMap.Add(8, TEXT("Let's move on to the key points of this game."));
// }


