// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPEventDispatcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPEventDispatcher::ACPPEventDispatcher()
{
	OnPrintHello.AddDynamic(this, &ACPPEventDispatcher::PrintHello);
}

void ACPPEventDispatcher::PrintHello()
{
	// Hello World!を出力する処理
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}

int32 ACPPEventDispatcher::Sum(int32 A, int32 B)
{
	return A + B;
}

// Called when the game starts or when spawned
void ACPPEventDispatcher::BeginPlay()
{
	SetupInput();

	if (IsPrintHello)
	{
		// PrintStringノードと同じ処理
		// UKismetSystemLibraryクラスのPrintString関数を呼び出す
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		// 計算結果を出力する処理
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
	}
}

void ACPPEventDispatcher::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
	case ECPPCalcType::Add:
	{
		// Add(足し算)の処理
		int32 ResultAdd = Sum(CalcVarA, CalcVarB);
		FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultAdd
			, true
			, true
			, FColor::Red
			, Duration
			);
		break;
	}
	case ECPPCalcType::Subtract:
	{
		// Subtract(引き算)の処理
		int32 ResultSubtract = CalcVarA - CalcVarB;
		FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultSubtract
			, true
			, true
			, FColor::Yellow
			, Duration
			);
		break;
	}
	case ECPPCalcType::Multiply:
	{
		// Multiply(掛け算)の処理
		int32 ResultMultiply = CalcVarA * CalcVarB;
		FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultMultiply
			, true
			, true
			, FColor::Green
			, Duration
			);
		break;
	}
	case ECPPCalcType::Divide:
	{
		// Divide(割り算)の処理
		float ResultDivide = (float)CalcVarA / (float)CalcVarB;
		FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultDivide
			, true
			, true
			, FColor::Blue
			, Duration
			);
		break;
	}
	}
}

void ACPPEventDispatcher::SetupInput()
{
	// 入力を有効にする
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HキーのPressedとReleasedをバインドする
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPEventDispatcher::PressedH);

	// ActionMappingsに設定したActionをバインドする
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPEventDispatcher::PressedActionPrintCalcResult);
}

void ACPPEventDispatcher::PressedH()
{
	// Hello World!を出力する処理
	//UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);

	// Event Dispathcer[OnPrintHello]をコールする
	OnPrintHello.Broadcast();
}

void ACPPEventDispatcher::PressedActionPrintCalcResult()
{
	// 計算結果を出力する処理
	PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
}


