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

	void GenerateHexGrid();

private:
	TArray<UChildActorComponent*> HexTileComponents;

	FVector CalculateHexPosition(int32 Q, int32 R) const;
	void ClearHexGrid();
};
