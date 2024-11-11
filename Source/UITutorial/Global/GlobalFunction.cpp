// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalFunction.h"

#include "Global/MainGameInstance.h"
#include "T1/RealTimeDataManager.h"

UMainGameInstance* UGlobalFunction::GetMainGameInstance(const UWorld* WorldContextObject)
{
	UMainGameInstance* MainGameInst = WorldContextObject->GetGameInstanceChecked<UMainGameInstance>();

	if (false == MainGameInst->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (false == Inst->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return MainGameInst;
}

ARealTimeDataManager* UGlobalFunction::GetRTDataManager()
{
	return nullptr;
}

