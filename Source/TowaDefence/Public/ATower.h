// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATower.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UArrowComponent;

UCLASS()
class TOWADEFENCE_API AATower : public AActor
{
	GENERATED_BODY()

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	UStaticMeshComponent* TowerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	USphereComponent* CollisionSphere;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	UArrowComponent* ArrowComponent;

	float CurrentHealth;
	float MaxHealth;
	float Damage;
	float AttackSpeed;
	float AttackRange;
	float AttackTimer;
	float RotationSpeed;
	int32 CostValue;
	int32 SellValue;
	int32 UpgradeCost;
	int32 CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	TArray<AActor*> TargetArray;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	AATower();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
