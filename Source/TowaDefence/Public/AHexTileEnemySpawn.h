// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AHexTile.h"
#include "AHexTileEnemySpawn.generated.h"

UCLASS()
class TOWADEFENCE_API AAHexTileEnemySpawn : public AHexTile
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAHexTileEnemySpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
