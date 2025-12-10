## 기초
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

## ver2
FlyCharacter.h
```
// FlyCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FlyCharacter.generated.h"

// 전방 선언 (컴파일 시간 단축)
class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class USpringArmComponent;
class UNiagaraComponent; // 스피드 라인용
class UNiagaraSystem;

UCLASS(config = Game)
class CITYSAMPLE_API AFlyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AFlyCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    /** 카메라 붐: 캐릭터 뒤에 카메라 위치 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* CameraBoom;

    /** 팔로우 카메라 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

    /** 스피드 라인 효과를 위한 나이아가라 컴포넌트 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = VFX)
    UNiagaraComponent* SpeedLinesComponent;

    /** 매핑 컨텍스트 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputMappingContext* DefaultMappingContext;

    /** 점프 입력 액션 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* JumpAction;

    /** 이동 입력 액션 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveAction;

    /** 시선 입력 액션 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* LookAction;

    /** 비행 토글 액션 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* FlyAction;

    /** 전력 질주/부스트 액션 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* SprintAction;

    /** 상승/하강 액션 */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* FlyUpAction;

public:
    // --- 비행 설정 변수 --- //

    /** 최대 비행 속도 (일반) */
    UPROPERTY(EditAnywhere, Category = "Flight Settings")
    float FlightSpeed = 4000.0f;

    /** 최대 비행 속도 (전력 질주 시) */
    UPROPERTY(EditAnywhere, Category = "Flight Settings")
    float SprintFlightSpeed = 15000.0f;

    /** 회전 시 롤링 속도 (뱅킹 감도) */
    UPROPERTY(EditAnywhere, Category = "Flight Settings")
    float RollInterpSpeed = 2.5f;

    /** 최대 롤 각도 (도 단위) */
    UPROPERTY(EditAnywhere, Category = "Flight Settings")
    float MaxRollAngle = 45.0f;

    /** FOV 설정 */
    UPROPERTY(EditAnywhere, Category = "Camera Settings")
    float BaseFOV = 90.0f;

    UPROPERTY(EditAnywhere, Category = "Camera Settings")
    float SprintFOV = 120.0f;

protected:
    /** 이동 로직 */
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void FlyUp(const FInputActionValue& Value);
    void ToggleFlight(const FInputActionValue& Value);
    void StartSprint(const FInputActionValue& Value);
    void StopSprint(const FInputActionValue& Value);

    /** 뱅킹 로직 */
    void UpdateFlightRotation(float DeltaTime);

    /** 카메라 로직 */
    void UpdateCameraFOV(float DeltaTime);

private:
    // 상태 플래그
    bool bIsFlying = false;
    bool bIsSprinting = false;

    // 뱅킹 계산용
    float CurrentRoll = 0.0f;
    FRotator LastControlRotation;
};
```

