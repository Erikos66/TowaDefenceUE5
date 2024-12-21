#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACEnemySpawner.generated.h"

class USplineComponent;
class APEnemyBaseClass;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TOWADEFENCE_API UEnemySpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemySpawnerComponent();

	// Reference to the spline component for the enemy path
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
	USplineComponent* SplineReference;

	// Enemy class to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<APEnemyBaseClass> EnemyClass;

	// Function to spawn an enemy and pass the spline reference
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnEnemy(TSubclassOf<APEnemyBaseClass> EnemyToSpawn);


	// Setter function for the spline reference
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetSplineReference(USplineComponent* Spline);

protected:
	virtual void BeginPlay() override;
};
