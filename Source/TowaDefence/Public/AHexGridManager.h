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
	virtual void OnConstruction(const FTransform& Transform) override;

public:
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
	TArray<AActor*> HexTileActors;

	void GenerateHexGrid();
	void ClearHexGrid();
	FVector CalculateHexPosition(int32 Q, int32 R) const;

	float PreviousScale = 1.0f;
	float PreviousOffset = 0.0f;
	int32 PreviousGridWidth = 0;
	int32 PreviousGridHeight = 0;
	
	bool HasGridParametersChanged() const;
};
