#include "ACEnemySpawner.h"

UEnemySpawnerComponent::UEnemySpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemySpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
}

