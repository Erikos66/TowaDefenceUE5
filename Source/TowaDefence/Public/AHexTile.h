#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AHexTile.generated.h"

UCLASS()
class TOWADEFENCE_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	AHexTile();

protected:
	virtual void BeginPlay() override;

public:

	// This part was the easiest, have to make the generator next and that has COMPLICATED math, send halp.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* TileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D AxialCoordinates;

	bool bIsEnemySpawnPoint = false;

	bool bIsBasePoint = false;

	bool bIsPathPoint = false;
};
