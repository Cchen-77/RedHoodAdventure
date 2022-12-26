// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "EnemyFindRedHoodService.generated.h"

/**
 * 
 */
UCLASS()
class REDHOODADVENTURE_API UEnemyFindRedHoodService : public UBTService
{
	GENERATED_BODY()
public:
	UEnemyFindRedHoodService();
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
