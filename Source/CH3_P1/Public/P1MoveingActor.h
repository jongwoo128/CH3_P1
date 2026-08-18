
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P1MoveingActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class CH3_P1_API AP1MoveingActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AP1MoveingActor();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MoveDirection = FVector(1.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 200.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange = 300.f;

private:
	FVector StartLocation;
	float CurrentDistance = 0.f;
	float MoveDirectionSign = 1.f;
};
