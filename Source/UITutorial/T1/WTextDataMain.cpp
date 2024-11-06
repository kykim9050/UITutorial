// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/WTextDataMain.h"
#include "T1/TextDataWidget.h"

void STextDataMain::Construct(const FArguments& InArgs)
{
	TSharedPtr<SGridPanel> GridPanel = nullptr;;

	ChildSlot
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		SAssignNew(GridPanel, SGridPanel)
	];

	for (int X = 0; X < 3; ++X)
	{
		for (int Y = 0; Y < 3; ++Y)
		{
			TSharedPtr<STextDataWidget> NewWidget = nullptr;
			GridPanel->AddSlot(Y, X)
			.Padding(10.f)
			[
				SAssignNew(NewWidget, STextDataWidget)
			];
			
			TextDataWidgets.Add(NewWidget);
		}
	}
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
