// Fill out your copyright notice in the Description page of Project Settings.

#include "ATower.h"
#include "Components/StaticMeshComponent.h"


AATower::AATower()
{
	PrimaryActorTick.bCanEverTick = true;
	// Very cool that collision is handled this way in C++, your able to even bind it to its own named function, or multiple!
}

void AATower::BeginPlay()
{
	Super::BeginPlay();
}

void AATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// I just wanted to add, GPT was useless here in helping to implement an overlap, let alone an interface. Had to actually check the documentation to figure this out.