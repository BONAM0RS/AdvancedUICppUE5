// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/NavigationConfig.h"

/**
 * 
 */
class ADVANCEDUI_API FAdvancedNavigationConfig : public FNavigationConfig
{
public:
	FAdvancedNavigationConfig();

	virtual EUINavigation GetNavigationDirectionFromKey(const FKeyEvent& InKeyEvent) const override;
	virtual EUINavigation GetNavigationDirectionFromAnalog(const FAnalogInputEvent& InAnalogEvent) override;
	virtual EUINavigationAction GetNavigationActionFromKey(const FKeyEvent& InKeyEvent) const override;
	virtual EUINavigationAction GetNavigationActionForKey(const FKey& InKey) const override;

protected:
	virtual bool IsAnalogHorizontalKey(const FKey& InKey) const override;
	virtual bool IsAnalogVerticalKey(const FKey& InKey) const override;

public:
	bool bBothAnalogNavigation;

};
