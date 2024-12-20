// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Input/CommonUIActionRouterBase.h"
#include "AdvancedCommonUIActionRouter.generated.h"

UCLASS()
class ADVANCEDUI_API UAdvancedCommonUIActionRouter : public UCommonUIActionRouterBase
{
	GENERATED_BODY()

public:
	// Override to create own cursor class (it is auto used if UCommonUIActionRouterBase have child class)
	virtual TSharedRef<FCommonAnalogCursor> MakeAnalogCursor() const override;

};
