// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"

#include "FAdvancedNavigationConfig.h"
#include "AdvancedCommonAnalogCursor.h"


void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

}

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

void APlayerControllerBase::SetArrowsNavigationState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		if (bNewState)
		{
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Left, EUINavigation::Left);
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Right, EUINavigation::Right);
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Up, EUINavigation::Up);
			CurrentNavConfig->KeyEventRules.Emplace(EKeys::Down, EUINavigation::Down);
		}
		else
		{
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Left);
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Right);
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Up);
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Down);
		}

		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetAcceptNavigationActionsState(bool bEnterNewState, bool bSpacebarNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		if (bEnterNewState)
		{
			CurrentNavConfig->KeyActionRules.Emplace(EKeys::Enter, EUINavigationAction::Accept);
		}
		else
		{
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Enter);
		}

		if (bSpacebarNewState)
		{
			CurrentNavConfig->KeyActionRules.Emplace(EKeys::SpaceBar, EUINavigationAction::Accept);
		}
		else
		{
			CurrentNavConfig->KeyEventRules.Remove(EKeys::SpaceBar);
		}

		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetBackNavigationActionsState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		if (bNewState)
		{
			CurrentNavConfig->KeyActionRules.Emplace(EKeys::Escape, EUINavigationAction::Back);
		}
		else
		{
			CurrentNavConfig->KeyEventRules.Remove(EKeys::Escape);
		}

		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetAnalogNavigationSide(bool bIsRight)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		if (bIsRight)
		{
			CurrentNavConfig->AnalogHorizontalKey = EKeys::Gamepad_RightX;
			CurrentNavConfig->AnalogVerticalKey = EKeys::Gamepad_RightY;
		}
		else
		{
			CurrentNavConfig->AnalogHorizontalKey = EKeys::Gamepad_LeftX;
			CurrentNavConfig->AnalogVerticalKey = EKeys::Gamepad_LeftY;
		}

		FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
	}
}

void APlayerControllerBase::SetAnalogNavigationBothState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		TSharedRef<FAdvancedNavigationConfig> AdvancedNavConfig = StaticCastSharedRef<FAdvancedNavigationConfig>(CurrentNavConfig);
		AdvancedNavConfig->bBothAnalogNavigation = bNewState;
		FSlateApplication::Get().SetNavigationConfig(AdvancedNavConfig);
	}
}
