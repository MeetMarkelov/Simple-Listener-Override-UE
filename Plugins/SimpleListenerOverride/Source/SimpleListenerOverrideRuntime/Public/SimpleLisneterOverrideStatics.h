// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "SimpleLisneterOverrideStatics.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLELISTENEROVERRIDERUNTIME_API USimpleLisneterOverrideStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/**
	 * Set listener position to Simple Lisneter Override Component location and rotation
	 * Actor - Actor with Simple Lisneter Override Component
	 * Loc - Additional location
	 * Rot - Additional rotation
	 */
	UFUNCTION(Category = "Listener", BlueprintCallable)
	static bool OverrideListener(AActor* Actor, const FVector Loc = FVector::ZeroVector, const FRotator Rot = FRotator::ZeroRotator);

	/**
	 * Back listener to controller location and rotation
	 */
	UFUNCTION(Category = "Listener", BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static bool ClearOverrideListener(UObject* WorldContextObject);

};
