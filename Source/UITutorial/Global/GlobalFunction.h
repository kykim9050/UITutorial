// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Global/ContentsEnum.h"
#include "GlobalFunction.generated.h"

/**
 * 
 */
class ARealTimeDataManager;
class UMainGameInstance;
class AT1GameState;
UCLASS()
class UITUTORIAL_API UGlobalFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/// <summary>
	/// MainGameInstance�� �������� static ���� �Լ�
	/// </summary>
	/// <param name="WorldContextObject"></param>
	/// <returns></returns>
	static UMainGameInstance* GetMainGameInstance(const UWorld* WorldContextObject);

	static AT1GameState* GetGameState(const UWorld* WorldContextObject);

	/// <summary>
	/// GameState�� Actor�� ������ �� �ִ� �żҵ� (���ø�)
	/// </summary>
	/// <typeparam name="EnumType"></typeparam>
	/// <param name="_GroupIndex"></param>
	/// <param name="_Actor"></param>
	template<typename EnumType>
	static void PushActor(EnumType _GroupIndex, AActor* _Actor)
	{
		if (nullptr == _Actor)
		{
			return;
		}

		PushActor(static_cast<uint8>(_GroupIndex), _Actor);
	}

	/// <summary>
	/// GameState�� Actor�� ������ �� �ִ� �żҵ�
	/// </summary>
	/// <param name="_GroupIndex"></param>
	/// <param name="_Actor"></param>
	UFUNCTION(BlueprintCallable, Category = "Game", meta = (UnsafeDuringActorConstruction = "true"))
	static void PushActor(uint8 _GroupIndex, AActor* _Actor);

protected:

private:
};
