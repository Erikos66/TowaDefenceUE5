// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnPoint_C.h"

// Sets default values
AEnemySpawnPoint_C::AEnemySpawnPoint_C()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawnPoint_C::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawnPoint_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

