// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealTimeData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRealTimeData
{
	GENERATED_BODY()
	
public:
	// x,y,z��ǥ�� ������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Pos;

public:
	FRealTimeData()
		:Pos(FVector())
	{

	}

	FRealTimeData(FVector _Pos)
		:Pos(_Pos)
	{

	}
};
