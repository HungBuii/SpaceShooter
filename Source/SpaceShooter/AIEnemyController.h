// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIEnemyController.generated.h"

class ASpaceShooterCharacter;
/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AAIEnemyController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;
	
	TObjectPtr<ASpaceShooterCharacter> PlayerCharacter;
	TObjectPtr<ASpaceShooterCharacter> MyCharacter;

	void StartBehaviorTree(ASpaceShooterCharacter* Player);
	
};
