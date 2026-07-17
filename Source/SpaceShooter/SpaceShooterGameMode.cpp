// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceShooterGameMode.h"

#include "AIEnemyController.h"
#include "SpaceShooterCharacter.h"
#include "Kismet/GameplayStatics.h"

ASpaceShooterGameMode::ASpaceShooterGameMode()
{
	// stub
}

void ASpaceShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	ASpaceShooterCharacter* Player = Cast<ASpaceShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	TArray<AActor*> EnemyAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIEnemyController::StaticClass(), EnemyAIActors);
	
	for (AActor* EnemyAIActor : EnemyAIActors)
	{
		AAIEnemyController* EnemyAI = Cast<AAIEnemyController>(EnemyAIActor);

		if (EnemyAI)
		{
			EnemyAI->StartBehaviorTree(Player);
			UE_LOG(LogTemp, Display, TEXT("%s starting behavior tree"), *EnemyAI->GetActorNameOrLabel());
		}
	}
}
