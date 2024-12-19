// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCommonButtonBase.h"

#include "Blueprint/WidgetTree.h"
#include "AdvancedCommonButtonInternalBase.h"


UCommonButtonInternalBase* UAdvancedCommonButtonBase::ConstructInternalButton()
{
	return WidgetTree->ConstructWidget<UAdvancedCommonButtonInternalBase>(UAdvancedCommonButtonInternalBase::StaticClass(), FName(TEXT("InternalRootButtonBase")));
}
