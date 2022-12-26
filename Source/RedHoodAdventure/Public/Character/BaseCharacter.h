// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "BaseCharacter.generated.h"
UENUM(BlueprintType)
enum class EFaction :uint8 {
	None,
	Friend,
	Enemy
};
class UBoxComponent;
UCLASS()
class REDHOODADVENTURE_API ABaseCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
public:
	ABaseCharacter();
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		float GetDefaultHealth() const;
	UFUNCTION(BlueprintCallable)
		float GetHealth() const;
protected:
	//AboutHit
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hit")
		bool HitOnceEnable = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hit")
		bool HitOnce;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Hit")
		TObjectPtr<UBoxComponent> HitBox;
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void HitCheck();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void HitStop();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void HitStopFinish();
	//AboutHealth
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
		float DefaultHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
		float Health = 0.0f;
	//Faction
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Faction")
		EFaction Faction = EFaction::None;
	//AboutActions
	UFUNCTION(BlueprintCallable)
		void UpdateActionRotation();
	virtual void BeginPlay() override;
};
