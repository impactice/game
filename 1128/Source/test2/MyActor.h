#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
// [Page 51] Enhanced Input 관련 헤더 추가
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MyActor.generated.h" // 반드시 가장 마지막에 위치

UCLASS()
class TEST2_API AMyActor : public APawn
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	virtual void BeginPlay() override;

	// [Page 51] 컴포넌트 슬롯 생성 (입력 매핑 컨텍스트)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<class UInputMappingContext> ThirdPersonContext;

	// [Page 51] 컴포넌트 슬롯 생성 (이동 액션)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<class UInputAction> MoveAction;

public:	
	virtual void Tick(float DeltaTime) override;

	// [Page 51] Input Action과 연결될 이동 함수
	UFUNCTION()
	void Move(const FInputActionValue& Value);

	// [Page 47] 로그 출력 함수
	void LogMessage();

private:
	// [Page 51] 매핑 컨텍스트 설정 함수
	void IMCMappingContext();
};