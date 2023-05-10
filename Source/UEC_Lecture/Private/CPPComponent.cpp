// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

//�R���X�g���N�^
ACPPComponent::ACPPComponent()
{
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponent���쐬   CreateDefaultSubobject�ŃI�u�W�F�N�g���쐬(�I�u�W�F�N�g��)
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	// �e�N���XActor �̃����o�ϐ��ɑ��
	RootComponent = DefaultSceneRoot;

	//StaticMesh�I�u�W�F�N�g���쐬
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	//StaticMesh��Load
	UStaticMesh* mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(mesh);

	//StaticMesh��RootComponent��Attach����
	StaticMesh->SetupAttachment(RootComponent);

	//ArrowComponent���쐬
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	//ArrowComponent�̈ʒu������
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));

	//ArrowComponent��StaticMesh��Attach
	Arrow->SetupAttachment(StaticMesh);

	//PointLightComponent���쐬
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	//�ʒu������
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	//staticMesh��Attach
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}


