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

	// 派生クラスで値を設定する
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FString GreetingMessage;
public:	

	//C++ BP どちらでも実装できる
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Greeting();
};
