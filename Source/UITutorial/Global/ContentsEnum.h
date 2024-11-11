// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ContentsEnum.generated.h"

UENUM(BlueprintType)
enum class EObjectType : uint8
{
	InfoManager,
	MAX,
};

/**
 * 
 */
UCLASS()
class UITUTORIAL_API UContentsEnum : public UObject
{
	GENERATED_BODY()
	
};
