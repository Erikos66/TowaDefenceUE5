#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTileTypes.h"
#include "AHexTile.generated.h"

UCLASS()

class TOWADEFENCE_API AHexTile : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Tile")
	UStaticMeshComponent* HexMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Tile")
	bool bCanBeTower = true;
	
	AHexTile();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Tile")
	EHexTileType TileType;

	virtual void OnTileSelected();

protected:
	virtual void BeginPlay() override;
};
