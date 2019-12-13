// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "SimpleLisneterOverrideComponent.generated.h"

/**
 * Plus X axis (Red) - Front 
 * Plus Y axis (Green) - Right
 * Plus Z axis (Blue) - Top
 */
UCLASS(ClassGroup = ("Listener"), BlueprintType, meta = (BlueprintSpawnableComponent))
class SIMPLELISTENEROVERRIDERUNTIME_API USimpleLisneterOverrideComponent : public USceneComponent
{
	GENERATED_BODY()
	
public:

	USimpleLisneterOverrideComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(Category = "Listener", BlueprintCallable)
	bool OverrideListener();
	
};