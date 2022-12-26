// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "BaseArrow.generated.h"

/**
 * 
 */
UCLASS()
class REDHOODADVENTURE_API ABaseArrow : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ABaseArrow();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrow")
		float HitDamage = 0.0f;
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arrow")
		float Lifetime = 3.0f;
};
