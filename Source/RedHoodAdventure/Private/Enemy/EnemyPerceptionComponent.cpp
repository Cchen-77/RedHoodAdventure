// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyPerceptionComponent.h"
#include"Player/BasePlayer.h"
#include"Perception/AISense_Sight.h"
#include"Perception/AISense_Damage.h"
TObjectPtr<ABaseCharacter> UEnemyPerceptionComponent::FindRedHood() {
	TArray<AActor*> SightPerceivedActors;
	GetKnownPerceivedActors(UAISense_Sight::StaticClass(), SightPerceivedActors);
	for (auto PerceivedActor : SightPerceivedActors) {
		auto RedHood = Cast<ABasePlayer>(PerceivedActor);
		if (RedHood) {
			return RedHood;
		}
	}
	TArray<AActor*> DamagePerceivedActors;
	GetKnownPerceivedActors(UAISense_Damage::StaticClass(), DamagePerceivedActors);
	for (auto PerceivedActor : DamagePerceivedActors) {
		UE_LOG(LogTemp, Display, TEXT("SB"));
		auto RedHood = Cast<ABasePlayer>(PerceivedActor);
		if (RedHood)
			return RedHood;
	}
	return nullptr;
}
