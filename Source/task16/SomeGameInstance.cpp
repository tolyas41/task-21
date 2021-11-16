// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SomeCharacter.h"

void USomeGameInstance::Init()
{
	Super::Init();

	PlayerExperience = 0;
	PlayerLevel = 0;
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
	PlayerLevel = Cast<ASomeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->Level;
	PlayerGold = Cast<ASomeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->Gold;
}

int32 USomeGameInstance::GetLooseCount()
{
	return LooseCount;
}

float USomeGameInstance::GetPlayerExperience()
{
	return PlayerExperience;
}

int32 USomeGameInstance::GetPlayerLevel()
{
	return PlayerLevel;
}

int32 USomeGameInstance::GetPlayerGold()
{
	return PlayerGold;
}
