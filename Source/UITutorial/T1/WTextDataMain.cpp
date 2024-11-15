// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/WTextDataMain.h"
#include "T1/TextDataWidget.h"
#include "Global/GlobalFunction.h"
#include "Global/MainGameInstance.h"
#include "DataTable/T1TextDataRow.h"
#include "Kismet/GameplayStatics.h"
#include "T1/MapWidget.h"


void STextDataMain::Construct(const FArguments& InArgs)
{
	World = InArgs._World;
	PosInfo = InArgs._PosInfo;

	TSharedPtr<SGridPanel> GridPanel = nullptr;;
	TSharedPtr<SMapWidget> Map = nullptr;

	ChildSlot
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		[
			SAssignNew(Map, SMapWidget)
		]
		+SHorizontalBox::Slot()
		[
			SAssignNew(GridPanel, SGridPanel)
		]
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
						.Info(nullptr)
						.VarInfo_Lambda([this]() -> FText
						{
							return GetPawnLocationText();
						})
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
	TWeakObjectPtr<UWorld> CurWorld = GetWorld();

	TextDataMainWidget = SNew(STextDataMain).World(CurWorld).PosInfo(PosData);
	return TextDataMainWidget.ToSharedRef();
}

FText STextDataMain::GetPawnLocationText() const
{
	const UWorld* CurWorld = Cast<const UWorld>(World);

	if (APlayerController* PlayerController = GEngine->GetFirstLocalPlayerController(CurWorld))
	{
		if (APawn* Pawn = PlayerController->GetPawn())
		{
			FVector Location = Pawn->GetActorLocation();

			return FText::FromString(FString::Printf(TEXT("Location: X=%.2f, Y=%.2f, Z=%.2f"), Location.X, Location.Y, Location.Z));
		}
	}

	return FText::FromString(TEXT("No Pawn Found"));
}
