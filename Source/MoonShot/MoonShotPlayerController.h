// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MoonShotPlayerController.generated.h"

UCLASS()
class AMoonShotPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMoonShotPlayerController();

protected:
	class AMoonShotCharacter* CharacterRef;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlayingState() override;
	// End PlayerController interface
	void OnSetJumpPressed();
	void OnSetJumpReleased();
	void OnInteract();

	UFUNCTION()
		void MoveForward(float Value);
	UFUNCTION()
		void MoveRight(float Value);

	void LookAtCursor();
};


