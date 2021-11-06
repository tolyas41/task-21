// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPlace.h"
#include "Kismet/GameplayStatics.h"
#include "SomeCharacter.h"

ATowerPlace::ATowerPlace()
{
	OnActorBeginOverlap.AddDynamic(this, &ATowerPlace::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ATowerPlace::OnEndOverlap);
}

void ATowerPlace::BeginPlay()
{
	Super::BeginPlay();

	PlayerChar = Cast<ASomeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

void ATowerPlace::OnBeginOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor == PlayerChar)
	{
		PlayerChar->IsAbleToBuild = true;
	}
}

void ATowerPlace::OnEndOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor == PlayerChar)
	{
		PlayerChar->IsAbleToBuild = false;
	}
}
