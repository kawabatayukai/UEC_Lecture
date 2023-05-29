// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPCalcInfo.h" 
#include "CPPStructure.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPStructure : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPStructure();

	// Event Dispatcher[OnPrintHello]
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);

	UPROPERTY(BlueprintAssignable, Category = "CPP_BP")
		FPrintHelloDelegate OnPrintHello;

	// Custom Event[PrintHello] 
	UFUNCTION()
		void PrintHello();

	int32 Sum(int32 A, int32 B);

	// Action Mappings�ɐݒ肵��Action����������֐�
	void PressedActionPrintCalcResult();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<FString> Messages = { TEXT("C++ Hello World!"), TEXT("aa"), TEXT("Bonjour le monde!"), TEXT("Hallo Welt!"), TEXT("����ɂ��͐��E!") };

	// �v�Z���ʂ��o�͂���֐�
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FColor(255, 255, 255);

	// �v�Z�p�̕ϐ�
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control�p�̕ϐ�
	bool IsPrintHello = false;
	int32 TypeIndex = 0;
	TArray<ECPPCalcType> CalcTypes = { ECPPCalcType::Add, ECPPCalcType::Subtract, ECPPCalcType::Multiply, ECPPCalcType::Divide };

	// Input�ݒ�
	void SetupInput();

	// Input Event����������֐�
	void PressedH();

	// �����ɍ\���̂��g�p�����v�Z���ʂ��o�͂���֐�
	void PrintCalcResultArgStructure(const FCPPCalcInfo& CalcInfo, const float PrintDuration);

	TArray<FCPPCalcInfo> CalcInfos = { {ECPPCalcType::Add, 7, 3}
								 , {ECPPCalcType::Subtract, 7, 3}
								 , {ECPPCalcType::Multiply, 7, 3}
								 , {ECPPCalcType::Divide, 7, 3}
	};
};
