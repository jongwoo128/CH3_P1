#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "P1PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;


UCLASS()
class CH3_P1_API AP1PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AP1PlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

protected:
	virtual void BeginPlay() override;
};
