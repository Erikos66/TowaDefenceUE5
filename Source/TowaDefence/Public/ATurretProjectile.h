#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATurretProjectile.generated.h"

class UCapsuleComponent;

UCLASS()
class TOWADEFENCE_API AAProjectile : public AActor
{
	GENERATED_BODY()

public:
	
	AAProjectile();

	virtual void Tick(float DeltaTime) override;

	void SetTarget(AActor* TargetActor);

	void SetDamage(float DamageValue);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float Speed = 500.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float Damage;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	UCapsuleComponent* CollisionCapsule;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY()
	AActor* Target;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
