// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BasePlayerController.h"
ABasePlayerController::ABasePlayerController() {
	bAutoManageActiveCameraTarget = false;
}
void ABasePlayerController::BeginPlay() {
	SetViewTarget(GetPawn());
}
