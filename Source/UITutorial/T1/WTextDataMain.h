// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "WTextDataMain.generated.h"

class STextDataWidget;
class UMapWidgetComponent;
class STextDataMain : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STextDataMain) {}
	SLATE_ARGUMENT(TWeakObjectPtr<UWorld>, World)
	SLATE_ATTRIBUTE(FText, PosInfo)
	SLATE_ARGUMENT(TWeakObjectPtr<UMapWidgetComponent> ,MapWidget)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<UWorld> World = nullptr;
	TAttribute<FText> PosInfo = TAttribute<FText>();
	TWeakObjectPtr<UMapWidgetComponent> MapWidget = TWeakObjectPtr<UMapWidgetComponent>();

protected:

private:
	TArray<TSharedPtr<STextDataWidget>> TextDataWidgets = TArray<TSharedPtr<STextDataWidget>>();

	FText GetPawnLocationText() const;
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
	UMapWidgetComponent* MapWidgetComponent = nullptr;
	TSharedPtr<STextDataMain> TextDataMainWidget = nullptr;
	TAttribute<FText> PosData = TAttribute<FText>();
};
