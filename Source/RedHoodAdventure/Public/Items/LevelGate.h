// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "LevelGate.generated.h"

/**
 * 
 */
class UPaperFlipbookComponent;
UCLASS()
class REDHOODADVENTURE_API ALevelGate : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ALevelGate();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
		FName NextLevelName;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void OpenDoor();
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Components")
	TObjectPtr<UPaperFlipbookComponent> GuideSprite;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DoorInfo")
		bool IsOpen;
	virtual void BeginPlay() override;
};
