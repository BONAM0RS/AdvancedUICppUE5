// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionWidget.h"
#include "AdvancedCommonActionWidget.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedCommonActionWidget : public UCommonActionWidget
{
	GENERATED_BODY()
	
public:
	virtual FSlateBrush GetIcon() const override;

protected:
	FSlateBrush GetIconForEnhancedInputAction(const UCommonInputSubsystem* CommonInputSubsystem, const UInputAction* InputAction, const int KeyNumber) const;
	FKey GetKeyForInputType(const ULocalPlayer* LocalPlayer, ECommonInputType InputType, const UInputAction* InputAction, const int KeyNumber) const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	int KeyNum = 0;

};
