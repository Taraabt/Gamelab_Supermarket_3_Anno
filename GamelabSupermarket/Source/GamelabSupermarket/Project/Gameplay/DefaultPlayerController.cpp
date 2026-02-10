#include "DefaultPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "DefaultCharacter.h"

void ADefaultPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!IsLocalController()) return;

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer) return;

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	if (Subsystem && DefaultMappingContext)
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ADefaultPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(InputComponent);

	if (!EnhancedInput) return;

	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADefaultPlayerController::HandleMove);

	EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ADefaultPlayerController::HandleJump);
	EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ADefaultPlayerController::HandleStopJump);
}

void ADefaultPlayerController::HandleMove(const FInputActionValue& Value)
{
	if (ADefaultCharacter* MyCharacter = Cast<ADefaultCharacter>(GetPawn()))
	{
		MyCharacter->Move(Value);
	}
}


void ADefaultPlayerController::HandleJump()
{
	if (ACharacter* MyCharacter = Cast<ACharacter>(GetPawn()))
	{
		MyCharacter->Jump();
	}
}

void ADefaultPlayerController::HandleStopJump()
{
	if (ACharacter* MyCharacter = Cast<ACharacter>(GetPawn()))
	{
		MyCharacter->StopJumping();
	}
}
