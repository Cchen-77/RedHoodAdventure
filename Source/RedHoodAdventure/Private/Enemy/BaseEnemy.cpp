// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BaseEnemy.h"
#include"Enemy/BaseEnemyController.h"
#include"Perception/AISense_Damage.h"
#include "Enemy/EnemyMonitor.h"
#include"Enemy/BaseEnemyController.h"
ABaseEnemy::ABaseEnemy() {
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ABaseEnemyController::StaticClass();
}
TObjectPtr<UBehaviorTree> ABaseEnemy::GetBehaviorTreeAsset() const {
	return BehaviorTreeAsset;
}
void ABaseEnemy::BeginPlay() {
	Super::BeginPlay();
	OnTakeAnyDamage.AddDynamic(this, &ABaseEnemy::EnemyTakeDamage);
}
bool ABaseEnemy::IsMovementLock() const{
	return IsDead || IsLightAttacking || IsHeavyAttacking || IsHurting;
}
void ABaseEnemy::EnemyTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser){
	if (Damage <= 0) return;
	if (IsDead) return;
	Health -= Damage;
	if (Health <= 0) {
		EnemyDead();
		auto EnemyController = Cast<ABaseEnemyController>(GetController());
		EnemyController->OnEnemyDead();
		OnEnemyNumUpd.Broadcast(-1,this);
	}
	else {
		EnemyHurt();
		UAISense_Damage::ReportDamageEvent(GetWorld(), DamagedActor, DamageCauser, Damage,FVector(),FVector());
	}
}