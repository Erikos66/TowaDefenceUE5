// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBaseClass_C.h"

// Sets default values
ATowerBaseClass_C::ATowerBaseClass_C()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerBaseClass_C::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerBaseClass_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

