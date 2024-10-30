// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include <Components/BoxComponent.h>
#include <GameFramework/Character.h>

float LerpDamperAlpha(float halflife, float dt, float eps=1e-5f)
{
	return 1.0f - FMath::Exp(-(0.69314718056f * dt) / (halflife + eps));
}

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(DefaultRoot);
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DefaultRoot);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// Subscribe to the event
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ADoor::BoxCollider_OnComponentBeginOverlap);
}

void ADoor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Un-subscribe from the event
	BoxCollider->OnComponentBeginOverlap.RemoveDynamic(this, &ADoor::BoxCollider_OnComponentBeginOverlap);
}

void ADoor::BoxCollider_OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Is the other actor a character?
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (IsValid(Character))
	{
		// Does the player have a key?
		if(bHasKey)
		{
			// If so, open the door
			Door->SetRelativeRotation(FRotator(0, 90, 0));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Door opened"));	
		}
		else
		{
			// Else print a reminder
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("You need a key!"));	
		}
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

