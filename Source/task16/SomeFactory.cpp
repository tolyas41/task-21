// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeFactory.h"
#include "Unit.h"
#include "TimerManager.h"
#include "SomeGameMode.h"
#include "Kismet/GameplayStatics.h"

ASomeFactory::ASomeFactory()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASomeFactory::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle MemberTimerHandle;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ASomeFactory::SpawnUnit, SpawnRate, true, 1.0f);

	SomeGameMode = Cast<ASomeGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

}

void ASomeFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASomeFactory::SpawnUnit()
{
	SpawnLocation = GetActorLocation();
	GetWorld()->SpawnActor<AUnit>(UnitToSpawn, SpawnLocation, FRotator(0, 225.0f, 0));
	SomeGameMode->OnSpawnEvent.Broadcast();

}
