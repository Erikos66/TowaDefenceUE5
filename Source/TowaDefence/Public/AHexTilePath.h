// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AHexTile.h"
#include "AHexTilePath.generated.h"

UCLASS()
class TOWADEFENCE_API AAHexTilePath : public AHexTile
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAHexTilePath();

	virtual void OnTileSelected() override
	{
		UE_LOG(LogTemp, Log, TEXT("A path can be placed here."));
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
