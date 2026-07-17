// Copyright by Hungne


#include "AIEnemyController.h"

#include "SpaceShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AAIEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

void AAIEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAIEnemyController::StartBehaviorTree(ASpaceShooterCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<ASpaceShooterCharacter>(GetPawn());
	
		if (Player)
		{
			PlayerCharacter = Player;
		}
	
		RunBehaviorTree(EnemyAIBehaviorTree);
		
		// UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		// if (MyBlackboard && PlayerCharacter && MyCharacter)
		// {
		// 	MyBlackboard->SetValueAsVector("StartLocation", MyCharacter->GetActorLocation());
		// }
	}
	
}


