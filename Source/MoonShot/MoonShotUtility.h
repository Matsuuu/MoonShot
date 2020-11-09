// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))
#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MOONSHOT_API MoonShotUtility
{
public:
	MoonShotUtility();
	~MoonShotUtility();
};
