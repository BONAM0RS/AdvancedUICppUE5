// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedGameInstance.h"

#include "BFL_NavigationConfig.h"


void UAdvancedGameInstance::Init()
{
	Super::Init();

	UBFL_NavigationConfig::ResetAdvancedNavigationConfig();
}

void UAdvancedGameInstance::Shutdown()
{
#if WITH_EDITOR
	// Reset custom Slate input binding to default
    // Only done in editor for safety - runtime standalone process won't need this
	UBFL_NavigationConfig::ResetDefaultNavigationConfig();
#endif

	Super::Shutdown();
}

