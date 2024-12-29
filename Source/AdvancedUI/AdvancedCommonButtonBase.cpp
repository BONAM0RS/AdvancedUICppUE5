// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonButtonBase.h"

#include "Blueprint/WidgetTree.h"
#include "AdvancedCommonButtonInternalBase.h"



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












