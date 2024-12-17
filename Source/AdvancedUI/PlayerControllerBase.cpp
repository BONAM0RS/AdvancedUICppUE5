// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"

#include "Framework/Application/NavigationConfig.h"


void APlayerControllerBase::SetDefaultClickAndBackActionsState(bool bNewState)
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FNavigationConfig> CurrentNavConfig = FSlateApplication::Get().GetNavigationConfig();
		{
			if (bNewState)
			{
				CurrentNavConfig->KeyActionRules.Emplace(EKeys::Virtual_Accept, EUINavigationAction::Accept);
			}
			else
			{
				CurrentNavConfig->KeyActionRules.Remove(EKeys::Virtual_Accept);
			}

			FSlateApplication::Get().SetNavigationConfig(CurrentNavConfig);
		}
	}
}
