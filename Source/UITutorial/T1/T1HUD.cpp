// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/T1HUD.h"
#include "Blueprint/UserWidget.h"

void AT1HUD::BeginPlay()
{
	Super::BeginPlay();
	
	MainWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);

	if (nullptr != MainWidget)
	{
		MainWidget->AddToViewport();
	}
}
