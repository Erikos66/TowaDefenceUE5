#include "AHexTile.h"
#include "Components/StaticMeshComponent.h"

AHexTile::AHexTile()
{
	PrimaryActorTick.bCanEverTick = false;

	// Hopefully making this in C++ will be easier to read and understand over the blueprint version.
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	RootComponent = TileMesh;
}

void AHexTile::BeginPlay()
{
	Super::BeginPlay();
}
