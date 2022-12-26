// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyLightAtkTask.h"
#include"Enemy/BaseEnemy.h"
#include"AIController.h"
UEnemyLightAtkTask::UEnemyLightAtkTask(){
	NodeName = "EnemyLightAtk";
}
EBTNodeResult::Type UEnemyLightAtkTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto EnemyController = OwnerComp.GetAIOwner();
	if (!EnemyController) return EBTNodeResult::Failed;
	auto Self = Cast<ABaseEnemy>(EnemyController->GetPawn());
	if (!Self) return EBTNodeResult::Failed;
	Self->EnemyLightAtk();
	return EBTNodeResult::Succeeded;
}
