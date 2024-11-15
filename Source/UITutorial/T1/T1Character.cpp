// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/T1Character.h"
#include "T1/MapWidgetComponent.h"

AT1Character::AT1Character()
{
	MapWidgetComponent = CreateDefaultSubobject<UMapWidgetComponent>(TEXT("MapWidgetComponent"));
}
