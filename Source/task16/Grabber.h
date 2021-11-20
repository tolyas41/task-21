// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"

class UPhysicsHandleComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TASK16_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Grab();
	void Release();
	void CheckPhysicsHadle();
	FVector GetPlayersReach();

	UPROPERTY()
	UPhysicsHandleComponent* PhysicsHandle;

	FVector PlayersReach;

	UPROPERTY(EditAnywhere)
	float Reach = 200.0f;
	UPROPERTY(EditAnywhere)
	float LevitateValue = 100.0f;

	bool IsPhysicsHandle;
};
