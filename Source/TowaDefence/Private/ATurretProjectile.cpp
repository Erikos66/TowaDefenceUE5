#include "ATurretProjectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "PEnemyBaseClass.h"

AAProjectile::AAProjectile(): Target(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionSphere"));
	CollisionCapsule->InitCapsuleSize(10.0f, 10.0f);
	CollisionCapsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionCapsule->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionCapsule->OnComponentBeginOverlap.AddDynamic(this, &AAProjectile::OnOverlapBegin);
	CollisionCapsule->SetupAttachment(RootComponent);


}

void AAProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AAProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target)
	{
		const FVector Direction = (Target->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		SetActorLocation(GetActorLocation() + Direction * Speed * DeltaTime);

		if (FVector::Dist(GetActorLocation(), Target->GetActorLocation()) < 10.0f)
		{
			OnOverlapBegin(nullptr, Target, nullptr, 0, false, FHitResult());
		}
	}
}

void AAProjectile::SetTarget(AActor* TargetActor)
{
	Target = TargetActor;
}

void AAProjectile::SetDamage(const float DamageValue)
{
	Damage = DamageValue;
}

void AAProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->Implements<UEnemyMarker>())
	{
		if (const auto Enemy = Cast<APEnemyBaseClass>(OtherActor))
		{
			Enemy->Health -= Damage;
			if (Enemy->Health <= 0.0f)
			{
				Enemy->Destroy();
			}
		}
		Destroy();
	}
}
