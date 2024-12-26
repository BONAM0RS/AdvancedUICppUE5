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

protected:
	virtual UCommonButtonInternalBase* ConstructInternalButton() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetMouseInteractionState(bool bNewState);

private:
	UPROPERTY()
	UAdvancedCommonButtonInternalBase* AdvancedInternalButton = nullptr;
};
