// Fill out your copyright notice in the Description page of Project Settings.

#include "CHPlayerBaseClass.h"

// Sets default values
ACHPlayerBaseClass::ACHPlayerBaseClass()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
void ACHPlayerBaseClass::BeginPlay()
{
	Super::BeginPlay();
}
void ACHPlayerBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ACHPlayerBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

