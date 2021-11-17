// Fill out your copyright notice in the Description page of Project Settings.


#include "SomePlayerController.h"
#include "SomeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Tower.h"
#include "Grabber.h"

ASomePlayerController::ASomePlayerController()
{

}

void ASomePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (Cast<ASomeCharacter>(GetPawn()))
	{
		Character = Cast<ASomeCharacter>(GetPawn());
	}
}
void ASomePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ASomePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
#if UE_BUILD_DEVELOPMENT
	UE_LOG(LogTemp, Warning, TEXT("Posses DONE"));
#endif
}

void ASomePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("Rotate", this, &ASomePlayerController::Rotate);
	InputComponent->BindAxis("MoveForward", this, &ASomePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASomePlayerController::MoveRight);
	InputComponent->BindAction("Grab", IE_Pressed, this, &ASomePlayerController::Grab);
	InputComponent->BindAction("Grab", IE_Released, this, &ASomePlayerController::Release);
	InputComponent->BindAction("Attack", IE_Pressed, this, &ASomePlayerController::Attack);
	InputComponent->BindAction("BuildTower", IE_Pressed, this, &ASomePlayerController::BuildTower);
}

void ASomePlayerController::Rotate(float Value)
{
	if (Value)
	{
		SetControlRotation((GetControlRotation() + FRotator(0, Value, 0)).Clamp());
	}
}

void ASomePlayerController::MoveForward(float Value)
{
	if (Value)
	{
		Character->AddMovementInput(Character->GetActorForwardVector(), Value);
	}
}

void ASomePlayerController::MoveRight(float Value)
{
	if (Value)
	{
		Character->AddMovementInput(Character->GetActorRightVector(), Value);
	}
}

void ASomePlayerController::Fire()
{
	Character->Fire();
}

void ASomePlayerController::Attack()
{
	Character->Attack();
}

void ASomePlayerController::BuildTower()
{
	if (Character->IsAbleToBuild && Character->Gold >= TowerCost)
	{
		Character->Gold -= TowerCost;
		Character->PlayAnimMontage(Character->HammerAttackAnimation);
		SpawnLocation = Character->GetActorLocation() + Character->GetActorForwardVector() * 10 + FVector(0, 0, 120.0f);
		GetWorld()->SpawnActor<ATower>(TowerClass, SpawnLocation, FRotator(0, 0, 0));
	}
}

void ASomePlayerController::Grab()
{
	Character->FindComponentByClass<UGrabber>()->Grab();
}

void ASomePlayerController::Release()
{
	Character->FindComponentByClass<UGrabber>()->Release();
}
