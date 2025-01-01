#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PEnemyBaseClass.generated.h"

class UStaticMeshComponent;
class USplineComponent;

UCLASS()
class TOWADEFENCE_API APEnemyBaseClass : public APawn
{
	GENERATED_BODY()

public:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Vars")
	UStaticMeshComponent* EnemyMesh;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Stats")
	float Health = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Stats")
	float MaxHealth = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|Movement")
	float MovementSpeed = 5.0f;

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

private:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// PROPERTIES & VARIABLES
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// FUNCTIONS
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


};
