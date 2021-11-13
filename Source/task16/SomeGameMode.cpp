// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameMode.h"
#include "Blueprint/UserWidget.h"

void ASomeGameMode::BeginPlay()
{
    Super::BeginPlay();

    ChangeWidget(ExperienceBar);
}

void ASomeGameMode::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}