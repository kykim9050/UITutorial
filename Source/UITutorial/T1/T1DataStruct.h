//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "T1DataStruct.generated.h"

/**
 *
 */
 USTRUCT()
 struct FTextDataInfo
 {
 	GENERATED_BODY()
 public:
 	UPROPERTY(EditAnywhere)
 	FString DataTitle = "Default";
 	
 	UPROPERTY(EditAnywhere)
 	FString DataUnit = "";
 
 	UPROPERTY(EditAnywhere)
 	FString DataValue = "...";
 
 public:
 	FTextDataInfo()
 		:DataTitle("Please write title")
 		, DataUnit("Please write unit")
 		, DataValue("Please match value")
 	{
 
 	}
 
 	FTextDataInfo(FString _DataTitle, FString _DataUnit, FString _DataValue)
 		:DataTitle(_DataTitle)
 		, DataUnit(_DataUnit)
 		, DataValue(_DataValue)
 	{
 
 	}
 };