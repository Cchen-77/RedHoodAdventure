// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/BaseArrow.h"
ABaseArrow::ABaseArrow() {

}
void ABaseArrow::BeginPlay() {
	Super::BeginPlay();
	SetLifeSpan(Lifetime);
}
