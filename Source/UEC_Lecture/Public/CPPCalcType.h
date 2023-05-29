// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * —ñ‹“Œ^‚Í.h‚Ì‚Ý
 */
UENUM(BlueprintType)
enum class ECPPCalcType : uint8
{
	Add       UMETA(DisplayName = "Addition"),
	Subtract  UMETA(DisplayName = "Subtraction"),
	Multiply  UMETA(DisplayName = "Multiplicatation"),
	Divide    UMETA(DisplayName = "Division"),
};

