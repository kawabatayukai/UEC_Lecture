// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPBlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void UCPPBlueprintFunctionLibrary::PrintHello()
{
	// HeloÇèoóÕÇ∑ÇÈ
	UKismetSystemLibrary::PrintString(NULL, FString::Printf(TEXT("Hello")), true, true, FColor::Cyan, 10.f);
}