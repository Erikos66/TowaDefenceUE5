#include "AHexGridManager.h"
#include "Components/ChildActorComponent.h"

AHexGridManager::AHexGridManager()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create a default root component to allow movement
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootComp;
}

void AHexGridManager::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Check if tiles already exist; regenerate only if necessary
	if (HexTileComponents.Num() == 0)
	{
		GenerateHexGrid();
	}
	else
	{
		// Move the entire grid with the manager
		for (UChildActorComponent* TileComponent : HexTileComponents)
		{
			if (TileComponent)
			{
				TileComponent->SetWorldLocation(GetActorLocation() + TileComponent->GetRelativeLocation());
			}
		}
	}
}


void AHexGridManager::GenerateHexGrid()
{
	ClearHexGrid(); // Clear existing tiles

	if (!HexTileClass) return;

	FVector GridOrigin = GetActorLocation(); // Starting position of the grid manager

	for (int32 Q = 0; Q < GridWidth; ++Q)
	{
		for (int32 R = 0; R < GridHeight; ++R)
		{
			FVector LocalPosition = CalculateHexPosition(Q, R);
			FVector WorldPosition = GridOrigin + LocalPosition;

			// Create a new Child Actor Component
			UChildActorComponent* TileComponent = NewObject<UChildActorComponent>(this);
			if (TileComponent)
			{
				TileComponent->SetChildActorClass(HexTileClass);
				TileComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

				TileComponent->RegisterComponent();
				TileComponent->SetWorldLocation(WorldPosition);

				// Rotate the tile 30 degrees on the Z axis to align properly
				TileComponent->SetWorldRotation(FRotator(0.0f, 30.0f, 0.0f));

				TileComponent->SetRelativeScale3D(FVector(Scale));

				HexTileComponents.Add(TileComponent);
			}
		}
	}
}




FVector AHexGridManager::CalculateHexPosition(int32 Q, int32 R) const
{
	const float HexSize = 100.0f; // Base hex radius (distance center to edge)
	const float Padding = Offset; // Extra spacing between tiles

	// Calculate dimensions of the hex tile with padding
	const float HexWidth = (HexSize * 2.0f) + Padding; // Width: 2 * radius + padding
	const float HexHeight = (FMath::Sqrt(3.0f) * HexSize) + Padding; // Height with padding

	// X and Y positions for axial coordinates
	float X = Q * HexWidth * 0.75f;
	float Y = R * HexHeight + ((Q % 2 == 0) ? 0.0f : HexHeight / 2.0f);

	return FVector(X, Y, 0.0f);
}


void AHexGridManager::ClearHexGrid()
{
	for (UChildActorComponent* Component : HexTileComponents)
	{
		if (Component)
		{
			Component->DestroyComponent();
		}
	}

	HexTileComponents.Empty();
}
