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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float CurrentHealth = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float MaxHealth = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float Damage = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float AttackSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float AttackRange = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float RotationSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 CostValue = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 SellValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 UpgradeCost = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 CurrentLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	USoundBase* AttackSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Targeting")
	TArray <AActor*> EnemiesInRange;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	AATower();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	void RotateTowardsClosestEnemy();

	UFUNCTION()
	void DetectionRangeOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

	UFUNCTION()
	void DetectionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* 
	OtherComp, int32 OtherBodyIndex);
	
};
