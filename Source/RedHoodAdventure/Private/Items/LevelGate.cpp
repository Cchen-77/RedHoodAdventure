// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/LevelGate.h"
#include"Kismet/GameplayStatics.h"
#include"Player/BasePlayer.h"
#include "PaperFlipbookComponent.h"
void ALevelGate::BeginPlay() {
	Super::BeginPlay();
	auto RedHood  = Cast<ABasePlayer>(UGameplayStatics::GetActorOfClass(GetWorld(), ABasePlayer::StaticClass()));
	RedHood->PlayerWantsEntering.AddDynamic(this,&ALevelGate::OpenDoor);
}
ALevelGate::ALevelGate() {
	GuideSprite = CreateDefaultSubobject<UPaperFlipbookComponent>("GuideSprite");
	GuideSprite->SetupAttachment(GetRootComponent());
}
