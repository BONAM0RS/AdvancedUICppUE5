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
	virtual void NativeDestruct() override;

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void RegisterBinding(const UInputAction* EnhancedInputAction, bool bShowInActionBar,
		const FInputActionExecutedDelegate Callback, FUIActionBindingHandle& BindingHandle);

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void UnregisterBinding(FUIActionBindingHandle BindingHandle);

	UFUNCTION(BlueprintCallable, Category = ExtendedActivatableWidget)
	void UnregisterAllBindings();

private:
	TArray<FUIActionBindingHandle> BindingHandles;
};
