// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/T1GameState.h"

void AT1GameState::PushActor(uint8 _Index, AActor* _Actor)
{
	if (false == AllActor.Contains(_Index))
	{
		AllActor.Add(_Index, NewObject<UActorGroup>());
	}

	AllActor[_Index]->Actors.Add(_Actor);
}
