// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/PointLightComponent.h"
#include "CPPConstructionScript.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPConstructionScript : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPConstructionScript();

	//Scene Component
	UPROPERTY(EditAnywhere)
		USceneComponent* DefaultSceneRoot;

	//Static Mesh Component
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;

	//Arrow Component
	UPROPERTY(VisibleAnywhere)
		UArrowComponent* Arrow;

	//PointLight Component
	UPROPERTY(EditAnywhere)
		UPointLightComponent* PointLight;

	UPROPERTY(EditAnywhere, Category = "Point Light")
		bool bIsVisible = false;

	UPROPERTY(EditAnywhere, Category = "Point Light")
		float Intensity = 5000.0f;

	UPROPERTY(EditAnywhere, Category = "Point Light")
		FLinearColor LightColor = FLinearColor::Green;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//•\Ž¦/”ñ•\Ž¦
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	//PrintString—p
	const float Duration = 10.0f;
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

};
