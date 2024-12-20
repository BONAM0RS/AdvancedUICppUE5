// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonAnalogCursor.h"


bool FAdvancedCommonAnalogCursor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	return FCommonAnalogCursor::HandleKeyDownEvent(SlateApp, InKeyEvent);
}

bool FAdvancedCommonAnalogCursor::HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	return FCommonAnalogCursor::HandleKeyUpEvent(SlateApp, InKeyEvent);
}

