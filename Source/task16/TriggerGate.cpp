// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerGate.h"
#include "Kismet/GameplayStatics.h"
#include "SomeGameMode.h"
#include "Unit.h"
#include "SomeGameInstance.h"
#include "SomeGameMode.h"
#include "SomeGameState.h"
#include "SomeItem.h"
#include "SomeCharacter.h"

ATriggerGate::ATriggerGate()
{
	OnActorBeginOverlap.AddDynamic(this, &ATriggerGate::OnOverlap);
}

void ATriggerGate::BeginPlay()
{
	Super::BeginPlay();

	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		SomeGameMode = Cast<ASomeGameMode>(GameMode);
		SomeGameState = SomeGameMode->GetGameState<ASomeGameState>();
	}
}

void ATriggerGate::OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor->GetClass() == UnitTD)
	{
		SomeGameState->LooseHealth();
		OtherActor->Destroy();
	}
	if (SomeGameState->GetHealth() == 0 || OtherActor == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		if (UGameplayStatics::GetCurrentLevelName(this) == "NewMap")
		{
			Cast<USomeGameInstance>(GetGameInstance())->TransferParams.Broadcast();
			UGameplayStatics::OpenLevel(this, "TowerDefence", false);
		}
		if (UGameplayStatics::GetCurrentLevelName(this) == "TowerDefence")
		{
			Cast<USomeGameInstance>(GetGameInstance())->OnLooseEvent.Broadcast();
			Cast<USomeGameInstance>(GetGameInstance())->TransferParams.Broadcast();
			UGameplayStatics::OpenLevel(this, "NewMap", false);
		}
	}
	if (OtherActor->GetClass() == TreasureItem)
	{
		ASomeCharacter* PlayerChar = Cast<ASomeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		PlayerChar->GainExperience(TreasureExperience);
		OtherActor->Destroy();
	}
}