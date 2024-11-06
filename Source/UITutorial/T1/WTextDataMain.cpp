// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/WTextDataMain.h"

void UWTextDataMain::ReleaseSlateResources(bool bReleaseChildren)
{

}

const FText UWTextDataMain::GetPaletteCategory()
{
	return FText::FromString(FString("Tutorial Widget"));
}

TSharedRef<SWidget> UWTextDataMain::RebuildWidget()
{
	return SNew(SSpacer);
}
