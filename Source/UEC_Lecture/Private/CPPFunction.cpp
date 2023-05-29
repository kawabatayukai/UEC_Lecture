// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFunction.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"


// Called when the game starts or when spawned
void ACPPFunction::BeginPlay()
{
	Super::BeginPlay();
	
	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintString�m�[�h�Ɠ�������
		// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
	}
}


int32 ACPPFunction::Sum(int32 A, int32 B)
{
	int32 LocalResult = A + B;
	return LocalResult;
}

//�v�Z���ʂ��擾
void ACPPFunction::PrintCalcResult(const ECPPCalcType& Type, const int32& A, const int32& B, const float& PrintDuration)
{
	switch (Type)
	{
	case ECPPCalcType::Add:
	{
		// Add(�����Z)�̏���
		int32 ResultAdd = Sum(CalcVarA, CalcVarB);
		FString StrResultAdd = FString::Printf(TEXT("Sum : %d + %d = %d"), CalcVarA, CalcVarB, ResultAdd);
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
		// Subtract(�����Z)�̏���
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
		// Multiply(�|���Z)�̏���
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
		// Divide(����Z)�̏���
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