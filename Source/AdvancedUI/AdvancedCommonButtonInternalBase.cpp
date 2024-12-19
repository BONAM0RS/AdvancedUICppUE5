// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonButtonInternalBase.h"

#include "SAdvancedCommonButton.h"
#include "Components/ButtonSlot.h"


TSharedRef<SWidget> UAdvancedCommonButtonInternalBase::RebuildWidget()
{
	MyButton = MyCommonButton = SNew(SAdvancedCommonButton)
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClickedOverride))
		.OnDoubleClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleDoubleClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressedOverride))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleasedOverride))
		.ButtonStyle(&GetStyle())
		.ClickMethod(GetClickMethod())
		.TouchMethod(GetTouchMethod())
		.IsFocusable(GetIsFocusable())
		.IsButtonEnabled(bButtonEnabled)
		.IsInteractionEnabled(bInteractionEnabled)
		.OnReceivedFocus(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleOnReceivedFocus))
		.OnLostFocus(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleOnLostFocus));

	MyBox = SNew(SBox)
		.MinDesiredWidth(MinWidth)
		.MinDesiredHeight(MinHeight)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			MyCommonButton.ToSharedRef()
		];

	if (GetChildrenCount() > 0)
	{
		Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyCommonButton.ToSharedRef());
	}

	return MyBox.ToSharedRef();
}
