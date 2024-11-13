// Fill out your copyright notice in the Description page of Project Settings.


#include "T1/WTextDataMain.h"
#include "T1/TextDataWidget.h"
#include "Global/GlobalFunction.h"
#include "Global/MainGameInstance.h"
#include "DataTable/T1TextDataRow.h"
#include "Kismet/GameplayStatics.h"


void STextDataMain::Construct(const FArguments& InArgs)
{
	World = InArgs._World;
	PosInfo = InArgs._PosInfo;
	
	if (false == World.IsValid())
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (false == World.IsValid())"), __FUNCTION__, __LINE__);
		return;
	}

	const UWorld* CastWorld = Cast<const UWorld>(World);
	if (nullptr == CastWorld)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == CastWorld)"), __FUNCTION__, __LINE__);
		return;
	}

	TSharedPtr<SGridPanel> GridPanel = nullptr;;

	ChildSlot
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		SAssignNew(GridPanel, SGridPanel)
	];

	FT1TextDataRow* TextDatas = UGlobalFunction::GetMainGameInstance(CastWorld)->GetT1TextDataRow(FName(TEXT("T1TextDatas")));

	if (nullptr == TextDatas)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == TextDatas)"), __FUNCTION__, __LINE__);
		return;
	}

	int32 DatasSize = TextDatas->Infos.Num();
	int32 Count = 0;

	for (int X = 0; X < 3; ++X)
	{
		for (int Y = 0; Y < 3; ++Y)
		{
			TSharedPtr<STextDataWidget> NewWidget = nullptr;

			if (DatasSize > Count)
			{
				GridPanel->AddSlot(Y, X)
				.Padding(10.f)
				[
					SAssignNew(NewWidget, STextDataWidget)
					.Info(&(TextDatas->Infos[Count]))
					.VarInfo_Lambda([this]() -> FText
						{
							return GetPawnLocationText();
						})
				];
				++Count;
			}
			else
			{
				GridPanel->AddSlot(Y, X)
				.Padding(10.f)
				[
					SAssignNew(NewWidget, STextDataWidget)
					.Info(nullptr)
				];
			}

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
	UWorld* CurWorld = GetWorld();

	if (nullptr == CurWorld)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == CurWorld)"), __FUNCTION__, __LINE__);
	}

	//PosData = MakeAttributeLambda([]()->FText
	//	{
	//		return FText::FromString(FDateTime::Now().ToString(TEXT("%Y-%m-%d %H:%M:%S")));
	//		//return UGameplayStatics::GetPlayerController(CurWorld, 0)->GetPawn()->GetActorLocation();
	//	});

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
