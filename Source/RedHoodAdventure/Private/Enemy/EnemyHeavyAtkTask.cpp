

#include "Enemy/EnemyHeavyAtkTask.h"
#include"Enemy/BaseEnemy.h"
#include"AIController.h"
UEnemyHeavyAtkTask::UEnemyHeavyAtkTask() {
	NodeName = "EnemyBossHeavyAtk";
}
EBTNodeResult::Type UEnemyHeavyAtkTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto EnemyController = OwnerComp.GetAIOwner();
	if (!EnemyController) return EBTNodeResult::Failed;
	auto Self = Cast<ABaseEnemy>(EnemyController->GetPawn());
	if (!Self) return EBTNodeResult::Failed;
	Self->EnemyHeavyAtk();
	return EBTNodeResult::Succeeded;
}
