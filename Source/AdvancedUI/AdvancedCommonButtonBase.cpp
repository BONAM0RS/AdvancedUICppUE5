// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonButtonBase.h"

#include "Blueprint/WidgetTree.h"
#include "AdvancedCommonButtonInternalBase.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/GridPanel.h"
#include "Components/GridSlot.h"


bool UAdvancedCommonButtonBase::Initialize()
{
	const bool bInitializedThisCall = Super::Initialize();

	if (bInitializedThisCall)
	{
		if (OutsideGridPanel)
		{
			UOverlay* NewRootWidget = NewObject<UOverlay>(this);
			UOverlaySlot* OverlaySlot = Cast<UOverlaySlot>(NewRootWidget->AddChild(OutsideGridPanel));
			OverlaySlot->SetPadding(FMargin());
			OverlaySlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
			OverlaySlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);

			CenterRow = LastRow / 2;
			CenterColumn = LastColumn / 2;
			UGridSlot* GridSlot = OutsideGridPanel->AddChildToGrid(WidgetTree->RootWidget, CenterRow, CenterColumn);
			GridSlot->SetPadding(FMargin());
			GridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
			GridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);

			WidgetTree->RootWidget = NewRootWidget;
		}
	}

	return bInitializedThisCall;
}

void UAdvancedCommonButtonBase::SetInputActionWidget(UCommonActionWidget* ActionWidget)
{
	InputActionWidget = ActionWidget;
}

UCommonButtonInternalBase* UAdvancedCommonButtonBase::ConstructInternalButton()
{
	AdvancedInternalButton = WidgetTree->ConstructWidget<UAdvancedCommonButtonInternalBase>(UAdvancedCommonButtonInternalBase::StaticClass(), FName(TEXT("InternalRootButtonBase")));
	return AdvancedInternalButton;
}

void UAdvancedCommonButtonBase::HandleFocusReceived()
{
	Super::HandleFocusReceived();

	if (OnButtonBaseFocused.IsBound())
	{
		OnButtonBaseFocused.Broadcast(this);
	}
}

void UAdvancedCommonButtonBase::HandleFocusLost()
{
	Super::HandleFocusLost();

	if (OnButtonBaseUnfocused.IsBound())
	{
		OnButtonBaseUnfocused.Broadcast(this);
	}
}












