// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TowerPlace.generated.h"

class ASomeCharacter;

UCLASS()
class TASK16_API ATowerPlace : public ATriggerBox
{
	GENERATED_BODY()

public:
	ATowerPlace();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnBeginOverlap(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
	void OnEndOverlap(class AActor* OverlappedActor, class AActor* OtherActor);
	ASomeCharacter* PlayerChar;

};
