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

void AHexTile::HighlightTile(bool bIsHighlighted)
{

	// Not entirely sure what this does, but it will be interesting to find out.
	//TODO: Find out what this does.
	TileMesh->SetRenderCustomDepth(bIsHighlighted);
	
}
