// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyMonitor.h"
#include"Enemy/BaseEnemy.h"
#include"Kismet/GameplayStatics.h"
AEnemyMonitor::AEnemyMonitor()
{
	PrimaryActorTick.bCanEverTick = false;
}
void AEnemyMonitor::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseEnemy::StaticClass(), OutActors);
	for (auto OutActor : OutActors) {
		auto Enemy = Cast<ABaseEnemy>(OutActor);
		if (Enemy) {
			EnemyNumber++;
			Enemy->OnEnemyNumUpd.AddDynamic(this, &AEnemyMonitor::OnEnemyUpd);
		}
	}
}
void AEnemyMonitor::OnEnemyUpd(int num, AActor* Enemy) {
	EnemyNumber += num;
	if (num > 0) {
		auto GameEnemy = Cast<ABaseEnemy>(Enemy);
		GameEnemy->OnEnemyNumUpd.AddDynamic(this, &AEnemyMonitor::OnEnemyUpd);
	}
	if (EnemyNumber <= 0) {
		OnAllEnemyDead();
		SetLifeSpan(1.0f);
	}
}

