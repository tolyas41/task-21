// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Damage.h"
#include "HammerCollider.generated.h"

DECLARE_EVENT(AHammerCollider, FOnHammerHitEvent)


class UCapsuleComponent;
UCLASS()
class TASK16_API AHammerCollider : public AActor, public IDamage
{
	GENERATED_BODY()
	
public:	
	AHammerCollider();

	UFUNCTION()
	virtual void OnDamage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) override;
	UFUNCTION()
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	FOnHammerHitEvent OnHammerHitEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* HammerCapsule;
};
