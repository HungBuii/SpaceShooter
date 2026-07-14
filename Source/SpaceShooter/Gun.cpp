// Copyright by Hungne


#include "Gun.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	SetRootComponent(SceneRoot);
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(SceneRoot);
	
	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>("MuzzleFlash");
	MuzzleFlashParticleSystem->SetupAttachment(Mesh);
	
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
	MuzzleFlashParticleSystem->Deactivate();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	MuzzleFlashParticleSystem->Activate(true);
	
	if (OwnerController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;
		OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		FVector EndLocation = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		
		if (bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult, ViewPointLocation, EndLocation, ECC_GameTraceChannel2, Params))
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactParticleSystem, 
				HitResult.ImpactPoint, HitResult.ImpactPoint.Rotation());
		}

	}

}

