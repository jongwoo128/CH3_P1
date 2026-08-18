
#include "P1MoveingActor.h"
#include "Components/StaticMeshComponent.h"


AP1MoveingActor::AP1MoveingActor()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

}


void AP1MoveingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}


void AP1MoveingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	CurrentDistance += MoveSpeed * DeltaTime * MoveDirectionSign;


	if (CurrentDistance >= MaxRange)
	{
		CurrentDistance = MaxRange;
		MoveDirectionSign = -1.f;
	}
	else if (CurrentDistance <= 0.f)
	{
		CurrentDistance = 0.f;
		MoveDirectionSign = 1.f;
	}

	
	const FVector NewLocation = StartLocation + MoveDirection.GetSafeNormal() * CurrentDistance;
	SetActorLocation(NewLocation);

}

