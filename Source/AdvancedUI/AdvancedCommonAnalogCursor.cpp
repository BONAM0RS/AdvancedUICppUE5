// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonAnalogCursor.h"

#include "AdvancedCommonUIActionRouter.h"


void FAdvancedCommonAnalogCursor::UpdateCursorVisibility()
{
	RefreshCursorVisibility();
}

void FAdvancedCommonAnalogCursor::SetGamepadCursorMovementState(bool bNewState)
{
	bIsAnalogMovementEnabled = bNewState;
}

void FAdvancedCommonAnalogCursor::Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor)
{
	FCommonAnalogCursor::Tick(DeltaTime, SlateApp, Cursor);
}

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



