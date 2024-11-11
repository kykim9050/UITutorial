// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
struct FT1TextDataRow;
UCLASS()
class UITUTORIAL_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	/// <summary>
	/// T1TextData 데이터 테이블 정보를 가져온다
	/// </summary>
	/// <param name="_Name"></param>
	/// <returns></returns>
	FT1TextDataRow* GetT1TextDataRow(FName _Name);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="_Name"></param>
	/// <returns></returns>
	const TSubclassOf<UObject> GetGlobalObjectClass(FName _Name);

protected:

private:
	UPROPERTY(EditAnywhere, meta = (AllowprivateAccess = "true"))
	UDataTable* T1TextDataRow = nullptr;


	UPROPERTY(EditAnywhere, meta = (AllowprivateAccess = "true"))
	UDataTable* GlobalObjectDataRow = nullptr;
};
