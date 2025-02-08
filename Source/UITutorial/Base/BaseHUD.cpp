// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/BaseHUD.h"
#include "Blueprint/UserWidget.h"

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();

	MainWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);

	if (nullptr != MainWidget)
	{
		MainWidget->AddToViewport();
	}
}