// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoonShotPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "MoonShotCharacter.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

AMoonShotPlayerController::AMoonShotPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AMoonShotPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	LookAtCursor();

}

void AMoonShotPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMoonShotPlayerController::OnSetJumpPressed);
	InputComponent->BindAction("Jump", IE_Released, this, &AMoonShotPlayerController::OnSetJumpReleased);

	InputComponent->BindAxis("MoveForward", this, &AMoonShotPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMoonShotPlayerController::MoveRight);
}

void AMoonShotPlayerController::OnSetJumpPressed() {
	GetCharacter()->Jump();
}

void AMoonShotPlayerController::OnSetJumpReleased() {
	GetCharacter()->StopJumping();
}

void AMoonShotPlayerController::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X);
	GetCharacter()->AddMovementInput(Direction, Value);
}

void AMoonShotPlayerController::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y);
	GetCharacter()->AddMovementInput(Direction, Value);
}

void AMoonShotPlayerController::LookAtCursor()
{
	FHitResult TraceResult(ForceInit);
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, TraceResult);
	GetCharacter()->SetActorRotation(FRotator(0, UKismetMathLibrary::FindLookAtRotation(GetCharacter()->GetActorLocation(), TraceResult.Location).Yaw, 0), ETeleportType::None);
}
