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
}

void ADefaultPlayerController::HandleMove(const FInputActionValue& Value)
{
	if (ADefaultCharacter* MyCharacter = Cast<ADefaultCharacter>(GetPawn()))
	{
		MyCharacter->Move(Value);
	}
}
void ADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}