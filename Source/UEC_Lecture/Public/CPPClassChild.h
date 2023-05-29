// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPClassBase.h"
#include "CPPClassChild.generated.h"

/**
 * 
 */
UCLASS()
class UEC_LECTURE_API ACPPClassChild : public ACPPClassBase
{
	GENERATED_BODY()

public:
	ACPPClassChild();

protected:
	virtual void BeginPlay() override;

public:
	// 子クラスのメンバ関数 
	void CallChildFunc();

	// 子クラスのデータメンバ
	int VarChildNum = 100;
};
