// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseUserWidget.h"
#include "TextureAndMaterialMainWidget.generated.h"

/**
 * 
 */
class UWrapBox;
UCLASS()
class UITUTORIAL_API UTextureAndMaterialMainWidget : public UBaseUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AddChildren(int32 childrenNum);

protected:

private:
	void addChild();

protected:

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> mResourceWidgetClass = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UWrapBox> mResourceContainer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 mChildrenNum = 0;
};
