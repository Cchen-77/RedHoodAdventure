// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseHUD.h"
#include"UI/HealthBar.h"
#include"Player/BasePlayer.h"
#include"Kismet/GameplayStatics.h"
#include"GameFramework/PlayerController.h"
void ABaseHUD::BeginPlay() {
	Super::BeginPlay();
	auto RedHood = Cast<ABasePlayer>(GetOwningPawn());
	if (RedHood) {
		RedHood->OnPlayerDead.AddDynamic(this, &ABaseHUD::OnPlayerDead);
	}
}
void ABaseHUD::OpenEscMenu()
{
	if (!EscMenu) {
		EscMenu = CreateWidget<UUserWidget>(GetWorld(), EscMenuClass);
	}
	EscMenu->AddToViewport();
	IncUICount();
	PauseGameImmediately();
}
void ABaseHUD::CloseEscMenu() {
	if(EscMenu)
		EscMenu->RemoveFromParent();
	DecUICount();
	UnPauseGameImmediately();
}
void ABaseHUD::OpenHealthBar() {
	if(!HealthBar)
	HealthBar = CreateWidget<UUserWidget>(GetWorld(), HealthBarClass);
	HealthBar->AddToViewport();
	auto temp = Cast<UHealthBar>(HealthBar);
	if (temp) {
		temp->StartFBTimer();
	}
}
void ABaseHUD::CloseHealthBar() {
	if (HealthBar) {
		HealthBar->RemoveFromParent();
		auto temp = Cast<UHealthBar>(HealthBar);
		if (temp) {
			temp->EndFBTimer();
		}
	}
}
void ABaseHUD::OpenDeadScreen()
{
	if (!DeadScreen) 
		DeadScreen = CreateWidget<UUserWidget>(GetWorld(), DeadScreenClass);
	DeadScreen->AddToViewport();
	IncUICount();
}
void ABaseHUD::CloseDeadScreen()
{
	if (DeadScreen) 
		DeadScreen->RemoveFromParent();
	DecUICount();
	
}
void ABaseHUD::OpenEnhanceChoice() {
	delete EnhanceWidget;
	EnhanceWidget = CreateWidget<UUserWidget>(GetWorld(),EnhanceWidgetClass);
	EnhanceWidget->AddToViewport();
	IncUICount();
	PauseGameInDelay(0.1);
}
void ABaseHUD::CloseEnhanceChoice()
{
	if (EnhanceWidget)
		EnhanceWidget->RemoveFromParent();
	DecUICount();
	UnPauseGameImmediately();
}
void ABaseHUD::OpenWinningWidget()
{
	if(!WinningWidget) 
		WinningWidget  = CreateWidget<UUserWidget>(GetWorld(), WinningWidgetClass);
	WinningWidget->AddToViewport();
	IncUICount();
	PauseGameImmediately();
}
void ABaseHUD::CloseWinningWidget()
{
	if (WinningWidget)
		WinningWidget->RemoveFromParent();
	DecUICount();
	UnPauseGameImmediately();
}
void ABaseHUD::OpenCreditsWidget()
{
	if(!CreditsWidget)
		CreditsWidget = CreateWidget<UUserWidget>(GetWorld(),CreditsWidgetClass);
	CreditsWidget->AddToViewport();
	IncUICount();
	PauseGameImmediately();
}
void ABaseHUD::CloseCreditsWidget()
{
	if (CreditsWidget)
		CreditsWidget->RemoveFromParent();
	DecUICount();
	UnPauseGameImmediately();
}
void ABaseHUD::IncUICount()
{
	UICount++;
	if (UICount == 1) {
		auto NowPlayerController = GetOwningPlayerController();
		if (NowPlayerController) {
			NowPlayerController->bShowMouseCursor = true;
			NowPlayerController->SetInputMode(FInputModeGameAndUI());
		}
	}
}
void ABaseHUD::DecUICount()
{
	UICount--;
	if (!UICount) {
		auto NowPlayerController = GetOwningPlayerController();
		if (NowPlayerController) {
			NowPlayerController->bShowMouseCursor = false;
			NowPlayerController->SetInputMode(FInputModeGameOnly());
		}
	}
}
void ABaseHUD::PauseGameInDelay(float Delay)
{
	GetWorld()->GetTimerManager().ClearTimer(DelayPause);
	GetWorld()->GetTimerManager().SetTimer(DelayPause, this, &ABaseHUD::PauseGameImmediately, Delay, false);
}
void ABaseHUD::PauseGameImmediately()
{
	++PauseCount;
	if (PauseCount == 1) {
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}
void ABaseHUD::UnPauseGameImmediately()
{
	--PauseCount;
	if(!PauseCount)
		UGameplayStatics::SetGamePaused(GetWorld(), false);
}
UUserWidget * ABaseHUD::GetHealthBar()
{
	return HealthBar;
}
UUserWidget * ABaseHUD::GetEscMenu()
{
	return EscMenu;
}
UUserWidget * ABaseHUD::GetDeadScreen()
{
	return DeadScreen;
}
UUserWidget * ABaseHUD::GetEnhanceWidget()
{
	return EnhanceWidget;
}
UUserWidget * ABaseHUD::GetWinningWidget()
{
	return WinningWidget;
}
UUserWidget * ABaseHUD::GetCreditsWidget()
{
	return CreditsWidget;
}
void ABaseHUD::OnPlayerDead() {
	CloseHealthBar();
	OpenDeadScreen();
}
