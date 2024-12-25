// Fill out your copyright notice in the Description page of Project Settings.


#include "FAdvancedNavigationConfig.h"



FAdvancedNavigationConfig::FAdvancedNavigationConfig()
{
	AnalogNavigationHorizontalThreshold = 0.50f;
	AnalogNavigationVerticalThreshold = 0.50f;
	bIgnoreModifiersForNavigationActions = true;

	AnalogHorizontalKey = EKeys::Gamepad_LeftX;
	AnalogVerticalKey = EKeys::Gamepad_LeftY;

	bBothAnalogNavigation = false;

	bTabNavigation = false;
	bKeyNavigation = true;
	bAnalogNavigation = true;

	KeyEventRules.Reset();

	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Left, EUINavigation::Left);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Right, EUINavigation::Right);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Up, EUINavigation::Up);
	KeyEventRules.Emplace(EKeys::Gamepad_DPad_Down, EUINavigation::Down);

	KeyActionRules.Reset();

	KeyActionRules.Emplace(EKeys::Virtual_Accept, EUINavigationAction::Accept);
	KeyActionRules.Emplace(EKeys::Escape, EUINavigationAction::Back);
	KeyActionRules.Emplace(EKeys::Virtual_Back, EUINavigationAction::Back);
}

EUINavigation FAdvancedNavigationConfig::GetNavigationDirectionFromKey(const FKeyEvent& InKeyEvent) const
{
	return FNavigationConfig::GetNavigationDirectionFromKey(InKeyEvent);
}

EUINavigation FAdvancedNavigationConfig::GetNavigationDirectionFromAnalog(const FAnalogInputEvent& InAnalogEvent)
{
	return FNavigationConfig::GetNavigationDirectionFromAnalog(InAnalogEvent);
}

EUINavigationAction FAdvancedNavigationConfig::GetNavigationActionFromKey(const FKeyEvent& InKeyEvent) const
{
	return FNavigationConfig::GetNavigationActionFromKey(InKeyEvent);
}

EUINavigationAction FAdvancedNavigationConfig::GetNavigationActionForKey(const FKey& InKey) const
{
	return FNavigationConfig::GetNavigationActionForKey(InKey);
}

bool FAdvancedNavigationConfig::IsAnalogHorizontalKey(const FKey& InKey) const
{
	if (bBothAnalogNavigation)
	{
		return InKey == EKeys::Gamepad_LeftX || InKey == EKeys::Gamepad_RightX;
	}
	
	return InKey == AnalogHorizontalKey;
}

bool FAdvancedNavigationConfig::IsAnalogVerticalKey(const FKey& InKey) const
{
	if (bBothAnalogNavigation)
	{
		InKey == EKeys::Gamepad_LeftY || InKey == EKeys::Gamepad_RightY;
	}
	
	return InKey == AnalogVerticalKey;
}


