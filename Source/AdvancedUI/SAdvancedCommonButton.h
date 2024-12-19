// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CommonUI/Private/CommonButtonTypes.h"

/**
 * 
 */
class ADVANCEDUI_API SAdvancedCommonButton : public SCommonButton
{
public:
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
};
