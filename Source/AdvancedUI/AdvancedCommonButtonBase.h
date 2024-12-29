// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "AdvancedCommonButtonBase.generated.h"

class UAdvancedCommonButtonInternalBase;

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetInputActionWidget(UCommonActionWidget* ActionWidget);

protected:
	virtual UCommonButtonInternalBase* ConstructInternalButton() override;

	virtual void HandleFocusReceived() override;
	virtual void HandleFocusLost() override;

private:
	UPROPERTY()
	UAdvancedCommonButtonInternalBase* AdvancedInternalButton = nullptr;

protected:
	UPROPERTY(BlueprintAssignable, Category = "Events", meta = (AllowPrivateAccess = true, DisplayName = "On Focused"))
	FCommonButtonBaseClicked OnButtonBaseFocused;

	UPROPERTY(BlueprintAssignable, Category = "Events", meta = (AllowPrivateAccess = true, DisplayName = "On Unfocused"))
	FCommonButtonBaseClicked OnButtonBaseUnfocused;
};
