#include "CControllerBaseClass.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Ensure we have a valid LocalPlayer.IMC_Selection
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("No LocalPlayer found for this controller."));
		return;
	}

	// Retrieve the Enhanced Input Local Player Subsystem.
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!Subsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("No EnhancedInputLocalPlayerSubsystem found."));
		return;
	}

	// Ensure we have a valid mapping context.
	if (!IMC_Selection)
	{
		UE_LOG(LogTemp, Warning, TEXT("No IMC Assigned!"));
		return;
	}

	// Add the mapping context with a specified priority (0 in this example).
	const int32 Priority = 0;
	Subsystem->AddMappingContext(IMC_Selection, Priority);
}
