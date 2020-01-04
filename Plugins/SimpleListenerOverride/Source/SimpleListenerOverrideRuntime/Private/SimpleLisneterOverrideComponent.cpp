// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleLisneterOverrideComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/ArrowComponent.h"

USimpleLisneterOverrideComponent::USimpleLisneterOverrideComponent(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("ListenerArrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor::Red;
		ArrowComponent->bTreatAsASprite = true;
		ArrowComponent->SetupAttachment(this);
		ArrowComponent->bIsScreenSizeScaled = true;
		ArrowComponent->SetEditorScale(1.5f);
		ArrowComponent->bHiddenInGame = false;
		ArrowComponent->SetVisibility(true);
		ArrowComponent->SetHiddenInGame(true);
	}
#endif // WITH_EDITORONLY_DATA
}

bool USimpleLisneterOverrideComponent::OverrideListener(const FVector Loc, const FRotator Rot)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

	if (!PC)
		return false;

	PC->SetAudioListenerOverride(this, Loc, Rot);

	return true;
}

#if WITH_EDITOR

void USimpleLisneterOverrideComponent::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Listener: PostEditChangeChainProperty"));

#if WITH_EDITORONLY_DATA
	if (ArrowComponent)
	{
		ArrowComponent->SetVisibility(bArrowVisible);
		ArrowComponent->SetHiddenInGame(bArrowHiddenInGame);
	}
#endif
};

#endif