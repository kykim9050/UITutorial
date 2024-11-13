// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/TextDataWidget.h"
#include "T1/T1DataStruct.h"

void STextDataWidget::Construct(const FArguments& InArgs)
{
	Info = InArgs._Info;
	VarInfo = InArgs._VarInfo;

	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(nullptr != Info ? Info->DataTitle : "None"))
		]
		+SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(nullptr != Info ? Info->DataUnit : "None"))
		]
		+SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(VarInfo.IsSet() ? VarInfo : FText::FromString(FString("Insert Value")))
		]
	];
}
