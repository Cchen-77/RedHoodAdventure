// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnemyLightAtkTask.generated.h"

/**
 * 
 */
UCLASS()
class REDHOODADVENTURE_API UEnemyLightAtkTask : public UBTTaskNode
{
	GENERATED_BODY()
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UEnemyLightAtkTask();

};
