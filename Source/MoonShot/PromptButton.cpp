// Fill out your copyright notice in the Description page of Project Settings.


#include "PromptButton.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/Object.h"

// Sets default values
APromptButton::APromptButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APromptButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APromptButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

