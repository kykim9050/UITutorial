// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "T1/RealTimeData.h"
#include "RealTimeDataManager.generated.h"

/**
 * 
 */
UCLASS()
class UITUTORIAL_API ARealTimeDataManager : public AActor
{
	GENERATED_BODY()
public:
	ARealTimeDataManager()
		:RTData(FRealTimeData())
	{

	}

	const FRealTimeData& GetRTData() const
	{
		return RTData;
	}
	
	void SetRTData(const FRealTimeData& _RTData)
	{
		RTData = _RTData;
	}

protected:
	void BeginPlay() override;

private:
	UPROPERTY()
	FRealTimeData RTData = FRealTimeData();
};
