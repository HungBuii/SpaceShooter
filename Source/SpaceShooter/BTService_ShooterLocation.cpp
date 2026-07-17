// Copyright by Hungne


#include "BTService_ShooterLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_ShooterLocation::UBTService_ShooterLocation()
{
	NodeName = TEXT("Get Shooter Location");
}

void UBTService_ShooterLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	
	if (PlayerPawn && Blackboard)
	{
		Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
}
