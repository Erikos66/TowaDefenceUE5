#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AHexGridManager.generated.h"

UCLASS()
class TOWADEFENCE_API AHexGridManager : public AActor
{
	GENERATED_BODY()

protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERITES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	TSubclassOf<class AActor> HexTileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	int32 GridWidth = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	int32 GridHeight = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	float Scale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	float Offset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Grid")
	float BaseHexRadius = 100.0f;

private:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	AHexGridManager();
	
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Destroyed() override;
	
	void GenerateHexGrid();
	
	void ClearHexGrid();

	FVector CalculateHexPosition(int32 Q, int32 R) const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERITES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	TArray<AActor*> HexTileActors;

	float PreviousScale = 1.0f;
	
	float PreviousOffset = 0.0f;
	
	int32 PreviousGridWidth = 0;
	
	int32 PreviousGridHeight = 0;
};
