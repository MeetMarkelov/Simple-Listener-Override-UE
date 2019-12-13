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

	UFUNCTION(Category = "Listener", BlueprintCallable)
	static bool OverrideListener(AActor* Actor);

	UFUNCTION(Category = "Listener", BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static bool ClearOverrideListener(UObject* WorldContextObject);

};
