// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Input/CommonAnalogCursor.h"


class ADVANCEDUI_API FAdvancedCommonAnalogCursor : public FCommonAnalogCursor
{
public:
    FAdvancedCommonAnalogCursor(const UCommonUIActionRouterBase& InActionRouter)
        : FCommonAnalogCursor(InActionRouter)
    {
    }

    virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;
    virtual bool HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;

    // You can return false to not process virtual accept as mouse click (then you need also handle navigation action accept 
    // in CommonButtonBase / SButton -> override key down/up events), but I think it's a rare case
    virtual bool ShouldVirtualAcceptSimulateMouseButton(const FKeyEvent& InKeyEvent, EInputEvent InputEvent) const override { return true; }
};
