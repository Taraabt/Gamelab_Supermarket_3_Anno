#include "Project/Gameplay/Slot.h"

ASlot::ASlot()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASlot::BeginPlay()
{
	Super::BeginPlay();
}

void ASlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ===== ADD TAG =====

void ASlot::AddSlotTag(FGameplayTag Tag)
{
	GameplayTags.AddTag(Tag);
}

// ===== REMOVE TAG =====

void ASlot::RemoveSlotTag(FGameplayTag Tag)
{
	GameplayTags.RemoveTag(Tag);
}

// ===== EQS INTERFACE =====

void ASlot::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = GameplayTags;
}