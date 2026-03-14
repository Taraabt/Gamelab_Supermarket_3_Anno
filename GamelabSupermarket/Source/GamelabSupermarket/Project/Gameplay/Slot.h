#pragma once

#include "CoreMinimal.h"
#include "Product.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Slot.generated.h"

UCLASS()
class GAMELABSUPERMARKET_API ASlot : public AActor, public IInteractable, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	ASlot();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	// Evento Blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Interact(ACharacter* Interactor);

public:

	// Container interno dei Gameplay Tags
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Tags")
	FGameplayTagContainer GameplayTags;

	// ===== FUNZIONI PER BLUEPRINT =====

	UFUNCTION(BlueprintCallable, Category = "Gameplay Tags")
	void AddSlotTag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category = "Gameplay Tags")
	void RemoveSlotTag(FGameplayTag Tag);

	// ===== INTERFACCIA EQS =====

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
};