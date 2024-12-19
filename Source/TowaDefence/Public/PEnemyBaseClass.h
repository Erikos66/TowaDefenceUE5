// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IEnemyMarker.h"
#include "GameFramework/Pawn.h"
#include "PEnemyBaseClass.generated.h"

UCLASS()
class TOWADEFENCE_API APEnemyBaseClass : public APawn, public IEnemyMarker
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APEnemyBaseClass();

	virtual void MarkAsEnemy() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
