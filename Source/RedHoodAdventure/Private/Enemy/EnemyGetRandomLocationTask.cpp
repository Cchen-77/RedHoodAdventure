// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyGetRandomLocationTask.h"
#include"Enemy/BaseEnemy.h"
#include"BehaviorTree/BlackboardComponent.h"
#include"NavigationSystem.h"
#include"AIController.h"
UEnemyGetRandomLocationTask::UEnemyGetRandomLocationTask() {
	NodeName = "GetRandomLocation";
}
EBTNodeResult::Type UEnemyGetRandomLocationTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Blackboard) return EBTNodeResult::Failed;
	auto Center = Cast<AActor>(Blackboard->GetValueAsObject(CenterSelector.SelectedKeyName));
	if (!Center) return EBTNodeResult::Failed;
	auto NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	FNavLocation NavLocation;
	auto Finded = NavSys->GetRandomReachablePointInRadius(Center->GetActorLocation(), Radius, NavLocation);
	if (!Finded) return EBTNodeResult::Failed;
	//For2DMovement
	auto NextLocation = FVector(NavLocation.Location.X, Center->GetActorLocation().Y, Center->GetActorLocation().Z);
	Blackboard->SetValueAsVector("NextLocation", NextLocation);
	return EBTNodeResult::Succeeded;
}
