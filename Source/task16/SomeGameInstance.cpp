// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SomeCharacter.h"

void USomeGameInstance::Init()
{
	Super::Init();

	PlayerExperience = 0;
	LooseCount = 0;
	OnLooseEvent.AddUFunction(this, FName("Loose"));
	TransferParams.AddUFunction(this, FName("Transfer"));
}

void USomeGameInstance::Loose()
{
	LooseCount++;
}

void USomeGameInstance::Transfer()
{
	PlayerExperience = Cast<ASomeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->Experience;
}

int32 USomeGameInstance::GetLooseCount()
{
	return LooseCount;
}

float USomeGameInstance::GetPlayerExperience()
{
	return PlayerExperience;
}
