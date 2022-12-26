// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "ProbabilityDecorator.generated.h"

/**
 * 
 */
UCLASS()
class REDHOODADVENTURE_API UProbabilityDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
	UProbabilityDecorator();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Probability", meta = (ClampMax = "1.0", ClampMin = "0.0"))
		float Probability = 0.0f;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
	
};
