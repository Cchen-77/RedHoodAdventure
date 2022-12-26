// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyFindRedHoodService.h"
#include"Enemy/BaseEnemyController.h"
#include"BehaviorTree/BlackboardComponent.h"
#include"Character/BaseCharacter.h"
UEnemyFindRedHoodService::UEnemyFindRedHoodService() {
	NodeName = "FindRedHood";
}
void UEnemyFindRedHoodService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	auto Blackboard = OwnerComp.GetBlackboardComponent();
	auto EnemyController = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner());
	if (!Blackboard || !EnemyController) return;
	auto RedHood = Cast<AActor>(EnemyController->FindRedHood());
	Blackboard->SetValueAsObject("RedHood", RedHood);
}
