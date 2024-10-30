// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class UBoxComponent; // Questo esiste! (Forward Declaration)

UCLASS()
class FIRSTUNREALACADEMY_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UFUNCTION()
	void BoxCollider_OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetHasKey() { bHasKey = true; }

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> BoxCollider; // Potevo anche farlo come puntatore UBoxComponent*, ma questo è meglio in UE5 per il g.c.

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Door; 	
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bHasKey = false;
};
