// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "T1HUD.generated.h"

class UT1MainWidget;
/**
 * 
 */
UCLASS()
class UITUTORIAL_API AT1HUD : public AHUD
{
	GENERATED_BODY()

public:

protected:
	void BeginPlay() override;

private:
	UUserWidget* MainWidget = nullptr;

	UPROPERTY(Editanywhere, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> MainWidgetClass = nullptr;
};
