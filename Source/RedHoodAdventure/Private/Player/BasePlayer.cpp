// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BasePlayer.h"
#include"GameFramework/SpringArmComponent.h"
#include"Camera/CameraComponent.h"
ABasePlayer::ABasePlayer() {
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
}
void ABasePlayer::BeginPlay() {
	Super::BeginPlay();
	OnTakeAnyDamage.AddDynamic(this, &ABasePlayer::PlayerTakeDamage);
}
void ABasePlayer::PlayerTakeDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Damage <= 0) return;
	if (IsDead) return;
	Health -= Damage;
	if (Health <=0 ) {
		PlayerDead();
		OnPlayerDead.Broadcast();
	}
	else {
		PlayerHurt();
	}
}
void ABasePlayer::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this,&ABasePlayer::PlayerJump);
	PlayerInputComponent->BindAction("LightAtk", IE_Pressed, this, &ABasePlayer::PlayerLightAtk);
	PlayerInputComponent->BindAction("HeavyAtk", IE_Pressed, this, &ABasePlayer::PlayerHeavyAtk);
	PlayerInputComponent->BindAction("Bow", IE_Pressed, this, &ABasePlayer::PlayerBow);
	PlayerInputComponent->BindAction("Slide", IE_Pressed, this, &ABasePlayer::PlayerSlide);
	PlayerInputComponent->BindAction("Enter", IE_Pressed, this, &ABasePlayer::PlayerEnter);
	PlayerInputComponent->BindAxis("MoveLeft", this, &ABasePlayer::PlayerMoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayer::PlayerMoveRight);
}
bool ABasePlayer::IsMovementLock() const {
	return IsDead || IsHurting || IsLightAttacking || IsSliding || IsBowing || IsHeavyAttacking;
}
void ABasePlayer::PlayerWantsEnter() {
	PlayerWantsEntering.Broadcast();
}
