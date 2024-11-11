// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GlobalFunction.generated.h"

/**
 * 
 */
class ARealTimeDataManager;
class UMainGameInstance;
UCLASS()
class UITUTORIAL_API UGlobalFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/// <summary>
	/// MainGameInstance를 가져오는 static 전역 함수
	/// </summary>
	/// <param name="WorldContextObject"></param>
	/// <returns></returns>
	static UMainGameInstance* GetMainGameInstance(const UWorld* WorldContextObject);

	ARealTimeDataManager* GetRTDataManager();

protected:

private:
};
