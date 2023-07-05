// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPStatic.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPStatic : public AActor
{
	GENERATED_BODY()
	
public:
	// staticメンバ関数
	static void SetPoint(int myPoint);

	//静的メンバ変数
	static int staticPoint;

	//通常のメンバ変数
	int normalPoint;
};
