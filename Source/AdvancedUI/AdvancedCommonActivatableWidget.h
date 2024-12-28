// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AdvancedCommonActivatableWidget.generated.h"


DECLARE_DYNAMIC_DELEGATE(FInputActionExecutedDelegate);

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedCommonActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeOnDeactivated() override;
	virtual void NativeDestruct() override;

	UFUNCTION(BlueprintCallable, Category = AdvancedCommonActivatableWidget)
	void RegisterBinding(const UInputAction* EnhancedInputAction, bool bShowInActionBar,
		const FInputActionExecutedDelegate& Callback, FUIActionBindingHandle& BindingHandle);

	UFUNCTION(BlueprintCallable, Category = AdvancedCommonActivatableWidget)
	void UnregisterBinding(FUIActionBindingHandle BindingHandle);

	UFUNCTION(BlueprintCallable, Category = AdvancedCommonActivatableWidget)
	void UnregisterAllBindings();

private:
	TArray<FUIActionBindingHandle> BindingHandles;
};
