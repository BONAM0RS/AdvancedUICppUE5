// Fill out your copyright notice in the Description page of Project Settings.

#include "SAdvancedCommonButton.h"


FReply SAdvancedCommonButton::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	return SButton::OnKeyDown(MyGeometry, InKeyEvent);
}

FReply SAdvancedCommonButton::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	return SButton::OnKeyUp(MyGeometry, InKeyEvent);
}
