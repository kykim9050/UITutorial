// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/RealTimeDataManager.h"
#include "Global/GlobalFunction.h"
#include "T1/T1GameState.h"

ARealTimeDataManager::ARealTimeDataManager()
{
	if (nullptr != UGlobalFunction::GetCurGameState<AT1GameState>(GetWorld()))
	{
		UGlobalFunction::PushActor<AT1GameState>(EObjectType::InfoManager, this);
	}
}

void ARealTimeDataManager::BeginPlay()
{
	Super::BeginPlay();
}



void ARealTimeDataManager::SetPos(const FVector& _Pos)
{
	RTData.Pos = _Pos;
}
