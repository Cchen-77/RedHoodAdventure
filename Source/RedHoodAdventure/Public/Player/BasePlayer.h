// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerWantsEntering);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerDead);
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class REDHOODADVENTURE_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ABasePlayer();

	//About Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		TObjectPtr<UCameraComponent> Camera;
	//About Player Action
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerLightAtk();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerLightAtkFinish();
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void ResetLightAttackCombo();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsLightAttacking = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Action")
		int MAXLightAttackCombo = 3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		int LightAttackCombo = 0;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerHeavyAtk();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerHeavyAtkFinish();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void ResetHeavyAttackCombo();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsHeavyAttacking = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Action")
		int MAXHeavyAttackCombo = 3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		int HeavyAttackCombo = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage")
		float HitDamage = 0.0f;

	UPROPERTY(BlueprintAssignable)
		FPlayerWantsEntering PlayerWantsEntering;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerEnter();
	UFUNCTION(BlueprintCallable)
		void PlayerWantsEnter();//broadcast to delegate

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void PlayerJump();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerBow();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerBowArrowout();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerBowFinish();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsBowing = false;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerSlide();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerSlideFinish();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsSliding = false;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerMoveLeft(float Amount);
	UFUNCTION(BlueprintImplementableEvent) 
		void PlayerMoveRight(float Amount);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerHurt();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerHurtFinish();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsHurting = false;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerDead();
	UPROPERTY(BlueprintAssignable)
		FPlayerDead OnPlayerDead;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsDead = false;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void PlayerHeal(float HealAmount);
		
protected:
	UFUNCTION(BlueprintCallable)
		bool IsMovementLock() const;
	UFUNCTION()
		void PlayerTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
