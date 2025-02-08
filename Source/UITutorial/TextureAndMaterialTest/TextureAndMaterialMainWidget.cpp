// Fill out your copyright notice in the Description page of Project Settings.


#include "TextureAndMaterialTest/TextureAndMaterialMainWidget.h"
#include "Components/WrapBox.h"

void UTextureAndMaterialMainWidget::AddChildren(int32 childrenNum)
{
	if (nullptr == mResourceWidgetClass)
	{
		UE_LOG(LogType, Error, TEXT("if (nullptr == ResourceWidgetClass)"));
		return;
	}

	for (int32 i = 0; i < childrenNum; i++)
	{
		addChild();
	}
}

void UTextureAndMaterialMainWidget::addChild()
{
	UUserWidget* ChildWidget = CreateWidget<UUserWidget>(this, mResourceWidgetClass);

	mResourceContainer->AddChild(ChildWidget);
}
