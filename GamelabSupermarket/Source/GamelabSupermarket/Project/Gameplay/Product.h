// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Product.generated.h"

UCLASS()
class GAMELABSUPERMARKET_API AProduct : public AActor
{
	GENERATED_BODY()
	
public:	

	AProduct();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite)
	FString name;



protected:

	virtual void BeginPlay() override;

};
