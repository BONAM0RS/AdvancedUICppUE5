// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonAnalogCursor.h"

#include "AdvancedCommonUIActionRouter.h"


bool FAdvancedCommonAnalogCursor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	return FCommonAnalogCursor::HandleKeyDownEvent(SlateApp, InKeyEvent);
}

bool FAdvancedCommonAnalogCursor::HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	return FCommonAnalogCursor::HandleKeyUpEvent(SlateApp, InKeyEvent);
}

bool FAdvancedCommonAnalogCursor::ShouldVirtualAcceptSimulateMouseButton(const FKeyEvent& InKeyEvent, EInputEvent InputEvent) const
{
	const bool bIsGameMode = ActionRouter.GetActiveInputMode() == ECommonInputMode::Game;
	if (bIsGameMode)
	{
		return false;
	}

	return true;
}



