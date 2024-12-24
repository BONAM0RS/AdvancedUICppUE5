// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonUIActionRouter.h"

#include "AdvancedCommonAnalogCursor.h"


TSharedRef<FCommonAnalogCursor> UAdvancedCommonUIActionRouter::MakeAnalogCursor() const
{
	return FCommonAnalogCursor::CreateAnalogCursor<FAdvancedCommonAnalogCursor>(*this);
}

void UAdvancedCommonUIActionRouter::SetGamepadCursorMovementState(bool bNewState)
{
    TSharedPtr<FCommonAnalogCursor> CommonAnalogCursor = GetCommonAnalogCursor();
    if (CommonAnalogCursor.IsValid())
    {
        TSharedPtr<FAdvancedCommonAnalogCursor> AdvancedCommonAnalogCursor = StaticCastSharedPtr<FAdvancedCommonAnalogCursor>(CommonAnalogCursor);
        AdvancedCommonAnalogCursor->SetGamepadCursorMovementState(bNewState);
    }
}
