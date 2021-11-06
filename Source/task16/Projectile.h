// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Damage.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TASK16_API AProjectile : public AActor, public IDamage
{
	GENERATED_BODY()
	
public:	
	AProjectile();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	virtual void OnDamage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMoveComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
};
