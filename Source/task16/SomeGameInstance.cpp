// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameInstance.h"

void USomeGameInstance::Init()
{
	Super::Init();

	LooseCount = 0;
	OnMapOpen.AddUFunction(this, FName("Loose"));
}

void USomeGameInstance::Loose()
{
	LooseCount++;
}
