// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "WTextDataMain.generated.h"

class STextDataWidget;

class STextDataMain : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STextDataMain) {}
	SLATE_ARGUMENT(TWeakObjectPtr<UWorld>, World)
	SLATE_ATTRIBUTE(FVector, PosInfo)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<UWorld> World = nullptr;
	TAttribute<FVector> PosInfo = TAttribute<FVector>();

protected:

private:
	TArray<TSharedPtr<STextDataWidget>> TextDataWidgets = TArray<TSharedPtr<STextDataWidget>>();
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UITUTORIAL_API UWTextDataMain : public UWidget
{
	GENERATED_BODY()
public:

protected:
	void ReleaseSlateResources(bool bReleaseChildren) override;
	const FText GetPaletteCategory() override;
	TSharedRef<SWidget> RebuildWidget() override;

private:
	TSharedPtr<STextDataMain> TextDataMainWidget = nullptr;
	TAttribute<FVector> PosData = TAttribute<FVector>();
};
