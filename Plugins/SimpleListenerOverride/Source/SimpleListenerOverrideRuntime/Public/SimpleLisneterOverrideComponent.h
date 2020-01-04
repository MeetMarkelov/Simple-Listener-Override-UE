// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "SimpleLisneterOverrideComponent.generated.h"

class UArrowComponent;

/**
 * Component that allow you easily override listener parent component, location and rotation
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

	/**
	 * Set listener position to Simple Lisneter Override Component location and rotation
	 * Loc - Additional location
	 * Rot - Additional rotation
	 */
	UFUNCTION(Category = "Listener", BlueprintCallable)
	bool OverrideListener(const FVector Loc = FVector::ZeroVector, const FRotator Rot = FRotator::ZeroRotator);

#if WITH_EDITOR

	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;

#endif

private:

#if WITH_EDITORONLY_DATA
	
	UPROPERTY()
	UArrowComponent* ArrowComponent;

	UPROPERTY(Category = "Listener", EditAnywhere)
	bool bArrowVisible = true;

	UPROPERTY(Category = "Listener", EditAnywhere)
	bool bArrowHiddenInGame = true;

#endif
	
};