// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
class UUserWidget;
UCLASS()
class REDHOODADVENTURE_API ABaseHUD : public AHUD
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void OnPlayerDead();
	UFUNCTION(BlueprintCallable)
		void OpenEscMenu();
	UFUNCTION(BlueprintCallable)
		void CloseEscMenu();
	UFUNCTION(BlueprintCallable)
		void OpenHealthBar();
	UFUNCTION(BlueprintCallable)
		void CloseHealthBar();
	UFUNCTION(BlueprintCallable)
		void OpenDeadScreen();
	UFUNCTION(BlueprintCallable)
		void CloseDeadScreen();
	UFUNCTION(BlueprintCallable)
		void OpenEnhanceChoice();
	UFUNCTION(BlueprintCallable)
		void CloseEnhanceChoice();
	UFUNCTION(BlueprintCallable)
		void OpenWinningWidget();
	UFUNCTION(BlueprintCallable)
		void CloseWinningWidget();
	UFUNCTION(BlueprintCallable)
		void OpenCreditsWidget();
	UFUNCTION(BlueprintCallable)
		void CloseCreditsWidget();
	UFUNCTION(BlueprintCallable)
		UUserWidget* GetHealthBar();
	UFUNCTION(BlueprintCallable)
		UUserWidget* GetEscMenu();
	UFUNCTION(BlueprintCallable)
		UUserWidget* GetDeadScreen();
	UFUNCTION(BlueprintCallable)
		UUserWidget* GetEnhanceWidget();
	UFUNCTION(BlueprintCallable)
		UUserWidget* GetWinningWidget();
	UFUNCTION(BlueprintCallable)
		UUserWidget* GetCreditsWidget();
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "UI")
		TSubclassOf<UUserWidget> HealthBarClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> EscMenuClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> DeadScreenClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> EnhanceWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> WinningWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> CreditsWidgetClass;
	TObjectPtr<UUserWidget> HealthBar = nullptr;
	TObjectPtr<UUserWidget> EscMenu = nullptr;
	TObjectPtr<UUserWidget> DeadScreen = nullptr;
	TObjectPtr<UUserWidget> EnhanceWidget = nullptr;
	TObjectPtr<UUserWidget> WinningWidget = nullptr;
	TObjectPtr<UUserWidget> CreditsWidget = nullptr;
	int PauseCount = 0;
	int UICount = 0;
	
	void IncUICount();
	void DecUICount();
	void PauseGameInDelay(float Delay);
	FTimerHandle DelayPause;
	void PauseGameImmediately();
	void UnPauseGameImmediately();
};
