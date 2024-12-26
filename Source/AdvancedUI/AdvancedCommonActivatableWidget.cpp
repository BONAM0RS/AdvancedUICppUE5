// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonActivatableWidget.h"

//#include "CommonUI/Private/Input/UIActionRouterTypes.h"
#include "Input/CommonUIInputTypes.h"


void UAdvancedCommonActivatableWidget::NativeDestruct()
{
	for (FUIActionBindingHandle Handle : BindingHandles)
	{
		if (Handle.IsValid())
		{
			Handle.Unregister();
		}
	}
	BindingHandles.Empty();

	Super::NativeDestruct();
}

void UAdvancedCommonActivatableWidget::RegisterBinding(const UInputAction* EnhancedInputAction, bool bShowInActionBar,
	const FInputActionExecutedDelegate Callback, FUIActionBindingHandle& BindingHandle)
{
	FBindUIActionArgs BindArgs(EnhancedInputAction, FSimpleDelegate::CreateLambda([EnhancedInputAction, Callback]()
		{
			Callback.ExecuteIfBound();
		}));
	BindArgs.bDisplayInActionBar = bShowInActionBar;

	BindingHandle = RegisterUIActionBinding(BindArgs);
	BindingHandles.Add(BindingHandle);
}

void UAdvancedCommonActivatableWidget::UnregisterBinding(FUIActionBindingHandle BindingHandle)
{
	if (BindingHandle.IsValid())
	{
		BindingHandle.Unregister();
		BindingHandles.Remove(BindingHandle);
	}
}

void UAdvancedCommonActivatableWidget::UnregisterAllBindings()
{
	for (FUIActionBindingHandle Handle : BindingHandles)
	{
		Handle.Unregister();
	}
	BindingHandles.Empty();
}
