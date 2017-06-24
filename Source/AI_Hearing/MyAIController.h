// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class AI_HEARING_API AMyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UBehaviorTreeComponent* BehaviorTreeComp;

	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly)
	FName TargetKey = "SensedPawn";

public:
	AMyAIController();

	virtual void Possess(APawn* InPawn) override;
	
	void SetSensedTarget(APawn* NewTarget);
};
