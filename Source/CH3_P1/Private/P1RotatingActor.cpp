
#include "P1RotatingActor.h"
#include "Components/StaticMeshComponent.h"

AP1RotatingActor::AP1RotatingActor()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

}

void AP1RotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AP1RotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationSpeed * DeltaTime);

}

