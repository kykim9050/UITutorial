// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/RealTimeDataManager.h"
#include "Global/GlobalFunction.h"

void ARealTimeDataManager::BeginPlay()
{
	Super::BeginPlay();
	UGlobalFunction::PushActor(EObjectType::InfoManager, this);
}


void ARealTimeDataManager::SetPos(const FVector& _Pos)
{
	RTData.Pos = _Pos;
}
