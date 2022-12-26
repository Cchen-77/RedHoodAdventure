// Copyright Epic Games, Inc. All Rights Reserved.


#include "RedHoodAdventureGameModeBase.h"
#include"Player/BasePlayer.h"
#include"Player/BasePlayerController.h"
ARedHoodAdventureGameModeBase::ARedHoodAdventureGameModeBase() {
	DefaultPawnClass = ABasePlayer::StaticClass();
	PlayerControllerClass = ABasePlayerController::StaticClass();
}
