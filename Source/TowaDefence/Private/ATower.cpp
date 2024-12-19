// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "IEnemyMarker.h"
#include "ATower.h"


AATower::AATower()
{
	PrimaryActorTick.bCanEverTick = true;

	TowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerMesh"));
	RootComponent = TowerMesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Detection Range"));
	CollisionSphere->InitSphereRadius(AttackRange);
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AATower::DetectionRangeOverlapStart);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AATower::DetectionRangeOverlapEnd);
	// Very cool that collision is handled this way in C++, your able to even bind it to its own named function, or multiple!

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);
}
void AATower::BeginPlay()
{
	Super::BeginPlay();
	
}

void AATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateTowardsClosestEnemy(); // Unfortunately for interpolation to work I need to call this every tick, which is not ideal. But necessary.
}

// I just wanted to add, GPT was useless here in helping to implement an overlap, let alone an interface. Had to actually check the documentation to figure this out.

void AATower::DetectionRangeOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Implements<IIEnemyMarker>())
    {
        EnemiesInRange.Add(OtherActor);
    }
}

void AATower::DetectionRangeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->Implements<IIEnemyMarker>()) // This is how C++ handles the "DoesImplementInterface" node, very neat.
    {
        EnemiesInRange.Remove(OtherActor);
    }
}

void AATower::RotateTowardsClosestEnemy()
{
	if (EnemiesInRange.Num() > 0)
	{
		const AActor* ClosestEnemy = EnemiesInRange[0];
		for (const AActor* Enemy : EnemiesInRange)
		{
			if (FVector::Dist(GetActorLocation(), Enemy->GetActorLocation()) < FVector::Dist(GetActorLocation(), ClosestEnemy->GetActorLocation()))
			{
				ClosestEnemy = Enemy;
			}
		}

		// all of this is me copying what i've already done in blueprints and goggling the fuck out of everything trying to work out how to do it. I think this works?
		//TODO: Check if this works..
		
		const FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), ClosestEnemy->GetActorLocation());
		const FRotator LookAtRotationYaw(0.f, LookAtRotation.Yaw, 0.f);
		const FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), LookAtRotationYaw, GetWorld()->GetDeltaSeconds(), RotationSpeed);
		SetActorRotation(NewRotation);
	}
	
}
