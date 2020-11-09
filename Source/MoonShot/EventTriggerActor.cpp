// Fill out your copyright notice in the Description page of Project Settings.


#include "EventTriggerActor.h"
#include "DrawDebugHelpers.h"
#include "MoonShotUtility.h"
#include "Engine/Canvas.h"

// Sets default values
AEventTriggerActor::AEventTriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    

	OnActorBeginOverlap.AddDynamic(this, &AEventTriggerActor::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AEventTriggerActor::OnOverlapEnd);


	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
}

// Called when the game starts or when spawned
void AEventTriggerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEventTriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AEventTriggerActor::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor enters trigger box
        printFString("Overlapped Actor = %s", *OtherActor->GetName());
        FString tagString = "";
        for (FName tag : OtherActor->Tags) {
            tagString += *tag.ToString();
        }
        printFString("Actor tags: %s", *tagString);
    }
}

void AEventTriggerActor::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor leaves trigger box
        printFString("%s has left the Trigger Box", *OtherActor->GetName());
    }
}