// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/T1HUD.h"

#include "T1/T1MainWidget.h"

void AT1HUD::BeginPlay()
{
	Super::BeginPlay();

	MainWidget = CreateWidget<UT1MainWidget>(GetWorld(), MainWidgetClass);

	if (nullptr != MainWidget)
	{
		MainWidget->AddToViewport();
	}
}
