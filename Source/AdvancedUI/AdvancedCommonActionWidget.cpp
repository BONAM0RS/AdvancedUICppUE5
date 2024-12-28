// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonActionWidget.h"

#include "CommonUITypes.h"
#include "CommonInputBaseTypes.h"
#include "CommonInputSubsystem.h"
#include "EnhancedInputSubsystems.h"


FSlateBrush UAdvancedCommonActionWidget::GetIcon() const
{
    //return Super::GetIcon();

	if (!IsDesignTime())
	{
		if (const UCommonInputSubsystem* CommonInputSubsystem = GetInputSubsystem())
		{
			if (EnhancedInputAction && CommonUI::IsEnhancedInputSupportEnabled())
			{
				return GetIconForEnhancedInputAction(CommonInputSubsystem, EnhancedInputAction, KeyNum);
				//return CommonUI::GetIconForEnhancedInputAction(CommonInputSubsystem, EnhancedInputAction);
			}
			else
			{
				return CommonUI::GetIconForInputActions(CommonInputSubsystem, InputActions);
			}
		}
	}
#if WITH_EDITORONLY_DATA
	else
	{
		if (DesignTimeKey.IsValid())
		{
			ECommonInputType Dummy;
			FName OutDefaultGamepadName;
			FCommonInputBase::GetCurrentPlatformDefaults(Dummy, OutDefaultGamepadName);

			ECommonInputType KeyInputType = ECommonInputType::MouseAndKeyboard;
			if (DesignTimeKey.IsGamepadKey())
			{
				KeyInputType = ECommonInputType::Gamepad;
			}
			else if (DesignTimeKey.IsTouch())
			{
				KeyInputType = ECommonInputType::Touch;
			}

			FSlateBrush InputBrush;
			if (UCommonInputPlatformSettings::Get()->TryGetInputBrush(InputBrush, TArray<FKey> { DesignTimeKey }, KeyInputType, OutDefaultGamepadName))
			{
				return InputBrush;
			}
		}
	}
#endif

	return *FStyleDefaults::GetNoBrush();
}

FSlateBrush UAdvancedCommonActionWidget::GetIconForEnhancedInputAction(const UCommonInputSubsystem* CommonInputSubsystem, 
	const UInputAction* InputAction, const int KeyNumber) const
{
	FKey KeyForCurrentInput = GetKeyForInputType(CommonInputSubsystem->GetLocalPlayer(), CommonInputSubsystem->GetCurrentInputType(), InputAction, KeyNumber);

	FSlateBrush SlateBrush;
	if (KeyForCurrentInput.IsValid() && UCommonInputPlatformSettings::Get()->TryGetInputBrush(SlateBrush, KeyForCurrentInput, CommonInputSubsystem->GetCurrentInputType(), CommonInputSubsystem->GetCurrentGamepadName()))
	{
		return SlateBrush;
	}

	return *FStyleDefaults::GetNoBrush();
}

FKey UAdvancedCommonActionWidget::GetKeyForInputType(const ULocalPlayer* LocalPlayer, ECommonInputType InputType, const UInputAction* InputAction, const int KeyNumber) const
{
	if (!LocalPlayer)
	{
		return FKey();
	}

	TArray<FKey> Keys;
	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		Keys = EnhancedInputLocalPlayerSubsystem->QueryKeysMappedToAction(InputAction);
	}

	// Filter keys based on the input type (Touch, Gamepad, MouseAndKeyboard)
	TArray<FKey> FilteredKeys;
	for (const FKey& Key : Keys)
	{
		if (!Key.IsValid())
		{
			continue;
		}

		if (Key.IsTouch() && InputType == ECommonInputType::Touch)
		{
			FilteredKeys.Add(Key);
		}
		else if (Key.IsGamepadKey() && InputType == ECommonInputType::Gamepad)
		{
			FilteredKeys.Add(Key);
		}
		else if (!Key.IsTouch() && !Key.IsGamepadKey() && InputType == ECommonInputType::MouseAndKeyboard)
		{
			FilteredKeys.Add(Key);
		}
	}

	// Return the key based on KeyNumber
	if (FilteredKeys.IsValidIndex(KeyNumber))
	{
		return FilteredKeys[KeyNumber];
	}

	return FKey();
}


