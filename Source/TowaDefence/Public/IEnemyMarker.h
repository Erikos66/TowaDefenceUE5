#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEnemyMarker.generated.h"

UINTERFACE(MinimalAPI)
class UEnemyMarker : public UInterface
{
	GENERATED_BODY()
};

// Pure C++ interface
class TOWADEFENCE_API IEnemyMarker
{
	GENERATED_BODY()

public:
	// Define any interface functions here
	virtual void MarkAsEnemy() = 0;

	virtual float GetHealth() const = 0;
};
