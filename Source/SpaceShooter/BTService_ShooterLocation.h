// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_ShooterLocation.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UBTService_ShooterLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_ShooterLocation();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
