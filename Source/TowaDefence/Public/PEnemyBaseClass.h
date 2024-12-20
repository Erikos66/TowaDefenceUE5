#pragma once

#include "IEnemyMarker.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PEnemyBaseClass.generated.h"

class UStaticMeshComponent;
class UArrowComponent;
class USplineComponent;

UCLASS()
class TOWADEFENCE_API APEnemyBaseClass : public APawn, public IEnemyMarker
{
	GENERATED_BODY()

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Vars")
	UStaticMeshComponent* EnemyMesh;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Vars")
	UArrowComponent* ArrowComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Stats")
	float Health = 10.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Stats")
	float MaxHealth = 10.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Movement")
	float MovementSpeed = 0.5f;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Wave")
	int32 WaveNumber;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy|Movement")
	float SplineProgress;

	UPROPERTY(BlueprintReadOnly, Category = "Enemy|Movement")
	USplineComponent* SplineReference;

	
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	APEnemyBaseClass();

	UFUNCTION(BlueprintCallable, Category = "EnemyFunctions")
	virtual void MarkAsEnemy() override;

	UFUNCTION(BlueprintCallable, Category = "EnemyFunctions")
	virtual void ApplyDamage(float DamageAmount) override;

	// Set the spline reference
	UFUNCTION(BlueprintCallable, Category = "Enemy|Movement")
	void SetSplineReference(USplineComponent* Spline);

protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Enemy|Death")
	virtual void Die();

	UFUNCTION(BlueprintCallable, Category = "Enemy|Movement")
	virtual void MoveAlongSpline(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Enemy|Movement")
	virtual void OnReachGoal();

private:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


};
