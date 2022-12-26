// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class REDHOODADVENTURE_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		float GetHealth();
	UFUNCTION(BlueprintCallable)
		float GetDefalutHealth();
	UFUNCTION(BlueprintCallable)
		void StartFBTimer();
	UFUNCTION(BlueprintCallable)
		void EndFBTimer();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tick")
		int WidgetFlipbookTimer = 0;
protected:
	FTimerHandle FBTimerHandle;
	void IncFBTimer();
};
