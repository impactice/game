.h 
```
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
// [중요] 이 generated.h 파일은 무조건 include 목록 중 맨 마지막에 있어야 합니다!
#include "FlyCharacter.generated.h"

UCLASS()
class CITYSAMPLE_API AFlyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFlyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- 비행 관련 함수 ---
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void MoveUp_World(float Value);
	void ToggleFlight();

protected:
	bool bIsFlying;
	
	UPROPERTY(EditAnywhere, Category = "Flight")
	float FlightSpeed;
};
```

.cpp 
```
#include "FlyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

// 생성자
AFlyCharacter::AFlyCharacter()
{
 	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	FlightSpeed = 4000.0f; // 비행 속도 (빠르게)
	bIsFlying = false;
}

// 게임 시작 시
void AFlyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// 매 프레임마다
void AFlyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 입력 설정
void AFlyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 축(Axis) 매핑 - 프로젝트 세팅의 이름과 같아야 함
	PlayerInputComponent->BindAxis("MoveForward", this, &AFlyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFlyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AFlyCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AFlyCharacter::LookUp);
	PlayerInputComponent->BindAxis("MoveUp", this, &AFlyCharacter::MoveUp_World);

	// 액션(Action) 매핑
	PlayerInputComponent->BindAction("ToggleFlight", IE_Pressed, this, &AFlyCharacter::ToggleFlight);
}

// --- 구현부 ---

void AFlyCharacter::ToggleFlight()
{
	bIsFlying = !bIsFlying;

	if (bIsFlying)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		GetCharacterMovement()->MaxFlySpeed = FlightSpeed;
	}
	else
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}

void AFlyCharacter::MoveForward(float Value)
{
	if (Value == 0.0f) return;

	if (bIsFlying)
	{
		// 비행 중: 카메라가 보는 방향으로 이동
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
	else
	{
		// 걷기 중: 평지 이동
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFlyCharacter::MoveRight(float Value)
{
	if (Value == 0.0f) return;

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFlyCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AFlyCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AFlyCharacter::MoveUp_World(float Value)
{
	if (bIsFlying && Value != 0.0f)
	{
		AddMovementInput(FVector::UpVector, Value);
	}
}
```
