// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "T1GameState.generated.h"


UCLASS()
class UActorGroup : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly/*, meta = (AllowPrivateAccess = "true")*/)
	TArray<AActor*> Actors = TArray<AActor*>();
};

UCLASS()
class UITUTORIAL_API AT1GameState : public AGameState
{
	GENERATED_BODY()
public:
	template<typename EnumType>
	void PushActor(EnumType _Index, AActor* _Actor)
	{
		PushActor(static_cast<uint8>(_Index), _Actor);
	}

	void PushActor(uint8 _Index, AActor* _Actor);

protected:

private:
	TMap<uint8, UActorGroup*> AllActor = TMap<uint8, UActorGroup*>();
};
