// Copyright by Hungne


#include "BTService_ShooterLocationIfSeen.h"

#include "AIEnemyController.h"
#include "SpaceShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_ShooterLocationIfSeen::UBTService_ShooterLocationIfSeen()
{
}

void UBTService_ShooterLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	AAIEnemyController* OwnerController = Cast<AAIEnemyController>(OwnerComp.GetAIOwner());
	ASpaceShooterCharacter* Player = OwnerController->PlayerCharacter;
	UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();
	
	if (OwnerController && Player && Blackboard)
	{
		if (OwnerController->LineOfSightTo(Player))
		{
			Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
			OwnerController->SetFocus(Player);
		}
		else
		{
			Blackboard->ClearValue(GetSelectedBlackboardKey());
			OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
		}
	}
}
