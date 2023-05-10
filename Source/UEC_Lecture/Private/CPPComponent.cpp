// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

//コンストラクタ
ACPPComponent::ACPPComponent()
{
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponentを作成   CreateDefaultSubobjectでオブジェクトを作成(オブジェクト名)
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponentをRootComponentに設定する
	// 親クラスActor のメンバ変数に代入
	RootComponent = DefaultSceneRoot;

	//StaticMeshオブジェクトを作成
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	//StaticMeshをLoad
	UStaticMesh* mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(mesh);

	//StaticMeshをRootComponentにAttachする
	StaticMesh->SetupAttachment(RootComponent);

	//ArrowComponentを作成
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	//ArrowComponentの位置を決定
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));

	//ArrowComponentをStaticMeshにAttach
	Arrow->SetupAttachment(StaticMesh);

	//PointLightComponentを作成
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	//位置を決定
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	//staticMeshにAttach
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}


