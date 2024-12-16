#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AHexGridManager.generated.h"

UCLASS()
class TOWADEFENCE_API AHexGridManager : public AActor
{
	GENERATED_BODY()

public:
	AHexGridManager();

protected:
	virtual void BeginPlay() override;

public:
	// Variables for grid generation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	TSubclassOf<class AHexTile> HexTileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	int32 GridWidth = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	int32 GridHeight = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	float Scale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	float Offset = 10.0f;

	// Overrides
	virtual void OnConstruction(const FTransform& Transform) override;

	// Generate hex grid
	void GenerateHexGrid();

private:
	TArray<AHexTile*> HexTiles;

	FVector CalculateHexPosition(int32 Q, int32 R) const;

	void ClearExistingTiles();
};
