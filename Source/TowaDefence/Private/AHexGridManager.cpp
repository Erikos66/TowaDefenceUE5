#include "AHexGridManager.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// GENERAL FUNCTIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class AHexTile;

AHexGridManager::AHexGridManager()
{
    PrimaryActorTick.bCanEverTick = false;
    
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
    TArray<USceneComponent*> LocalChildren;
    RootComponent->GetChildrenComponents(true, LocalChildren);

    for (USceneComponent* Child : LocalChildren)
    {
        if (UChildActorComponent* ChildActorComp = Cast<UChildActorComponent>(Child))
        {
            ChildActorComp->DestroyComponent();
        }
    }
    HexTileComponents.Empty();

    const FVector GridOrigin = GetActorLocation();
    
    const float ScaledRadius = BaseHexRadius * Scale;
    const float HexWidth = ScaledRadius * 2.0f + Offset;
    const float HexHeight = FMath::Sqrt(3.0f) * ScaledRadius + Offset;

    for (int32 Q = 0; Q < GridWidth; ++Q)
    {
        for (int32 R = 0; R < GridHeight; ++R)
        {
            FVector LocalPosition = CalculateHexPosition(Q, R, HexWidth, HexHeight);
            FVector WorldPosition = GridOrigin + LocalPosition;

            if (UChildActorComponent* NewChildActor = NewObject<UChildActorComponent>(this))
            {
                NewChildActor->SetChildActorClass(HexTileClass);
                NewChildActor->RegisterComponent();
                NewChildActor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
                NewChildActor->SetRelativeLocation(WorldPosition - GridOrigin);
                NewChildActor->SetRelativeRotation(FRotator(0.0f, 30.0f, 0.0f));
                NewChildActor->SetRelativeScale3D(FVector(Scale, Scale, Scale));

                HexTileComponents.Add(NewChildActor);
            }
        }
    }
}

FVector AHexGridManager::CalculateHexPosition(int32 const Q, int32 const R, float const HexWidth, float const HexHeight)
{
    const float X = Q * HexWidth * 0.75f;
    const float Y = R * HexHeight + ((Q % 2 == 0) ? 0.0f : HexHeight / 2.0f);

    return FVector(X, Y, 0.0f);
}

TArray<UChildActorComponent*> AHexGridManager::GetEdgeTiles() const
{
    TArray<UChildActorComponent*> EdgeTiles;

    EdgeTiles.Empty();

    for (int32 Q = 0; Q < GridWidth; ++Q)
    {
        for (int32 R = 0; R < GridHeight; ++R)
        {
            if (Q == 0 || Q == GridWidth - 1 || R == 0 || R == GridHeight - 1)
            {
                if (const int32 Index = Q * GridHeight + R; HexTileComponents.IsValidIndex(Index))
                {
                    EdgeTiles.Add(HexTileComponents[Index].Get());
                }
            }
        }
    }

    return EdgeTiles;
}

void AHexGridManager::GenerateEnemySpawnPoints() const
{
    TArray<UChildActorComponent*> EdgeTiles = GetEdgeTiles();
    TArray<UChildActorComponent*> ListOfEnemySpawns;

    for (int32 i = 0; i < NumEnemySpawnPoints && EdgeTiles.Num() > 0; ++i)
    {
        const int32 RandomIndex = FMath::RandRange(0, EdgeTiles.Num() - 1);
        ListOfEnemySpawns.Add(EdgeTiles[RandomIndex]);
        EdgeTiles.RemoveAt(RandomIndex);
    }
}
