// Copyright by Hungne


#include "BTTaskNode_Shoot.h"

#include "AIEnemyController.h"
#include "SpaceShooterCharacter.h"

UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
	NodeName = TEXT("Shoot Shooter");
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	AAIEnemyController* OwnerController = Cast<AAIEnemyController>(OwnerComp.GetAIOwner());
	if (OwnerController)
	{
		ASpaceShooterCharacter* OwnerCharacter = OwnerController->MyCharacter;
		ASpaceShooterCharacter* PlayerCharacter = OwnerController->PlayerCharacter;

		if (OwnerCharacter && PlayerCharacter)
		{
			OwnerCharacter->Shoot();
			return EBTNodeResult::Succeeded;
		}
	}
	
	return EBTNodeResult::Failed;
}
