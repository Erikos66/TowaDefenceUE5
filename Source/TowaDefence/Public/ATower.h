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
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float AttackTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 CostValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 SellValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 UpgradeCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 CurrentLevel;

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

	UFUNCTION()
	void DetectionRangeOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

	UFUNCTION()
	void DetectionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* 
	OtherComp, int32 OtherBodyIndex);
	
};
