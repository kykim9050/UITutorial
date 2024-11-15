// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/MapWidget.h"

void SMapWidget::Construct(const FArguments& InArgs)
{
	MapImg = InArgs._MapImg;

	ChildSlot
	[
		SNew(SImage)
		.Image_Lambda([this]()-> const FSlateBrush*
			{
				return GetMapImage();
			})
	];
}

const FSlateBrush* SMapWidget::GetMapImage()
{
	if (MapImg.IsSet() && MapImg.Get().IsValid())
	{
		return MapImg.Get().Get();
	}

	return FCoreStyle::Get().GetBrush("WhiteBrush");
}
