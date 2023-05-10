// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"   //ArrowComponent�̎g�p
#include "Components/PointLightComponent.h"
#include "CPPComponent.generated.h"      //�}�N�����܂ނ��߈�ԉ�

UCLASS()
class UEC_LECTURE_API ACPPComponent : public AActor
{
	GENERATED_BODY()
public:
	ACPPComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//PrintString�\������
	const float Duration = 10.0f;

	//�F
	const FColor TextColor = FColor(255, 0, 255);

public:
	//Scene Component
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;

	//Static Mesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	//ArrowComponent
	UPROPERTY(VisibleAnywhere)
	UArrowComponent* Arrow;

	//PointLightComponent
	UPROPERTY(EditAnywhere)
	UPointLightComponent* PointLight;
};
