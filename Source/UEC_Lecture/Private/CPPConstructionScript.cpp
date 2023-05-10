// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructionScript.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPConstructionScript::ACPPConstructionScript()
{
	//SceneComponent�̍쐬
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	//SceneComponet��RootComponent��
	RootComponent = DefaultSceneRoot;

	//StaticMeshComponent���쐬
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	StaticMesh->SetupAttachment(RootComponent);

	// ArrowComponent���쐬����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	// ArrowComponent�̈ʒu��ݒ肷��
	Arrow->SetRelativeLocation(FVector(30.0f, 0.0f, 0.0f));

	// ArrowComponent��StaticMeshComponent��Attach����
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponent���쐬����
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	// PointLightComponent�̈ʒu��ݒ肷��
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	// PointLightComponent��StaticMeshComponent��Attach����
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPConstructionScript::BeginPlay()
{
	Super::BeginPlay();


	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Text�̃J���[���ɕϐ�TextColor��ݒ�
		, Duration
	);
}

void ACPPConstructionScript::OnConstruction(const FTransform& Transform)
{
	//�\��/��\��
	PointLight->SetVisibility(bIsVisible);
	//���̋���
	PointLight->SetIntensity(Intensity);
	//�F
	PointLight->SetLightColor(LightColor);
}
