// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameState.h"
#include "SomeGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SomeGameInstance.h"


void ASomeGameState::BeginPlay()
{
	Super::BeginPlay();

	LooseCount = Cast<USomeGameInstance>(GetGameInstance())->GetLooseCount();
}


void ASomeGameState::LooseHealth()
{
	Health--;
}

int32 ASomeGameState::GetHealth()
{
	return Health;
}