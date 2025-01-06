#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACEnemySpawner.generated.h"

class USplineComponent;
class APEnemyBaseClass;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TOWADEFENCE_API UEnemySpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemySpawnerComponent();

protected:
	virtual void BeginPlay() override;
};
