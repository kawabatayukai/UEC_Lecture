// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractBPParent.h"

// Called when the game starts or when spawned
void ACPPAbstractBPParent::BeginPlay()
{
	Super::BeginPlay();
	
	// ���A����
	Greeting();
}

//C++ �Ŏ�������֐��ɂ�_Implementation������
void ACPPAbstractBPParent::Greeting_Implementation()
{
	//BP�Ŋg�����Ȃ��ۂɌĂяo�����
}