// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/TextDataWidget.h"
#include "T1/T1DataStruct.h"

void STextDataWidget::Construct(const FArguments& InArgs)
{
	Info = InArgs._Info;

	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(Info.IsValid() ? Info->DataTitle : "None"))
		]
		+SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(Info.IsValid() ? Info->DataUnit : "None"))
		]
		+SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(Info.IsValid() ? Info->DataValue : "None"))
		]
	];
}
