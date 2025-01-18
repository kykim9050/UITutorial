// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LineGraphWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITUTORIAL_API ULineGraphWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Set the data points for the graph
    UFUNCTION(BlueprintCallable, Category = "Graph")
    void SetGraphData(const TArray<FVector2D>& InDataPoints);

protected:
    // Data points for the graph
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graph")
    TArray<FVector2D> DataPoints;

    // Override OnPaint to draw the graph
    virtual int32 NativePaint(
        const FPaintArgs& Args,
        const FGeometry& AllottedGeometry,
        const FSlateRect& MyCullingRect,
        FSlateWindowElementList& OutDrawElements,
        int32 LayerId,
        const FWidgetStyle& InWidgetStyle,
        bool bParentEnabled
    ) const override;
	
};
