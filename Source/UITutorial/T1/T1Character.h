// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseCharacter.h"
#include "T1Character.generated.h"

/**
 * 
 */
class UMapWidgetComponent;
UCLASS()
class UITUTORIAL_API AT1Character : public ABaseCharacter
{
	GENERATED_BODY()
public:
	AT1Character();

protected:

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget", meta = (AllowPrivateAccess = "true"))
	UMapWidgetComponent* MapWidgetComponent = nullptr;
};
