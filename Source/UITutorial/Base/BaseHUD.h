// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class UITUTORIAL_API ABaseHUD : public AHUD
{
	GENERATED_BODY()
public:

protected:
	void BeginPlay() override;

private:

protected:

private:
	TObjectPtr<UUserWidget> MainWidget = nullptr;

	UPROPERTY(Editanywhere, Category = "BlueprintWidgetClass", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> MainWidgetClass = nullptr;
};
