
#include "P1Character.h"
#include "P1PlayerController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AP1Character::AP1Character()
{

	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	NormalSpeed = 600.0f;
	SprintSpeedMultiplier = 1.7f;
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;

	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

/*
void AP1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AP1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

void AP1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AP1PlayerController* PlayerController = Cast<AP1PlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AP1Character::Move
				);
			}

			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&AP1Character::StartJump
				);

				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&AP1Character::StopJump
				);
			}

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AP1Character::Look
				);
			}

			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&AP1Character::StartSprint
				);

				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&AP1Character::StopSprint
				);
			}
		}
	}
}

void AP1Character::Move(const FInputActionValue& value)
{
	if (!Controller) return; //Controller가 있는지 더블 체크 개념으로 확인 
							 //(GetActorForwardVector()나 GetActorRightVector()는 기본적으로 Controller가 있어야 하는 함수여서 특히나 더블 체크)

	const FVector2D MoveInput = value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X)) 
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void AP1Character::StartJump(const FInputActionValue& value)
{
	//Controller 더블 체크가 없는 이유는 Jump()나 StopJumpping()와 같은 경우 내부적으로 한번 체크하는 기능이 탑재되어 있어서 그럼.
	if (value.Get<bool>())
	{
		Jump(); //캐릭터의 점프를 구현해주는 함수
	}
}
void AP1Character::StopJump(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		StopJumping(); // 캐릭터의 점프를 멈추도록 만들어주는 함수
	}
}

void AP1Character::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	AddControllerYawInput(LookInput.X); //Character 클래스에서 이미 내부적으로 구현이 되어있는 함수이다. (점프 함수 처럼)
	AddControllerPitchInput(LookInput.Y);
}

void AP1Character::StartSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement()) 
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}

void AP1Character::StopSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	}
}