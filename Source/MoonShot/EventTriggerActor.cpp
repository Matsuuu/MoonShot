// Fill out your copyright notice in the Description page of Project Settings.


#include "EventTriggerActor.h"
#include "MoonShotUtility.h"
#include "Engine/Canvas.h"
#include "PaperSpriteComponent.h"
#include "MoonShotCharacter.h"

// Sets default values
AEventTriggerActor::AEventTriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    ButtonSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ButtonSprite"));
    ButtonSprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEventTriggerActor::BeginPlay()
{
	Super::BeginPlay();

    OnActorBeginOverlap.AddDynamic(this, &AEventTriggerActor::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AEventTriggerActor::OnOverlapEnd);
    ButtonSprite->SetVisibility(false);
}

// Called every frame
void AEventTriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AEventTriggerActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor enters trigger box
        printFString("Overlapped Actor is %s", *OtherActor->GetName());
       
        if (OverlapperIsPlayer(OtherActor)) {
            ButtonSprite->SetVisibility(true);
            GetPlayerCharacterPointer(OtherActor)->CanInteractEnter(this);
        }
    }
}

void AEventTriggerActor::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor leaves trigger box
        printFString("%s has left the Trigger Box", *OtherActor->GetName());
        if (OverlapperIsPlayer(OtherActor)) {
            ButtonSprite->SetVisibility(false);
            GetPlayerCharacterPointer(OtherActor)->CanInteractExit();
        }
    }
}

AMoonShotCharacter* AEventTriggerActor::GetPlayerCharacterPointer(AActor* OtherActor) {
    AMoonShotCharacter* Character = Cast<AMoonShotCharacter>(OtherActor);
    return Character;
}

bool AEventTriggerActor::OverlapperIsPlayer(AActor* Actor) {
    bool IsPlayer = false;
    for (FName tag : Actor->Tags) {
        if (tag.ToString() == "Player") {
            IsPlayer = true;
            break;
        }
    }
    return IsPlayer;
}
