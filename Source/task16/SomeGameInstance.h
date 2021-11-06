// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SomeGameInstance.generated.h"

DECLARE_EVENT(USomeGameInstance, FOnLooseEvent)

UCLASS()
class TASK16_API USomeGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	FOnLooseEvent OnMapOpen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LooseCount;

private:
	UFUNCTION()
	void Loose();
};
