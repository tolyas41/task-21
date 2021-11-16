// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SomeFactory.generated.h"

class AUnit;
class ASomeGameMode;

UCLASS()
class TASK16_API ASomeFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	ASomeFactory();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AUnit> UnitToSpawn;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnLocation;

	ASomeGameMode* SomeGameMode;

	UFUNCTION()
	void SpawnUnit();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float SpawnRate{ 1.0f };

};
