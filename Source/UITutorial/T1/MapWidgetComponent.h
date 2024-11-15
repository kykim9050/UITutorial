// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MapWidgetComponent.generated.h"


UCLASS(BlueprintType)
class AMap : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapWidget")
	FSlateBrush MapImg;
};

USTRUCT(BlueprintType)
struct FMapWidgetData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapWidget")
	TSubclassOf<AMap> MapClass;

	FMapWidgetData()
		:MapClass(nullptr)
	{

	}

	FMapWidgetData(TSubclassOf<AMap> _MapClass)
		:MapClass(_MapClass)
	{

	}
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UITUTORIAL_API UMapWidgetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMapWidgetComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	FMapWidgetData& GetMapData()
	{
		return MapData;
	}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapWidget", meta = (AllowPrivateAccess = "true"))
	FMapWidgetData MapData;
};
