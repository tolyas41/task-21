// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TriggerGate.generated.h"

class AUnit;
class ASomeGameMode;
class ASomeGameState;
class ASomeItem;
UCLASS()
class TASK16_API ATriggerGate : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ATriggerGate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AUnit> UnitTD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ASomeItem> TreasureItem;

	ASomeGameMode* SomeGameMode;
	ASomeGameState* SomeGameState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TreasureExperience;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor);

};
