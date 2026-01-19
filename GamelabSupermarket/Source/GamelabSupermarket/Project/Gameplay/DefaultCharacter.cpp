#include "DefaultCharacter.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ADefaultCharacter::ADefaultCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADefaultCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D Movementvector = Value.Get<FVector2D>();
	const FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, Movementvector.Y);
	const FVector Right = GetActorRightVector();
	AddMovementInput(Right, Movementvector.X);
}

void ADefaultCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void ADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


