// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"

#include "Framework/Application/NavigationConfig.h"


void APlayerControllerBase::SetTabNavigationState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		CurrentNavConfig->bTabNavigation = bNewState;
		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetKeyNavigationState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		CurrentNavConfig->bKeyNavigation = bNewState;
		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetAnalogNavigationState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		CurrentNavConfig->bAnalogNavigation = bNewState;
		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetDpadNavigationState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		if (bNewState)
		{
			CurrentNavConfig->bKeyNavigation = bNewState;
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Gamepad_DPad_Left, EUINavigation::Left);
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Gamepad_DPad_Right, EUINavigation::Right);
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Gamepad_DPad_Up, EUINavigation::Up);
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Gamepad_DPad_Down, EUINavigation::Down);
		}
		else
		{
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Gamepad_DPad_Left);
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Gamepad_DPad_Right);
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Gamepad_DPad_Up);
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Gamepad_DPad_Down);
		}

		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}
