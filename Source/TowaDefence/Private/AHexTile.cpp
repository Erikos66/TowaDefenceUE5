﻿#include "AHexTile.h"
#include "Components/StaticMeshComponent.h"

AHexTile::AHexTile()
{
    PrimaryActorTick.bCanEverTick = false;

    HexMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HexMesh"));
    RootComponent = HexMesh;
}

void AHexTile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AHexTile::BeginPlay()
{
    Super::BeginPlay();
    
}
    