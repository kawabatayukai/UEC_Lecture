// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPPBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UEC_LECTURE_API UCPPBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	//FunctionLibrary	
	//static�֐��ŃO���[�o���֐��I��

public:
	UFUNCTION(BlueprintCallable, Category = "CPPBlueprintunctionLibrary")
		static void PrintHello();
};
