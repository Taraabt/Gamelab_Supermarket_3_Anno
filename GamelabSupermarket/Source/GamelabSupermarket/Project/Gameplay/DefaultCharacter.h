#pragma once

#include "CoreMinimal.h"
#include "Product.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "DefaultCharacter.generated.h"

class UInputMappingContext;
class UInputAction;


UCLASS()
class GAMELABSUPERMARKET_API ADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADefaultCharacter();


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value);



};
