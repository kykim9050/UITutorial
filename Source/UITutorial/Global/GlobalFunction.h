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

	/// <summary>
	/// ���� World�� ���ϴ� GameState�� �������� �Լ�
	/// </summary>
	/// <typeparam name="GameStateType"></typeparam>
	/// <param name="WorldContextObject"></param>
	/// <returns></returns>
	template<typename GameStateType>
	static GameStateType* GetCurGameState(const UWorld* WorldContextObject)
	{
		if (nullptr == WorldContextObject)
		{
			return nullptr;
		}

		const UWorld* World = Cast<UWorld>(WorldContextObject);
		GameStateType* CurGameState = World->GetGameState<GameStateType>();

		if (nullptr == CurGameState)
		{
			return nullptr;
		}

		return CurGameState;
	}

	/// <summary>
	/// GameState�� Actor�� ������ �� �ִ� �żҵ� (���ø�)
	/// </summary>
	/// <typeparam name="EnumType"></typeparam>
	/// <param name="_GroupIndex"></param>
	/// <param name="_Actor"></param>
	template<typename GameStateType, typename EnumType>
	static void PushActor(EnumType _GroupIndex, AActor* _Actor)
	{
		if (nullptr == _Actor)
		{
			return;
		}

		PushActor<GameStateType>(static_cast<uint8>(_GroupIndex), _Actor);
	}

	/// <summary>
	/// GameState�� Actor�� ������ �� �ִ� �żҵ�
	/// </summary>
	/// <param name="_GroupIndex"></param>
	/// <param name="_Actor"></param>
	template<typename GameStateType>
	UFUNCTION(BlueprintCallable, Category = "Game", meta = (UnsafeDuringActorConstruction = "true"))
	static void PushActor(uint8 _GroupIndex, AActor* _Actor)
	{
		if (nullptr == _Actor->GetWorld())
		{
			return;
		}

		AT1GameState* GameState = GetCurGameState<GameStateType>(_Actor->GetWorld());
		if (nullptr == GameState)
		{
			UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == GameState)"), __FUNCTION__, __LINE__);
		}

		GameState->PushActor(_GroupIndex, _Actor);
	}

protected:

private:
};
