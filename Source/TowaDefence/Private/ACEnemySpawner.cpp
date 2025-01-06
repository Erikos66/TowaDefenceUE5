#include "ACEnemySpawner.h"
#include "Components/SplineComponent.h"
#include "PEnemyBaseClass.h"
#include "Engine/World.h"

UEnemySpawnerComponent::UEnemySpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemySpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
}

