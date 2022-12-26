// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnemyGetRandomLocationTask.generated.h"

/**
 * 
 */
UCLASS()
class REDHOODADVENTURE_API UEnemyGetRandomLocationTask : public UBTTaskNode
{
	GENERATED_BODY()
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UEnemyGetRandomLocationTask();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		float Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FBlackboardKeySelector CenterSelector;
};
