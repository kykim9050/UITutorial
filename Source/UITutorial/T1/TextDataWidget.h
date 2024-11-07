// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct FTextDataInfo;

class UITUTORIAL_API STextDataWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STextDataWidget) {}
	SLATE_ARGUMENT(FTextDataInfo*, Info)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
protected:

private:
	FTextDataInfo* Info = nullptr;
};
