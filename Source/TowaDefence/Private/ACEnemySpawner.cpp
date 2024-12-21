#include "ACEnemySpawner.h"
#include "Components/SplineComponent.h"
#include "PEnemyBaseClass.h"
#include "Engine/World.h"

UEnemySpawnerComponent::UEnemySpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SplineReference = nullptr;
}

void UEnemySpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!SplineReference)
	{
		SplineReference = GetOwner()->FindComponentByClass<USplineComponent>();
	}
}

void UEnemySpawnerComponent::SetSplineReference(USplineComponent* Spline)
{
	SplineReference = Spline;
}

void UEnemySpawnerComponent::SpawnEnemy(TSubclassOf<APEnemyBaseClass> EnemyToSpawn)
{
	if (!EnemyToSpawn || !SplineReference)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot spawn enemy: EnemyToSpawn or SplineReference is invalid."));
		return;
	}

	// Get the starting point of the spline
	FVector SpawnLocation = SplineReference->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);
	FRotator SpawnRotation = SplineReference->GetRotationAtSplinePoint(0, ESplineCoordinateSpace::World);

	// Spawn the selected enemy class
	APEnemyBaseClass* SpawnedEnemy = GetWorld()->SpawnActor<APEnemyBaseClass>(EnemyToSpawn, SpawnLocation, SpawnRotation);
	if (SpawnedEnemy)
	{
		// Pass the spline reference to the spawned enemy
		SpawnedEnemy->SetSplineReference(SplineReference);
	}
}

