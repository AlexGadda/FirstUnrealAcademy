// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyCpp.h"
#include "Door.h"
#include "Components/SphereComponent.h"

// Sets default values
AKeyCpp::AKeyCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("BoxCollider"));
	SphereCollider->SetupAttachment(DefaultRoot);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(DefaultRoot);
}

// Called when the game starts or when spawned
void AKeyCpp::BeginPlay()
{
	Super::BeginPlay();

	// Subscribe to overlap event
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AKeyCpp::SphereCollider_OnComponentBeginOverlap);
	
}

void AKeyCpp::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Un-subscribe to overlap event
	SphereCollider->OnComponentBeginOverlap.RemoveDynamic(this, &AKeyCpp::SphereCollider_OnComponentBeginOverlap);
}

// Called every frame
void AKeyCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKeyCpp::SphereCollider_OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Door->SetHasKey();
	Destroy();
}
