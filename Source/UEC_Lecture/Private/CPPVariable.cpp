// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"   //�L���X�g���邽��

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();
	
	//�ϐ���錾����
	FString Message = "Variable C++ Hello World";

	//�^�ϊ��@�@UKismetStringLibrary::Conv

	UKismetSystemLibrary::PrintString(this, UKismetStringLibrary::Conv_FloatToString(Duration)
		, true, true, TextColor, Duration);
}


