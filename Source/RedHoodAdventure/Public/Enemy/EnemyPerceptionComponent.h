// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "EnemyPerceptionComponent.generated.h"

/**
 * 
 */
class ABaseCharacter;
UCLASS()
class REDHOODADVENTURE_API UEnemyPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	 TObjectPtr<ABaseCharacter> FindRedHood();
};
