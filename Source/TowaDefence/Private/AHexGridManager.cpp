#include "AHexGridManager.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// GENERAL FUNCTIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
    // Clear existing child components
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

    FVector GridOrigin = GetActorLocation();

    for (int32 Q = 0; Q < GridWidth; ++Q)
    {
        for (int32 R = 0; R < GridHeight; ++R)
        {
            FVector LocalPosition = CalculateHexPosition(Q, R);
            FVector WorldPosition = GridOrigin + LocalPosition;

            UChildActorComponent* NewChildActor = NewObject<UChildActorComponent>(this);
            if (NewChildActor)
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

FVector AHexGridManager::CalculateHexPosition(int32 Q, int32 R) const
{
    const float ScaledRadius = BaseHexRadius * Scale; // Apply scale to the base radius
    const float HexWidth = ScaledRadius * 2.0f + Offset; // Total width including padding
    const float HexHeight = FMath::Sqrt(3.0f) * ScaledRadius + Offset; // Total height including padding

    // Axial coordinate system to Cartesian (handles odd row staggering)
    float X = Q * HexWidth * 0.75f; // Horizontal spacing with overlap
    float Y = R * HexHeight + ((Q % 2 == 0) ? 0.0f : HexHeight / 2.0f); // Vertical staggering for odd rows

    return FVector(X, Y, 0.0f);
}