FlyCharacter.cpp
```
#include "FlyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h" // 벡터 수학에 필수

AFlyCharacter::AFlyCharacter()
{
    // 캡슐 크기 설정
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // 중요 수정: 캐릭터 메시의 컨트롤러 회전 사용 비활성화.
    // 메시가 카메라에 딱 붙는 게 아니라 부드럽게 회전하길 원합니다.
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // 캐릭터 무브먼트 설정
    GetCharacterMovement()->bOrientRotationToMovement = true; // 지상에서는 이동 방향으로 회전
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

    // 비행 설정
    GetCharacterMovement()->JumpZVelocity = 700.f;
    GetCharacterMovement()->AirControl = 0.35f;
    GetCharacterMovement()->MaxWalkSpeed = 500.f;
    GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
    GetCharacterMovement()->BrakingDecelerationFlying = 3000.0f; // 급정거를 위해 높은 감속력 설정

    // 카메라 붐 생성
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->bUsePawnControlRotation = true; // 붐은 컨트롤러를 따라감
    CameraBoom->bEnableCameraLag = true; // "무게감"을 위해 랙 추가
    CameraBoom->CameraLagSpeed = 10.0f;

    // 팔로우 카메라 생성
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    // 스피드 라인용 나이아가라 컴포넌트 생성 (초기엔 비활성화)
    SpeedLinesComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SpeedLines"));
    SpeedLinesComponent->SetupAttachment(RootComponent);
    SpeedLinesComponent->bAutoActivate = false;
}

void AFlyCharacter::BeginPlay()
{
    Super::BeginPlay();

    // 입력 매핑 컨텍스트 추가
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

void AFlyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsFlying)
    {
        UpdateFlightRotation(DeltaTime);
        UpdateCameraFOV(DeltaTime);
    }
}

//////////////////////////////////////////////////////////////////////////
// 입력

void AFlyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

        // 점프
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

        // 이동
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFlyCharacter::Move);

        // 시선
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFlyCharacter::Look);

        // 비행 관련
        EnhancedInputComponent->BindAction(FlyAction, ETriggerEvent::Started, this, &AFlyCharacter::ToggleFlight);
        EnhancedInputComponent->BindAction(FlyUpAction, ETriggerEvent::Triggered, this, &AFlyCharacter::FlyUp);

        // 전력 질주
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AFlyCharacter::StartSprint);
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AFlyCharacter::StopSprint);
    }
}

void AFlyCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();

        if (bIsFlying)
        {
            // 비행 중: 카메라가 보는 방향(Pitch 포함 3차원)으로 이동
            const FVector ForwardDirection = Rotation.Vector();
            const FVector RightDirection = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

            AddMovementInput(ForwardDirection, MovementVector.Y);
            AddMovementInput(RightDirection, MovementVector.X);
        }
        else
        {
            // 지상: 수평선(Yaw만 고려)으로 이동
            const FRotator YawRotation(0, Rotation.Yaw, 0);
            const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
            const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

            AddMovementInput(ForwardDirection, MovementVector.Y);
            AddMovementInput(RightDirection, MovementVector.X);
        }
    }
}

void AFlyCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookAxisVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        AddControllerYawInput(LookAxisVector.X);
        AddControllerPitchInput(LookAxisVector.Y);
    }
}

void AFlyCharacter::FlyUp(const FInputActionValue& Value)
{
    // 수직 상승/하강 (Space/Ctrl)
    float MovementValue = Value.Get<float>();
    if (bIsFlying)
    {
        AddMovementInput(FVector::UpVector, MovementValue);
    }
}

void AFlyCharacter::ToggleFlight(const FInputActionValue& Value)
{
    bIsFlying = !bIsFlying;

    if (bIsFlying)
    {
        GetCharacterMovement()->SetMovementMode(MOVE_Flying);
        GetCharacterMovement()->MaxFlySpeed = FlightSpeed;

        // [중요 수정] 비행 중에는 이동 방향으로 자동 회전하는 기능을 끕니다.
        // 우리가 만든 UpdateFlightRotation 함수가 회전을 전담하여 뱅킹(기울기)을 구현합니다.
        GetCharacterMovement()->bOrientRotationToMovement = false;
    }
    else
    {
        GetCharacterMovement()->SetMovementMode(MOVE_Walking);

        // [중요 수정] 착륙하면 다시 이동 방향으로 회전하게 켭니다.
        GetCharacterMovement()->bOrientRotationToMovement = true;

        // 착륙 시 기울어진 회전을 수평으로 초기화
        FRotator CurrentRot = GetActorRotation();
        SetActorRotation(FRotator(0.0f, CurrentRot.Yaw, 0.0f));
    }
}

void AFlyCharacter::StartSprint(const FInputActionValue& Value)
{
    bIsSprinting = true;
    if (bIsFlying)
    {
        GetCharacterMovement()->MaxFlySpeed = SprintFlightSpeed;

        // 스피드 라인 활성화
        if (SpeedLinesComponent) SpeedLinesComponent->Activate();
    }
}

void AFlyCharacter::StopSprint(const FInputActionValue& Value)
{
    bIsSprinting = false;
    if (bIsFlying)
    {
        GetCharacterMovement()->MaxFlySpeed = FlightSpeed;

        // 스피드 라인 비활성화
        if (SpeedLinesComponent) SpeedLinesComponent->Deactivate();
    }
}

/**
 * 핵심 뱅킹 메커니즘
 * 회전 속도(Yaw Delta)에 기반하여 롤(Roll)을 계산합니다.
 */
void AFlyCharacter::UpdateFlightRotation(float DeltaTime)
{
    if (!Controller) return;

    // 1. 목표 회전값 가져오기 (카메라가 보는 방향)
    FRotator ControlRot = Controller->GetControlRotation();

    // 2. 현재 방향과 목표 방향의 차이 계산
    FRotator ActorRot = GetActorRotation();
    FRotator DeltaRot = UKismetMathLibrary::NormalizedDeltaRotator(ControlRot, ActorRot);

    // 3. Yaw 차이에 기반한 목표 Roll 계산 (오른쪽 회전 = 양수 Yaw 차이 = 양수 Roll)
    // 범위를 정규화하고 곱하여 더 급격한 뱅크 각도를 얻음
    float TargetRoll = FMath::Clamp(DeltaRot.Yaw * 1.5f, -MaxRollAngle, MaxRollAngle);

    // 4. 부드러움을 위해 현재 Roll에서 목표 Roll로 보간
    CurrentRoll = FMath::FInterpTo(CurrentRoll, TargetRoll, DeltaTime, RollInterpSpeed);

    // 5. 새로운 회전 구성
    // 액터의 Pitch와 Yaw를 컨트롤러에 맞추되, Roll은 덮어씀.
    // 하지만 뱅킹 시각 효과가 자연스럽게 보이도록 Yaw가 컨트롤러보다 약간 뒤처지게 함.
    FRotator NewRot = FMath::RInterpTo(ActorRot, ControlRot, DeltaTime, 10.0f); // 부드러운 Yaw/Pitch 정렬
    NewRot.Roll = CurrentRoll; // 계산된 뱅크 각도 적용

    SetActorRotation(NewRot);
}

/**
 * 동적 카메라 메커니즘
 * 비행 상태에 따라 FOV를 보간합니다.
 */
void AFlyCharacter::UpdateCameraFOV(float DeltaTime)
{
    float TargetFOV = bIsSprinting ? SprintFOV : BaseFOV;
    float NewFOV = FMath::FInterpTo(FollowCamera->FieldOfView, TargetFOV, DeltaTime, 5.0f);
    FollowCamera->SetFieldOfView(NewFOV);
}
```

