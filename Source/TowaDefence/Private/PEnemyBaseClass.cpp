// Fill out your copyright notice in the Description page of Project Settings.


#include "PEnemyBaseClass.h"

// Sets default values
APEnemyBaseClass::APEnemyBaseClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

