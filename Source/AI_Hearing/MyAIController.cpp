// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "MyAICharacter.h"


AMyAIController::AMyAIController()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
}


void AMyAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	AMyAICharacter* Char = Cast<AMyAICharacter>(InPawn);
	if (Char && Char->BehaviorTree->BlackboardAsset)
	{
		BlackboardComp->InitializeBlackboard(*Char->BehaviorTree->BlackboardAsset);

		BehaviorTreeComp->StartTree(*Char->BehaviorTree);
	}
}

void AMyAIController::SetSensedTarget(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetKey, NewTarget);
	}
}