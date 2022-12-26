// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"
#include"Components/BoxComponent.h"
#include"PaperFlipbookComponent.h"
#include"Gameframework/CharacterMovementComponent.h"
ABaseCharacter::ABaseCharacter() {
	bUseControllerRotationPitch = bUseControllerRotationRoll = bUseControllerRotationYaw = false;
	HitBox = CreateDefaultSubobject<UBoxComponent>("HitBox");
	HitBox->SetupAttachment(GetRootComponent());
}
void ABaseCharacter::BeginPlay() {
	Super::BeginPlay();
	Health = DefaultHealth;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->ConstrainNormalToPlane(FVector(0, 1, 0));
}
void ABaseCharacter::Tick(float DeltaTime)
{
	if (GetSprite()->DoesSocketExist("Hit") && GetSprite()->GetSocketLocation("Hit") != GetSprite()->GetComponentLocation()){
		if (!HitOnceEnable||!HitOnce) {
			HitCheck();
		}
	}
	else{
		HitOnce = false;
	}
	Super::Tick(DeltaTime);
}
float ABaseCharacter::GetDefaultHealth() const
{
	return DefaultHealth;
}
float ABaseCharacter::GetHealth() const
{
	return Health;
}
void ABaseCharacter::UpdateActionRotation() {
	auto BaseController = GetController();
	check(BaseController);
	float Yaw = BaseController->GetControlRotation().Yaw;
	while (Yaw < -180 || Yaw>180) {
		if (Yaw > 180) Yaw -= 360;
		if (Yaw < -180) Yaw += 360;
	}
	if (FMath::Abs<float>(Yaw) <= 90) {
		SetActorRotation(FRotator(0, 0, 0));
	}
	else {
		SetActorRotation(FRotator(0, 180, 0));
	}
}