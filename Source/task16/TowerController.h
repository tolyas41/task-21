// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TowerController.generated.h"

class ATower;
UCLASS()
class TASK16_API ATowerController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	TSubclassOf<AActor> TargetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxAttackDistance = 600.0f;

private:
	AActor* Target;
	ATower* Tower;
	TArray<AActor*> Enemies;
	float AttackDistance;

	UFUNCTION()
	void Fire();
};
