// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/MapWidget.h"
#include "T1/MapWidgetComponent.h"

void SMapWidget::Construct(const FArguments& InArgs)
{
	MapData = InArgs._MapData;

	ChildSlot
	[
		SNew(SImage)
		.Image(this, &SMapWidget::GetMapImage)
	];
}

const FSlateBrush* SMapWidget::GetMapImage() const
{
	if (MapData && MapData->MapClass)
	{
		return &MapData->MapClass.GetDefaultObject()->MapImg;
	}

	return FCoreStyle::Get().GetBrush("WhiteBrush");
}
