// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonAnalogCursor.h"

#include "AdvancedCommonUIActionRouter.h"
#include "CommonInputTypeEnum.h"


void FAdvancedCommonAnalogCursor::RefreshCursorVisibility()
{
	if (bIsAnalogMovementEnabled)
	{
		FSlateApplication& SlateApp = FSlateApplication::Get();
		if (TSharedPtr<FSlateUser> SlateUser = SlateApp.GetUser(GetOwnerUserIndex()))
		{
			const bool bShowCursor = bIsAnalogMovementEnabled || ActionRouter.ShouldAlwaysShowCursor() || ActiveInputMethod == ECommonInputType::MouseAndKeyboard;

			if (bShowCursor)
			{
				if (ActiveInputMethod == ECommonInputType::MouseAndKeyboard)
				{
					SlateApp.SetPlatformCursorVisibility(true);
					SlateUser->SetCursorVisibility(true);
				}
				else if (ActiveInputMethod == ECommonInputType::Gamepad)
				{
					SlateApp.SetPlatformCursorVisibility(false);
					SlateUser->SetCursorVisibility(true);
				}
			}
			else
			{
				SlateApp.SetPlatformCursorVisibility(false);
				SlateUser->SetCursorVisibility(false);
			}
		}
	}
	else
	{
		FCommonAnalogCursor::RefreshCursorVisibility();
	}
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



