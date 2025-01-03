﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATower.generated.h"


class UStaticMeshComponent;
class USphereComponent;

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

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	float CurrentHealth = 10.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	float MaxHealth = 10.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	float Damage = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	float AttackSpeed = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	float AttackRange = 200.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	float RotationSpeed = 10.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	int32 CostValue = 2;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	int32 SellValue = 1;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	int32 UpgradeCost = 5;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	int32 CurrentLevel = 1;

	UPROPERTY(BlueprintReadWrite, Category = "Tower")
	USoundBase* AttackSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Targeting")
	TArray <AActor*> EnemiesInRange;

	UPROPERTY(EditDefaultsOnly, Category = "Tower|Combat")
	TSubclassOf<class AAProjectile> ProjectileClass;

	FTimerHandle FireRateTimerHandle;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	AATower();

	void FireAtEnemy();
	
	void StartFiring();

	void StopFiring();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	void RotateTowardsClosestEnemy();

	UFUNCTION()
	void DetectionRangeOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

	UFUNCTION()
	void DetectionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* 
	OtherComp, int32 OtherBodyIndex);
	
};
