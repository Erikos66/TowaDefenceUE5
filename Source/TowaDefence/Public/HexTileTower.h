#pragma once

#include "CoreMinimal.h"
#include "AHexTile.h"
#include "HexTileTower.generated.h"

UCLASS()
class TOWADEFENCE_API AHexTileTower : public AHexTile
{
	GENERATED_BODY()

public:
	virtual void OnTileSelected() override
	{
		UE_LOG(LogTemp, Log, TEXT("Tower can be placed here."));
	}
protected:
	
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};

