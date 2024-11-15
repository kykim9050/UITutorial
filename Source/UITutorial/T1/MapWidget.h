// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UITUTORIAL_API SMapWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMapWidget) {}
	SLATE_ATTRIBUTE(TWeakObjectPtr<const FSlateBrush>, MapImg)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

protected:

private:
	TAttribute<TWeakObjectPtr<const FSlateBrush>> MapImg;

	const FSlateBrush* GetMapImage();
};
