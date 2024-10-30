// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include <Components/BoxComponent.h>
#include <GameFramework/Character.h>

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// Iscrizione all'evento
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ADoor::BoxCollider_OnComponentBeginOverlap);
	
}

void ADoor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Disincrizione all'evento
	BoxCollider->OnComponentBeginOverlap.RemoveDynamic(this, &ADoor::BoxCollider_OnComponentBeginOverlap);
}

void ADoor::BoxCollider_OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (IsValid(Character))
	{
		UE_LOG(LogTemp, Display, TEXT("PORTA!"));
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


