// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "T1/T1DataStruct.h"
#include "T1TextDataRow.generated.h"

/**
 * 
 */
USTRUCT()
struct UITUTORIAL_API FT1TextDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	/// <summary>
	/// FTextDataInfo 구조체 배열 자료구조
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<FTextDataInfo> Infos = TArray<FTextDataInfo>();
};
