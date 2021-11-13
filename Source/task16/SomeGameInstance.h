// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SomeGameInstance.generated.h"

DECLARE_EVENT(USomeGameInstance, FOnLooseEvent)
DECLARE_EVENT(USomeGameInstance, FTransferParams)

UCLASS()
class TASK16_API USomeGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	FOnLooseEvent OnLooseEvent;
	FTransferParams TransferParams;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LooseCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayerExperience;

	UFUNCTION()
	int32 GetLooseCount();
	UFUNCTION()
	float GetPlayerExperience();

private:
	UFUNCTION()
	void Transfer();
	UFUNCTION()
	void Loose();
};
