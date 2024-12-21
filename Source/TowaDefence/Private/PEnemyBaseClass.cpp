#include "PEnemyBaseClass.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SplineComponent.h"




APEnemyBaseClass::APEnemyBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;

	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	RootComponent = EnemyMesh;
}

void APEnemyBaseClass::MarkAsEnemy()
{
	
}

void APEnemyBaseClass::SetSplineReference(USplineComponent* Spline)
{
	SplineReference = Spline;
}

void APEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("An Enemy has Spawned!"));
}

void APEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveAlongSpline(DeltaTime);
}

void APEnemyBaseClass::ApplyDamage(float const DamageAmount)
{
	// Reduce the health by the damage amount
	Health -= DamageAmount;

	// Clamp health to ensure it doesn't go below 0
	Health = FMath::Clamp(Health, 0.0f, MaxHealth);

	// Debug message
	UE_LOG(LogTemp, Log, TEXT("%s took %f damage. Remaining Health: %f"), *GetName(), DamageAmount, Health);

	// Check if the enemy is dead
	if (Health <= 0.0f)
	{
		// Handle death
		UE_LOG(LogTemp, Log, TEXT("%s has been destroyed!"), *GetName());
		Die();
	}
}

void APEnemyBaseClass::Die()
{
	Destroy();
}

void APEnemyBaseClass::MoveAlongSpline(float const DeltaTime)
{
	if (SplineReference)
	{
		// Update the progress along the spline
		SplineProgress += (MovementSpeed * DeltaTime) / SplineReference->GetSplineLength();

		// Clamp progress to ensure it doesn't exceed 1.0
		SplineProgress = FMath::Clamp(SplineProgress, 0.0f, 1.0f);

		// Move the enemy along the spline
		FVector NewLocation = SplineReference->GetLocationAtTime(SplineProgress, ESplineCoordinateSpace::World);
		FRotator NewRotation = SplineReference->GetRotationAtTime(SplineProgress, ESplineCoordinateSpace::World);

		SetActorLocationAndRotation(NewLocation, NewRotation);

		// Check if the enemy has reached the end of the spline
		if (SplineProgress >= 1.0f)
		{
			// Handle reaching the goal
			Destroy(); // Or call a custom goal-handling function
		}
	}
}