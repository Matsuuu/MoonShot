// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogWidget.generated.h"

/**
 * 
 */
UCLASS()
class MOONSHOT_API UDialogWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	int PrintedCharacterCount = 0;
	FString Message;
	FTimerHandle UnusedHandle;
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* DialogText;

	void DisplayMessage(FString DialogMessage);

	void AddLetter();

	UFUNCTION(BlueprintCallable)
	void SetMessage(FString DialogMessage);

	UFUNCTION(BlueprintCallable)
		static UDialogWidget* Spawn(APlayerController* SpawningActor, FString DialogMessage);
};
