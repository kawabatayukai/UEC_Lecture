// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAbstractParent.h"
#include "CPPAbstractChild.generated.h"

/**
 * 
 */
UCLASS()
class UEC_LECTURE_API ACPPAbstractChild : public ACPPAbstractParent
{
	GENERATED_BODY()
	
public:

	//ˆ¥ŽA‚·‚é
	void Greeting(FString message) override;
};
