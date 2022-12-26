// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "BaseEnemy.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyNumUpdSignature, int, Number, AActor*, Enemy);
class UBehaviorTree;
UCLASS()
class REDHOODADVENTURE_API ABaseEnemy : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ABaseEnemy();
	TObjectPtr<UBehaviorTree> GetBehaviorTreeAsset() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyLightAtk();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyLightAtkFinish();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void ResetLightAttackCombo();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsLightAttacking = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Action")
		int MAXLightAttackCombo = 3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		int LightAttackCombo = 0;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyHeavyAtk();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyHeavyAtkFinish();
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

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyHurt();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyHurtFinish();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsHurting = false;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void EnemyDead();
	UPROPERTY(BlueprintAssignable)
		FEnemyNumUpdSignature OnEnemyNumUpd;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action")
		bool IsDead = false;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		TObjectPtr<UBehaviorTree> BehaviorTreeAsset;
	UFUNCTION(BlueprintCallable)
		bool IsMovementLock() const;
	UFUNCTION()
		void EnemyTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	virtual void BeginPlay() override;
};
