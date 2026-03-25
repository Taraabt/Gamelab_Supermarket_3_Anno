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
    const FVector2D MovementVector = Value.Get<FVector2D>();

    if (!Controller) return;

    // Direzioni rispetto alla camera/controller
    const FRotator ControlRotation = Controller->GetControlRotation();
    const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

    const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    FVector MoveDirection = (Forward * MovementVector.Y) + (Right * MovementVector.X);

    if (!MoveDirection.IsNearlyZero())
    {
        AddMovementInput(MoveDirection);

        // Ruota il personaggio verso la direzione di movimento
        FRotator NewRotation = MoveDirection.Rotation();
        NewRotation.Pitch = 0.f;
        NewRotation.Roll = 0.f;

        SetActorRotation(NewRotation);
    }
}



