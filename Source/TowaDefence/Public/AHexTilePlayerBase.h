// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AHexTile.h"
#include "AHexTilePlayerBase.generated.h"

UCLASS()
class TOWADEFENCE_API AAHexTilePlayerBase : public AHexTile
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAHexTilePlayerBase();
	
	virtual void OnTileSelected() override
	{
		UE_LOG(LogTemp, Log, TEXT("This is the player's base."));
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
