// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/RealTimeDataManager.h"
#include "Global/GlobalFunction.h"

ARealTimeDataManager::ARealTimeDataManager()
{
	if (nullptr != UGlobalFunction::GetGameState(GetWorld()))
	{
		UGlobalFunction::PushActor(EObjectType::InfoManager, this);
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
