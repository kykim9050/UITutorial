// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "T1MainWidget.generated.h"

/**
 * 
 */
class UWTextDataMain;
class UCanvasPanel;
class ULineGraphWidget;
UCLASS(Blueprintable, BlueprintType)
class UITUTORIAL_API UT1MainWidget : public UUserWidget
{
	GENERATED_BODY()
public:

protected:
	const FText GetPaletteCategory() override;

private:
	UPROPERTY(BlueprintReadOnly, Category = "T1Widget", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	UCanvasPanel* RootWidget = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "T1Widget", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	UWTextDataMain* TextDataMain = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "T1Widget", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	ULineGraphWidget* LineGraphWidget = nullptr;
};
