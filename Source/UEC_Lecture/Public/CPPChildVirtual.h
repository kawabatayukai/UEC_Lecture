// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPParentVirtual.h"
#include "CPPChildVirtual.generated.h"

/**
 * 
 */
UCLASS()
class UEC_LECTURE_API ACPPChildVirtual : public ACPPParentVirtual
{
	GENERATED_BODY()
	
public:
	void SetPoint(int myPoint) override;
};
