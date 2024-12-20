// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonUIActionRouter.h"

#include "AdvancedCommonAnalogCursor.h"


TSharedRef<FCommonAnalogCursor> UAdvancedCommonUIActionRouter::MakeAnalogCursor() const
{
	return FCommonAnalogCursor::CreateAnalogCursor<FAdvancedCommonAnalogCursor>(*this);
}
