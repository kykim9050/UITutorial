// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/RealTimeDataManager.h"

void ARealTimeDataManager::BeginPlay()
{
	Super::BeginPlay();
}

void ARealTimeDataManager::SetPos(const FVector& _Pos)
{
	RTData.Pos = _Pos;
}
