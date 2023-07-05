// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPInterface.generated.h"

// This class does not need to be modified.
//�G���W����Interface�N���X��F��
UINTERFACE(MinimalAPI)
class UCPPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface�N���X�{��
 */
class UEC_LECTURE_API ICPPInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// �����Ɩ߂�l���Ȃ������o�֐�
	virtual void PrintHello();

	// �����Ɩ߂�l�����郁���o�֐�
	virtual int Add(int A, int B);
};