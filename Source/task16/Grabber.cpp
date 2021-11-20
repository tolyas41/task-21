// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	CheckPhysicsHadle();
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsPhysicsHandle && PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetPlayersReach() + FVector(0, 0, LevitateValue));
	}
}

void UGrabber::Grab()
{
	if (IsPhysicsHandle)
	{
		FHitResult Hit;
		FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

		GetWorld()->LineTraceSingleByObjectType(Hit, GetOwner()->GetActorLocation(), GetPlayersReach(),	FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

		if (Hit.GetActor())
		{
			PhysicsHandle->GrabComponentAtLocationWithRotation(Hit.GetComponent(), NAME_None, GetPlayersReach(), FRotator());
		}
	}
}

void UGrabber::Release()
{
	if (IsPhysicsHandle)
	{
		PhysicsHandle->ReleaseComponent();
	}
}

FVector UGrabber::GetPlayersReach()
{
	return GetOwner()->GetActorLocation() + GetOwner()->GetActorRotation().Vector() * Reach;
}

void UGrabber::CheckPhysicsHadle()
{
	if (PhysicsHandle)
	{
		IsPhysicsHandle = true;
	}
	else
	{
		IsPhysicsHandle = false;
	}
}