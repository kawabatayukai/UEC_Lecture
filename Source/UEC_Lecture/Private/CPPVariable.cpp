// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"   //キャストするため

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();
	
	//変数を宣言する
	FString Message = "Variable C++ Hello World";

	//型変換　　UKismetStringLibrary::Conv

	UKismetSystemLibrary::PrintString(this, UKismetStringLibrary::Conv_FloatToString(Duration)
		, true, true, TextColor, Duration);
}


