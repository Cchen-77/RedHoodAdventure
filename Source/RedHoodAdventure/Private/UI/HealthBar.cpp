// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HealthBar.h"
#include"Player/BasePlayer.h"
float UHealthBar::GetHealth() {
	auto RedHood = Cast<ABasePlayer>(GetOwningPlayerPawn());
	if (!RedHood) return 0;
	return RedHood->GetHealth();
}
float UHealthBar::GetDefalutHealth() {
	auto RedHood = Cast<ABasePlayer>(GetOwningPlayerPawn());
	if (!RedHood) return 1;
	return RedHood->GetDefaultHealth();
}

void UHealthBar::StartFBTimer()
{
	WidgetFlipbookTimer = 0;
	GetWorld()->GetTimerManager().SetTimer(FBTimerHandle, this, &UHealthBar::IncFBTimer, 0.1, true);
}
void UHealthBar::EndFBTimer() {
	GetWorld()->GetTimerManager().ClearTimer(FBTimerHandle);
}
void UHealthBar::IncFBTimer() {
	WidgetFlipbookTimer++;
}
