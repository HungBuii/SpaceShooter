// Copyright by Hungne


#include "AIEnemyController.h"

#include "SpaceShooterCharacter.h"
#include "Kismet/GameplayStatics.h"

void AAIEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

void AAIEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ASpaceShooterCharacter* PlayerPawn = Cast<ASpaceShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (PlayerPawn)
	{
		// MoveToActor(PlayerPawn, 200.0f);
		SetFocus(PlayerPawn);
	}

}


