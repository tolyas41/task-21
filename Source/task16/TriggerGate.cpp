// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerGate.h"
#include "Kismet/GameplayStatics.h"
#include "SomeGameMode.h"
#include "Unit.h"
#include "SomeGameInstance.h"

ATriggerGate::ATriggerGate()
{
	OnActorBeginOverlap.AddDynamic(this, &ATriggerGate::OnOverlap);
}

void ATriggerGate::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerGate::OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor->GetClass() == UnitTD)
	{
		Health--;
		OtherActor->Destroy();
	}
	if (Health == 0 || OtherActor == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		if (UGameplayStatics::GetCurrentLevelName(this) == "NewMap")
		{
			UGameplayStatics::OpenLevel(this, "TowerDefence", false);
		}
		if (UGameplayStatics::GetCurrentLevelName(this) == "TowerDefence")
		{
			UGameplayStatics::OpenLevel(this, "NewMap", false);
		}

		Cast<USomeGameInstance>(GetGameInstance())->OnMapOpen.Broadcast();
	}
}