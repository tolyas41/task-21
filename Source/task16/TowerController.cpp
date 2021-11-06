// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerController.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void ATowerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!Target || Target->IsActorBeingDestroyed())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), TargetClass, Enemies);
		Target = UGameplayStatics::FindNearestActor(GetPawn()->GetActorLocation(), Enemies, AttackDistance);
		if (AttackDistance > MaxAttackDistance)
		{
			Target = nullptr;
		}
		SetFocus(Target);
	}
}

void ATowerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATowerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Tower = Cast<ATower>(InPawn);

	FTimerHandle FireTimerHandle;
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ATowerController::Fire, Tower->FireRate, true, 2.0f);
}

void ATowerController::Fire()
{
	if (Target && !Target->IsActorBeingDestroyed())
	{
		Tower->Fire();
	}
}