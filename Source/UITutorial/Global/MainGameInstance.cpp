// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/MainGameInstance.h"
#include "DataTable/T1TextDataRow.h"

const FT1TextDataRow* UMainGameInstance::GetT1TextDataRow(FName _Name)
{
	if (nullptr == T1TextDataRow)
	{
		UE_LOG(LogType, Fatal, TEXT("%S(%u)> if (nullptr == T1TextDataRow)"), __FUNCTION__, __LINE__);
	}

	FT1TextDataRow* Data = T1TextDataRow->FindRow<FT1TextDataRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogType, Error, TEXT("%S(%u)> %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
		return nullptr;
	}

	return Data;
}