// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "AdvancedCommonButtonInternalBase.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedCommonButtonInternalBase : public UCommonButtonInternalBase
{
	GENERATED_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
