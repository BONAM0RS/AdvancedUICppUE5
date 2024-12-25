// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFL_NavigationConfig.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UBFL_NavigationConfig : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static void ResetAdvancedNavigationConfig();

	UFUNCTION(BlueprintCallable)
	static void ResetDefaultNavigationConfig();

	UFUNCTION(BlueprintCallable)
	static void SetTabNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	static void SetKeyNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	static void SetAnalogNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	static void SetDpadNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	static void SetArrowsNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	static void SetAcceptNavigationActionsState(bool bEnterNewState, bool bSpacebarNewState);

	UFUNCTION(BlueprintCallable)
	static void SetBackNavigationActionsState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	static void SetAnalogNavigationSide(bool bIsRight);

	UFUNCTION(BlueprintCallable)
	static void SetAnalogNavigationBothState(bool bNewState);
};
