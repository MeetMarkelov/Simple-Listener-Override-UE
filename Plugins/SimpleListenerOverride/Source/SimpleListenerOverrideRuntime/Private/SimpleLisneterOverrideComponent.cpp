// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleLisneterOverrideComponent.h"
#include "Kismet/GameplayStatics.h"

USimpleLisneterOverrideComponent::USimpleLisneterOverrideComponent(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	//
}

bool USimpleLisneterOverrideComponent::OverrideListener()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

	if (!PC)
		return false;

	PC->SetAudioListenerOverride(this, FVector::ZeroVector, FRotator::ZeroRotator);

	return true;
}