// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyMonitor.generated.h"

class ABaseEnemy;
UCLASS()
class REDHOODADVENTURE_API AEnemyMonitor : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemyMonitor();
protected:
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnEnemyUpd(int num, AActor* Enemy);
	UPROPERTY(VisibleAnywhere, Category = "EnemyInfos")
		int EnemyNumber = 0;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void OnAllEnemyDead();
};
