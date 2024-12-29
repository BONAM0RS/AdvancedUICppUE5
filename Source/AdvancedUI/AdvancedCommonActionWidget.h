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
	virtual void UpdateActionWidget() override;

	FSlateBrush GetIconForEnhancedInputAction(const UCommonInputSubsystem* CommonInputSubsystem, const UInputAction* InputAction, const int KeyNumber) const;
	FKey GetKeyForInputType(const ULocalPlayer* LocalPlayer, ECommonInputType InputType, const UInputAction* InputAction, const int KeyNumber) const;

	UFUNCTION(BlueprintNativeEvent)
	FSlateBrush GetCustomIcon() const;

	UFUNCTION(BlueprintCallable)
	UCommonInputSubsystem* GetCommonInputSubsystem() const;

	virtual bool ShouldUpdateActionWidgetIcon() const override;

	UFUNCTION(BlueprintCallable)
	bool IsPreview() const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | General")
	float Size = 64.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Custom Icon")
	bool bUseCustomIcon = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Enhanced Input Action")
	int KeyNum = 0;

	
};
