// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct FMapWidgetData;
class UITUTORIAL_API SMapWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMapWidget) {}
	SLATE_ARGUMENT(FMapWidgetData*, MapData)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	const FSlateBrush* GetMapImage() const;
protected:

private:
	FMapWidgetData* MapData;

};
