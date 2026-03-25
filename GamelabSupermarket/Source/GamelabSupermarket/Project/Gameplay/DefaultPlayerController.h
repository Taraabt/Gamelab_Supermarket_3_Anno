#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "DefaultPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class GAMELABSUPERMARKET_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/* ===== OVERRIDES ===== */
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	/* ===== INPUT ASSETS ===== */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	/* ===== INPUT HANDLERS ===== */
	void HandleMove(const FInputActionValue& Value);


};
