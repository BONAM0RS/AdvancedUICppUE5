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
	UFUNCTION(BlueprintCallable)
	virtual void UpdateActionWidget() override;

	UFUNCTION(BlueprintCallable, Category = "Setters")
	void SetSize(float InSize);

	UFUNCTION(BlueprintCallable, Category = "Setters")
	void SetUseCustomIconState(bool bNewState);

	UFUNCTION(BlueprintCallable, Category = "Setters")
	void SetKeyNum(int InKeyNum);

	virtual FSlateBrush GetIcon() const override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdatedActionWidget);
	UPROPERTY(BlueprintAssignable, Category = AdvancedCommonActionWidget)
	FOnUpdatedActionWidget OnUpdatedActionWidget;

protected:
	FSlateBrush GetIconForEnhancedInputAction(const UCommonInputSubsystem* CommonInputSubsystem, const UInputAction* InputAction, const int KeyNumber) const;
	FKey GetKeyForInputType(const ULocalPlayer* LocalPlayer, ECommonInputType InputType, const UInputAction* InputAction, const int KeyNumber) const;

	UFUNCTION(BlueprintNativeEvent, Category = "CustomIcon")
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
