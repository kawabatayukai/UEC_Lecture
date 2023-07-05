// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractBPParent.h"

// Called when the game starts or when spawned
void ACPPAbstractBPParent::BeginPlay()
{
	Super::BeginPlay();
	
	// 挨拶する
	Greeting();
}

//C++ で実装する関数には_Implementationをつける
void ACPPAbstractBPParent::Greeting_Implementation()
{
	//BPで拡張しない際に呼び出される
}