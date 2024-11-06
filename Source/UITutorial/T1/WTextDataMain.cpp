// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/WTextDataMain.h"

void STextDataMain::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(STextBlock)
		.Text(FText::FromString("Test Text"))
	];
}

void UWTextDataMain::ReleaseSlateResources(bool bReleaseChildren)
{
	TextDataMainWidget.Reset();
}

const FText UWTextDataMain::GetPaletteCategory()
{
	return FText::FromString(FString("Tutorial Widget"));
}

TSharedRef<SWidget> UWTextDataMain::RebuildWidget()
{
	TextDataMainWidget = SNew(STextDataMain);
	return TextDataMainWidget.ToSharedRef();
}
