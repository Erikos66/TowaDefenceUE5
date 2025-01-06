#include "PEnemyBaseClass.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SplineComponent.h"




APEnemyBaseClass::APEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

void APEnemyBaseClass::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}