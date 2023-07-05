// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractParent.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPAbstractParent::BeginPlay()
{
	Super::BeginPlay();
	
	// ˆ¥ŽA‚·‚é
	Greeting(GreetingMessage);
}
