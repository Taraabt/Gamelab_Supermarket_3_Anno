// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBox.generated.h"

UCLASS()
class GAMELABSUPERMARKET_API AMyBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBox();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Box")
	int MaxProdotti = 3;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Box")
	TArray<AProduct*> Prodotti;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
