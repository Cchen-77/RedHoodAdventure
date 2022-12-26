// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/ProbabilityDecorator.h"
UProbabilityDecorator::UProbabilityDecorator() {
	NodeName = "ProbabilityDecorator";
}
bool UProbabilityDecorator::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{

	return FMath::RandRange(0.0, 1.0) <= Probability;
}
