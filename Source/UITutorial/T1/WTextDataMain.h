// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "WTextDataMain.generated.h"

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
	
};
