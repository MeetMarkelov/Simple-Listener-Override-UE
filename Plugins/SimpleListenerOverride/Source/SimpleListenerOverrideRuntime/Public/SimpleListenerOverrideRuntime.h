// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSimpleListenerOverride, All, All)

#define SLO_LOG(Time, Format, ...) \
if (false) \
{ \
	const FString ToDisplayText = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
	if (ToDisplayText != "") \
	{ \
		UE_LOG(LogSimpleListenerOverride, Warning, TEXT("%s"), *ToDisplayText); \
		const float ToDisplayTime = float(Time); \
		if (GEngine && ToDisplayTime > 0.f) \
		{ \
			GEngine->AddOnScreenDebugMessage(-1, ToDisplayTime, FColor::Red, ToDisplayText); \
		} \
	} \
}

class FSimpleListenerOverrideRuntime : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
