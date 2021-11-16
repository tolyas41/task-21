// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SomeCharacter.generated.h"

class AProjectile;
class ASomeFactory;
class AHammerCollider;
class UAnimationAsset;

DECLARE_EVENT(ASomeCharacter, FHealEvent)

UCLASS()
class TASK16_API ASomeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASomeCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void StopAnimation();
	UFUNCTION()
	void Fire();
	UFUNCTION()
	void Attack();
	UFUNCTION()
	void GainExperience(float ExpGain);
	UFUNCTION()
	void GainGold(int32 GoldAmount);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Causer")
	TSubclassOf<AProjectile> ProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullets")
	TSubclassOf<AProjectile> CharProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Factory")
	TSubclassOf<ASomeFactory> FactoryClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hammer")
	TSubclassOf<AHammerCollider> HammerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* HammerAttackAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* FireAttackAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* HammerReturnAnimation;
	UPROPERTY()
	AHammerCollider* HammerCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float RotateSpeed = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exp")
	int32 Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exp")
	float ExperienceToLevelUp = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exp")
	float Experience = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exp")
	float ExperienceRate = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gold")
	int32 Gold = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gold")
	int32 GoldRate = 2;

	FHealEvent OnHealEvent;
	FTimerHandle AttackCooldownHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float DamageToApply = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hammer")
	float AttackCooldown = 2.0f;
	bool IsAbleToBuild = false;
	bool IsAttackOnCooldown;

private:
	void CheckProjectile();
	void CheckAttack();
	void AttackOnCooldown();
	void Cooldown();

	bool IsReadyToFire;
	bool IsReadyToAttack;
};
