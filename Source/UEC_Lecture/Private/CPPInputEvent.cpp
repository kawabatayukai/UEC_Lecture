// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPInputEvent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

int32 ACPPInputEvent::Sum(int32 A, int32 B)
{
	return A + B;
}


// Called when the game starts or when spawned
void ACPPInputEvent::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();

	if (IsPrintHello)
	{
		// PrintString�m�[�h�Ɠ�������
		// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		// �v�Z���ʂ��o�͂��鏈��
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
	}

}

//�v�Z���ʂ��擾
void ACPPInputEvent::PrintCalcResult(const ECPPCalcType& Type, const int32& A, const int32& B, const float& PrintDuration)
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

void ACPPInputEvent::PressedActionPrintCalcResult()
{
	// �v�Z���ʂ��o�͂��鏈��
	PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
}

void ACPPInputEvent::AxisEventPrint(float Rate)
{
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}

void ACPPInputEvent::SetupInput()
{
	// ���͂�L���ɂ���
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// H�L�[��Pressed��Released���o�C���h����
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPInputEvent::PressedH);
	//InputComponent->BindKey(EKeys::H, IE_Released, this, &ACPPInputEvent::ReleasedH);

	// ActionMappings�ɐݒ肵��Action���o�C���h����
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPInputEvent::PressedActionPrintCalcResult);
	InputComponent->BindAxis("MoveForward", this, &ACPPInputEvent::AxisEventPrint);
}

void ACPPInputEvent::PressedH()
{
	// Hello World!���o�͂��鏈��
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}

void ACPPInputEvent::ReleasedH()
{
	// �v�Z���ʂ��o�͂��鏈��
	PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
}