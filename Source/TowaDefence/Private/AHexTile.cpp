#include "AHexTile.h"

AHexTile::AHexTile()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHexTile::BeginPlay()
{
	Super::BeginPlay();
}

void AHexTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexTile::OnTileSelected()
{
	UE_LOG(LogTemp, Log, TEXT("Base Hex Tile Selected"));
}
