// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "SomeGameMode.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Proj Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileMoveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();	

	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnDamage);
}

void AProjectile::OnDamage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
}

