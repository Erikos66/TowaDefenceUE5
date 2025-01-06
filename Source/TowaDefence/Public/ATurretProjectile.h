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

protected:
	virtual void BeginPlay() override;

private:
};
