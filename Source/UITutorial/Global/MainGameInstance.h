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
	/// T1TextData ������ ���̺� ������ �����´�
	/// </summary>
	/// <param name="_Name"></param>
	/// <returns></returns>
	const FT1TextDataRow* GetT1TextDataRow(FName _Name);

protected:

private:
	UPROPERTY(EditAnywhere, /*BlueprintReadWrite, */meta = (AllowprivateAccess = "true"))
	UDataTable* T1TextDataRow = nullptr;
};
