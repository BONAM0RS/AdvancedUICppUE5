// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetDefaultClickAndBackActionsState(bool bNewState);
	
	// Add functions to disable/enable thumbstick/dpad/key/tab navigation, maybe smth else 
};
