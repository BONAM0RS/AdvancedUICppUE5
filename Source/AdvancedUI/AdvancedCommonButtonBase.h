// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "AdvancedCommonButtonBase.generated.h"

class UAdvancedCommonButtonInternalBase;
class UGridPanel;
class UCommonTextBlock;

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

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

protected:
	/**
	* In case you need second input action widget
	*/
	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (BindWidget, OptionalWidget = true, AllowPrivateAccess = true))
	TObjectPtr<UCommonActionWidget> InputActionWidgetSecond;

	/**
	 * In case you want update text style in base button
	 */
	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (BindWidget, OptionalWidget = true, AllowPrivateAccess = true))
	UCommonTextBlock* TextWidget;

	// You can use it to add content that will not be recognized as button (example: input action widget outside of button borders)
	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (BindWidget, OptionalWidget = true, AllowPrivateAccess = true))
	UGridPanel* OutsideGridPanel;

	/**
	 * Should be minimum 2 and even number, button will be placed in the center column and row of this grid. 
	 * You must place button content to the same center column and grid. Also it is better to set layer 1 for your button content
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config | OutsideGridPanel", meta = (AllowPrivateAccess = true))
	int LastColumn = 2;

	/**
	 * Should be minimum 2 and even number, button will be placed in the center column and row of this grid
	 * You must place button content to the same center column and grid. Also it is better to set layer 1 for your button content
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config | OutsideGridPanel", meta = (AllowPrivateAccess = true))
	int LastRow = 2;

public:
	UPROPERTY(BlueprintReadOnly, Category = "OutsideGridPanel")
	int CenterColumn = 1;

	UPROPERTY(BlueprintReadOnly, Category = "OutsideGridPanel")
	int CenterRow = 1;
};
