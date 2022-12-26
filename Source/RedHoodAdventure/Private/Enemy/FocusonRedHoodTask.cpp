// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/FocusonRedHoodTask.h"
#include"Enemy/BaseEnemyController.h"
#include"Character/BaseCharacter.h"
UFocusonRedHoodTask::UFocusonRedHoodTask() {
	NodeName = "FocusonRedHood";
}
EBTNodeResult::Type UFocusonRedHoodTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto EnemyController = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner());
	if (!EnemyController) return EBTNodeResult::Failed;
	EnemyController->SetFocus(EnemyController->FindRedHood());
	return EBTNodeResult::Succeeded;
}
