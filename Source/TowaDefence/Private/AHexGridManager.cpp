#include "AHexGridManager.h"
#include "AHexTile.h"

AHexGridManager::AHexGridManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();
	GenerateHexGrid();
}

void AHexGridManager::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Generate grid in editor
	GenerateHexGrid();
}

void AHexGridManager::GenerateHexGrid()
{
	if (!HexTileClass) return;

	// Clear any previously spawned tiles
	ClearExistingTiles();

	for (int32 Q = 0; Q < GridWidth; ++Q)
	{
		for (int32 R = 0; R < GridHeight; ++R)
		{
			FVector Position = CalculateHexPosition(Q, R);

			// Spawn the hex tile
			AHexTile* NewTile = GetWorld()->SpawnActor<AHexTile>(HexTileClass, Position, FRotator::ZeroRotator);
			if (NewTile)
			{
				// Set the axial coordinates
				NewTile->AxialCoordinates = FVector2D(Q, R);

				// Apply the scale to the hex tile's mesh
				NewTile->SetActorScale3D(FVector(Scale));

				HexTiles.Add(NewTile);
			}
		}
	}
}

FVector AHexGridManager::CalculateHexPosition(int32 Q, int32 R) const
{
	const float BaseHexWidth = 100.f;  // Base size of your hex mesh width
	const float BaseHexHeight = 86.6f; // Base size of your hex mesh height

	// Apply scale and offset
	const float HexWidth = BaseHexWidth * Scale + Offset;
	const float HexHeight = BaseHexHeight * Scale + Offset;

	float X = HexWidth * 0.75f * Q;
	float Y = HexHeight * (R + 0.5f * (Q % 2));
	return FVector(X, Y, 0.f);
}

void AHexGridManager::ClearExistingTiles()
{
	for (AHexTile* Tile : HexTiles)
	{
		if (Tile && !Tile->IsPendingKillPending())
		{
			Tile->Destroy();
		}
	}

	HexTiles.Empty();
}
