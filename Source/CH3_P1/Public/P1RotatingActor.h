
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P1RotatingActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class CH3_P1_API AP1RotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AP1RotatingActor();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	FRotator RotationSpeed = FRotator(0.f, 90.f, 0.f);

};
