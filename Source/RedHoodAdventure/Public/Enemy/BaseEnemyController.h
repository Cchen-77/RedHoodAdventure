// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseEnemyController.generated.h"

/**
 * 
 */
class ABaseCharacter;
class UEnemyPerceptionComponent;
UCLASS()
class REDHOODADVENTURE_API ABaseEnemyController : public AAIController
{
	GENERATED_BODY()
public:
	ABaseEnemyController();
	TObjectPtr<ABaseCharacter> FindRedHood();
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void OnEnemyDead();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		TObjectPtr<UEnemyPerceptionComponent> EnemyPerceptionComponent;
	virtual void OnPossess(APawn* InPawn) override;
};
