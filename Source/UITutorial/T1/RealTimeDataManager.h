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

	//UFUNCTION(BlueprintCallable)
	//const FRealTimeData& GetRTData() const
	//{
	//	return RTData;
	//}
	//
	//UFUNCTION(BlueprintCallable)
	//void SetRTData(const FRealTimeData& _RTData)
	//{
	//	RTData = _RTData;
	//}
	UFUNCTION(BlueprintCallable)
	const FVector& GetPos() const
	{
		return Pos;
	}

	UFUNCTION(BlueprintCallable)
	void SetPos(const FVector& _Pos);


protected:
	void BeginPlay() override;

private:
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	//FRealTimeData RTData = FRealTimeData();
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector Pos = FVector();
};
