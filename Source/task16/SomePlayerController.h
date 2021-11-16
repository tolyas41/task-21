// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SomePlayerController.generated.h"

class ASomeCharacter;
class ATower;

UCLASS()
class TASK16_API ASomePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASomePlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* aPawn) override;
	virtual void SetupInputComponent() override;

private:
	ASomeCharacter* Character;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	TSubclassOf<ATower> TowerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int32 TowerCost = 5;

	void Rotate(float Value);
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Fire();
	void Attack();
	void BuildTower();
};
