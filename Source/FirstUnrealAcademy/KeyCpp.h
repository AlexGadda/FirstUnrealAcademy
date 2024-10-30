// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyCpp.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class ADoor; // Speed up compilation time (better than include)

UCLASS()
class FIRSTUNREALACADEMY_API AKeyCpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyCpp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Config")
	TObjectPtr<ADoor> Door;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void SphereCollider_OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> SphereCollider; // Potevo anche farlo come puntatore UBoxComponent*, ma questo è meglio in UE5 per il g.c.

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> StaticMesh; 	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
