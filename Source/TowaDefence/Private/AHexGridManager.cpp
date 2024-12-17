#include "AHexGridManager.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// GENERAL FUNCTIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#if WITH_EDITOR
void AHexGridManager::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    // Regenerate the grid unconditionally
    ClearHexGrid();
    GenerateHexGrid();
}
#endif

void AHexGridManager::Destroyed()
{
    Super::Destroyed();

    // Destroy all spawned hex tile actors
    for (AActor* Tile : HexTileActors)
    {
        if (IsValid(Tile)) // Safe check for a valid, not-destroyed actor
        {
            Tile->Destroy();
        }
    }

    HexTileActors.Empty();
}

AHexGridManager::AHexGridManager()
{
    PrimaryActorTick.bCanEverTick = false;

    // Add a root component for the actor
    USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = RootComp;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// GRID MANAGEMENT
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void AHexGridManager::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    GenerateHexGrid();
}

void AHexGridManager::GenerateHexGrid()
{
    if (!HexTileClass) return;

    FVector GridOrigin = GetActorLocation();

    for (int32 Q = 0; Q < GridWidth; ++Q)
    {
        for (int32 R = 0; R < GridHeight; ++R)
        {
            FVector LocalPosition = CalculateHexPosition(Q, R);
            FVector WorldPosition = GridOrigin + LocalPosition;

            // Spawn a new tile actor
            AActor* NewTile = GetWorld()->SpawnActor<AActor>(HexTileClass, WorldPosition, FRotator(0.0f, 30.0f, 0.0f));
            if (NewTile)
            {
                NewTile->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
                NewTile->SetActorScale3D(FVector(Scale));
                HexTileActors.Add(NewTile);
                NewTile->SetOwner(this);
            }
        }
    }
}

void AHexGridManager::ClearHexGrid()
{
    // Destroy all existing tile actors
    for (AActor* Tile : HexTileActors)
    {
        if (IsValid(Tile)) // Replaced IsPendingKillPending with isValid as it is the preferred method.
        {
            Tile->Destroy();
        }
    }

    HexTileActors.Empty();
}

FVector AHexGridManager::CalculateHexPosition(int32 Q, int32 R) const
{
    const float HexWidth = (BaseHexRadius * 2.0f * Scale) + Offset; // Total width with scaling and padding
    const float HexHeight = (FMath::Sqrt(3.0f) * BaseHexRadius * Scale) + Offset; // Total height with scaling and padding

    // Axial coordinate calculations
    float X = Q * HexWidth * 0.75f; // Horizontal spacing with slight overlap
    float Y = R * HexHeight + ((Q % 2 == 0) ? 0.0f : HexHeight / 2.0f); // Vertical staggering for odd/even rows

    return FVector(X, Y, 0.0f);
}
