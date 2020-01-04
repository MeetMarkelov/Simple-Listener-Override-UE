// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleLisneterOverrideStatics.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "SimpleLisneterOverrideComponent.h"

// USimpleLisneterOverrideStatics

bool USimpleLisneterOverrideStatics::OverrideListener(AActor* Actor, const FVector Loc, const FRotator Rot)
{
	if (!Actor)
		return false;

	USimpleLisneterOverrideComponent* SimpleListener = Cast<USimpleLisneterOverrideComponent>(Actor->GetComponentByClass(USimpleLisneterOverrideComponent::StaticClass()));

	if (!SimpleListener)
		return false;

	return SimpleListener->OverrideListener(Loc, Rot);
}

bool USimpleLisneterOverrideStatics::ClearOverrideListener(UObject* WorldContextObject)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);

	if (!PC)
		return false;

	PC->ClearAudioListenerOverride();

	return true;
}