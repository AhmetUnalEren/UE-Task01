// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cell.h"
#include "Bacteria.generated.h"

/**
 * 
 */
UCLASS()
class UE_TASK01_API ABacteria : public ACell
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	void Division();
	virtual void BeginPlay() override;
	FTimerHandle TimerHandle_Division;
};
