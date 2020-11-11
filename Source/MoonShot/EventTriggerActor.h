// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerBox.h"
#include "EventTriggerActor.generated.h"

UCLASS()
class MOONSHOT_API AEventTriggerActor : public ATriggerBox
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventTriggerActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UPaperSpriteComponent* ButtonSprite;

	bool OverlapperIsPlayer(class AActor* Actor);

	class AMoonShotCharacter* GetPlayerCharacterPointer(class AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool CanInteract = false;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "HandleInteraction"))
		void Interact();
};
