// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBaseClass_C.h"

// Sets default values
AEnemyBaseClass_C::AEnemyBaseClass_C()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBaseClass_C::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBaseClass_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBaseClass_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

