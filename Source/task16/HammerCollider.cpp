// Fill out your copyright notice in the Description page of Project Settings.

#include "HammerCollider.h"
#include "Components/CapsuleComponent.h"

AHammerCollider::AHammerCollider()
{
	HammerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Hammer Collider"));
	SetRootComponent(HammerCapsule);
	HammerCapsule->SetCapsuleRadius(30.0f);
	HammerCapsule->SetCapsuleHalfHeight(30.0f);

	HammerCapsule->OnComponentHit.AddDynamic(this, &AHammerCollider::OnDamage);

}

void AHammerCollider::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	OnHammerHitEvent.Broadcast();
}

void AHammerCollider::OnDamage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	SetActorEnableCollision(false);
}
