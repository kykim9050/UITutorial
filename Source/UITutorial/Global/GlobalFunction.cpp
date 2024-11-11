// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalFunction.h"

#include "Global/MainGameInstance.h"
#include "T1/RealTimeDataManager.h"
#include "T1/T1GameState.h"

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

AT1GameState* UGlobalFunction::GetGameState(const UWorld* WorldContextObject)
{
	if (nullptr == WorldContextObject)
	{
		return nullptr;
	}

	const UWorld* World = Cast<UWorld>(WorldContextObject);
	AT1GameState* CurGameState = World->GetGameState<AT1GameState>();

	if (nullptr == CurGameState)
	{
		return nullptr;
	}

	return CurGameState;
}

void UGlobalFunction::PushActor(uint8 _GroupIndex, AActor* _Actor)
{
	if (nullptr == _Actor->GetWorld())
	{
		return;
	}

	const UWorld* World = Cast<UWorld>(_Actor->GetWorld());

	AT1GameState* GameState = World->GetGameState<AT1GameState>();
	if (nullptr == GameState)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == GameState)"), __FUNCTION__, __LINE__);
	}

	GameState->PushActor(_GroupIndex, _Actor);
}

