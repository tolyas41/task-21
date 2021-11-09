// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SomeGameState.generated.h"

UCLASS()
class TASK16_API ASomeGameState : public AGameStateBase
{

	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	void LooseHealth();
	int32 GetHealth();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LooseCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Health = 5;


};
