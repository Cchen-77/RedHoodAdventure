// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BaseEnemyController.h"
#include"Enemy/EnemyPerceptionComponent.h"
#include"BrainComponent.h"
#include"Enemy/BaseEnemy.h"
ABaseEnemyController::ABaseEnemyController() {
	EnemyPerceptionComponent = CreateDefaultSubobject<UEnemyPerceptionComponent>("EnemyPerceptionComponent");
	SetPerceptionComponent(*EnemyPerceptionComponent);
}
void ABaseEnemyController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
TObjectPtr<ABaseCharacter> ABaseEnemyController::FindRedHood() {
	if (!EnemyPerceptionComponent) return nullptr;
	return EnemyPerceptionComponent->FindRedHood();
}
void ABaseEnemyController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
	auto InEnemy = Cast<ABaseEnemy>(InPawn);
	if (InEnemy) {
		RunBehaviorTree(InEnemy->GetBehaviorTreeAsset());
	}
}
void ABaseEnemyController::OnEnemyDead() {
	BrainComponent->Cleanup();
}