CitySample.Build.cs
```
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CitySample : ModuleRules
{
	public CitySample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.Add(ModuleDirectory);

		PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "HeadMountedDisplay",
            "Json",
            "PhysicsCore",
            "ChaosVehiclesCore",
            "StateTreeModule",
            "HoverDrone",
            "HairStrandsCore",
            "EnhancedInput",
            "GameplayTags",
            "MotionWarping",
            "ContextualAnimation",
			"Media",
			"MediaUtils",
			"MediaAssets",
			"AudioMixer",
			"GeometryCollectionEngine",
			"Gauntlet",
			"MassTraffic",
			"MassZoneGraphNavigation",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Niagara",
			"CinematicCamera",
			"Foliage",
			"Slate",
			"SlateCore",
			"NetCore",
			"AnimToTexture",
			"ModularGameplay",
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"NetworkPrediction",
			"ZoneGraph",
			"AnimGraphRuntime",
			"CitySampleMassCrowd",
			"DeveloperSettings",
			"RenderCore",
			"MoviePlayer",
			"StreamingPauseRendering",
			"LevelSequence",
	
			// AI/AISupport Plugin Modules
			"AISupportModule",

			// Mass core
			"MassEntity",

			// AI/MassAI Plugin Modules
			"MassAIBehavior",
			"MassAIDebug",
			
			// AI/MassCrowd Plugin Modules
			"MassCrowd",

			// Runtime/MassGameplay Plugin Modules
			"MassActors",
			"MassCommon",
			"MassGameplayDebug",
			"MassLOD",
			"MassMovement",
			"MassNavigation",
			"MassRepresentation",
			"MassReplication",
			"MassSpawner",
			"MassSimulation",
			"MassSignals",
		});

		if(Target.Platform != UnrealTargetPlatform.Linux)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"ElectraPlayerRuntime",
				"ElectraPlayerPlugin"
			});
		}

		if (Target.bBuildEditor == true)
		{
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"UnrealEd",
					"NiagaraEditor",
					"MeshUtilities",
					"Gauntlet"
				}
			);
		}
	}
}

```

## 블루프린트 
<img width="1919" height="1029" alt="image" src="https://github.com/user-attachments/assets/1561d22d-f6af-44de-9119-fe76d825ae1e" />

