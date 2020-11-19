// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogWidget.h"
#include "MoonShotUtility.h"
#include "Components/TextBlock.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "MoonShotPlayerController.h"

void UDialogWidget::NativeConstruct() {
	Super::NativeConstruct();
	if (DialogText != nullptr) {
		AMoonShotPlayerController* Player = Cast<AMoonShotPlayerController>(GetWorld()->GetFirstPlayerController());
		if (Player != nullptr) {
			Player->DialogOpened(this);
		}
		DialogText->SetText(FText::FromString(""));
		PrintedCharacterCount = 0;
		AddLetter();
	}
}

void UDialogWidget::SetMessage(FString DialogMessage) {
	Message = DialogMessage;
}

void UDialogWidget::AddLetter() {
	PrintedCharacterCount++;
	DialogText->SetText(FText::FromString(Message.Left(PrintedCharacterCount)));
	if (PrintedCharacterCount < Message.Len()) {
		GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &UDialogWidget::AddLetter, 0.02f, false);
	}
}

UDialogWidget* UDialogWidget::Spawn(APlayerController* PlayerController, FString DialogMessage) {
	// TODO: Keksi miten t‰‰ll‰ voisi spawnata blueprint version
	// TODO: K‰yt‰ AMoonShotPlayerController* Player = Cast<AMoonShotPlayerController>(GetWorld()->GetFirstPlayerController()); ‰l‰k‰ ota parametrina
	UDialogWidget* ThisDialogWidget = CreateWidget<UDialogWidget>(PlayerController, UDialogWidget::StaticClass());
	print("Spawn called");
	if (ThisDialogWidget) {
		ThisDialogWidget->AddToViewport(99999);

		print("YES");
	}
	else {
		print("Nope");
	}
	return ThisDialogWidget;
}