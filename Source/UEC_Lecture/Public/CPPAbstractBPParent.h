// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAbstractBPParent.generated.h"

UCLASS(BlueprintType, Blueprintable, Abstract)
class UEC_LECTURE_API ACPPAbstractBPParent : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// �h���N���X�Œl��ݒ肷��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FString GreetingMessage;
public:	

	//C++ BP �ǂ���ł������ł���
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Greeting();
};
