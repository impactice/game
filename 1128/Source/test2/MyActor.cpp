#include "MyActor.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h" // 컨트롤러 찾기용

// 생성자
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

// [Page 53] BeginPlay: 게임 시작 시 초기화
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// [Page 47] 로그 출력
	LogMessage();

	// [보정] Actor는 기본적으로 입력을 받지 않으므로 컨트롤러를 찾아 입력을 활성화해야 함
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		// 입력 활성화
		EnableInput(PlayerController);

		// [Page 52] 매핑 컨텍스트 추가 함수 호출
		IMCMappingContext();

		// [Page 53] 입력 액션 바인딩 (Actor에서는 SetupPlayerInputComponent 대신 여기서 수행)
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			// MoveAction이 발동(Triggered)될 때 Move 함수 실행
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyActor::Move);
		}
	}
}

// Tick: 매 프레임 실행
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// [Page 52] Move: 실제 이동 로직 구현
void AMyActor::Move(const FInputActionValue& Value)
{
	// 입력값(X, Y) 가져오기
	const FVector2D MovementVector = Value.Get<FVector2D>();

	// X축 이동 (앞/뒤)
	if (MovementVector.X != 0.0f)
	{
		// 액터의 정면 방향으로 이동
		AddMovementInput(GetActorForwardVector(), MovementVector.X);
	}

	// Y축 이동 (좌/우)
	if (MovementVector.Y != 0.0f)
	{
		// 액터의 오른쪽 방향으로 이동
		AddMovementInput(GetActorRightVector(), MovementVector.Y);
	}
}

// [Page 52] IMCMappingContext: 키 매핑 컨텍스트 활성화
void AMyActor::IMCMappingContext()
{
	// 플레이어 컨트롤러 가져오기
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		// 향상된 입력 로컬 플레이어 서브시스템 가져오기
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			// 매핑 컨텍스트 추가 (우선순위 0)
			if (ThirdPersonContext)
			{
				Subsystem->AddMappingContext(ThirdPersonContext, 0);
			}
		}
	}
}

// [Page 47] LogMessage: 화면에 디버그 메시지 출력
void AMyActor::LogMessage()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hello, World!"));
	}
}