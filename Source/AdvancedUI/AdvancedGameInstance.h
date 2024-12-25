// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AdvancedGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void Shutdown() override;

public:
	UFUNCTION(BlueprintCallable)
	void ResetAdvancedNavigationConfig();

	UFUNCTION(BlueprintCallable)
	void ResetDefaultNavigationConfig();

	UFUNCTION(BlueprintCallable)
	void SetTabNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void SetKeyNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void SetAnalogNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void SetDpadNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void SetArrowsNavigationState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void SetAcceptNavigationActionsState(bool bEnterNewState, bool bSpacebarNewState);

	UFUNCTION(BlueprintCallable)
	void SetBackNavigationActionsState(bool bNewState);

	UFUNCTION(BlueprintCallable)
	void SetAnalogNavigationSide(bool bIsRight);

	UFUNCTION(BlueprintCallable)
	void SetAnalogNavigationBothState(bool bNewState);
};
