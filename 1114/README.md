
# Unity 게임 프로그래밍 가이드

> Kyungsung University Game Programming Course

## 목차
- [Unity 설치](#unity-설치)
- [간단한 예제: RollingBall](#간단한-예제-rollingball)
- [캐릭터 이동 구현](#캐릭터-이동-구현)

---

## Unity 설치

### 1. Unity 다운로드 및 설치

#### Unity Hub 다운로드
1. [Unity 공식 웹사이트](https://unity.com/) 접속
2. "Get started" 클릭
3. "Student and hobbyist" 탭 선택
   - Student 플랜: "Sign up" 클릭
   - Personal 플랜: "Get started" 클릭

#### Unity ID 생성
- 새 계정 생성 또는 기존 계정으로 로그인
- Unity Student plan 신청 가능

#### Unity Hub 설치
1. "Download for Windows" 클릭
2. `UnityHubSetup.exe` 다운로드 및 실행
3. 설치 마법사 진행

### 2. Unity 에디터 설정

#### Unity Hub 로그인
1. Unity Hub 실행
2. Unity ID로 로그인

#### Unity 에디터 설치
1. Unity Hub에서 "Install Unity Editor" 선택
2. 원하는 버전 선택 및 설치

#### 라이선스 활성화
1. "Get Personal Edition License" 선택
2. 이용 약관 동의 후 Personal Edition License 획득

### 3. 프로젝트 생성

#### 새 프로젝트 만들기
1. Unity Hub에서 "New Project" 클릭
2. 프로젝트 템플릿 선택 (3D 권장)
3. 프로젝트 이름 및 저장 위치 설정
4. "Create Project" 클릭

#### Unity 에디터 인터페이스
- **Hierarchy**: 씬 내 오브젝트 목록
- **Scene**: 3D 작업 공간
- **Game**: 게임 실행 화면
- **Inspector**: 선택한 오브젝트의 속성
- **Project**: 프로젝트 파일 및 에셋
- **Console**: 로그 및 오류 메시지

---

## 간단한 예제: RollingBall

### 프로젝트 개요
공이 경사면을 굴러내려가는 간단한 물리 시뮬레이션 게임

### 1. 카메라 설정

#### Main Camera 위치 초기화
1. **Hierarchy** → Main Camera 선택
2. **Inspector** → Transform → Position
   - X: 0, Y: 0, Z: 0

#### 씬 뷰 조작법
- **시점 선회**: Alt + 마우스 드래그
- **시점 평행 이동**: Ctrl + Alt + 마우스 드래그
- **줌 인/아웃**: 마우스 휠
- **오브젝트에 시점 맞추기**: F 키
- **씬 기즈모**: X축이 오른쪽, Y축이 위쪽이 되도록 조정

### 2. 바닥 만들기

1. **Hierarchy** → Create → 3D Object → Cube
2. **Inspector** → Transform 설정
   - Position: (0, 0, 0)
   - Scale: (10, 0.5, 5)
3. Cube 이름을 "Floor"로 변경

### 3. 벽 만들기

#### 왼쪽 벽 (Wall01)
1. **Hierarchy** → Create → 3D Object → Cube
2. 이름을 "Wall01"로 변경
3. **Inspector** → Transform 설정
   - Position: (-5.3, 4.6, 0)
   - Scale: (1, 10, 5)

#### 오른쪽 벽 (Wall02)
1. **Hierarchy** → Wall01 → Duplicate
2. 이름을 "Wall02"로 변경
3. **Inspector** → Transform → Position: (5.3, 4.6, 0)

#### 안쪽 벽 (Wall03)
1. **Hierarchy** → Create → 3D Object → Cube
2. 이름을 "Wall03"로 변경
3. **Inspector** → Transform 설정
   - Position: (0, 4.6, 2)
   - Scale: (10, 10, 1)
4. 씬 기즈모에서 퍼스펙티브 모드로 변경

### 4. 조명 및 카메라 조정

#### Main Camera 설정
1. **Hierarchy** → Main Camera
2. **Inspector** → Transform
   - Position: (0, 8, -11.9)
   - Rotation: (18, 0, 0)

#### Directional Light 설정
1. **Hierarchy** → Directional Light
2. **Inspector** → Transform
   - Position: (0, 0, -11.9)
   - Rotation: (10, 0, 0)

### 5. 경사면 만들기

#### Slope01
1. **Hierarchy** → Create → 3D Object → Cube
2. 이름을 "Slope01"로 변경
3. **Inspector** → Transform
   - Position: (-1, 8.57, 1)
   - Rotation: (0, 0, -10)
   - Scale: (8, 0.3, 2)

#### Slope02
1. Slope01 복제 (Duplicate)
2. 이름을 "Slope02"로 변경
3. **Inspector** → Transform → Position: (-1.5, 3.9, 1)

#### Slope03
1. Slope02 복제
2. 이름을 "Slope03"로 변경
3. **Inspector** → Transform
   - Position: (-3, 0.35, 1)
   - Scale: (5, 0.3, 2)

#### Slope04
1. Slope03 복제
2. 이름을 "Slope04"로 변경
3. **Inspector** → Transform
   - Position: (0.9, 6.2, 1)
   - Rotation: (0, 0, 8)
   - Scale: (8, 0.3, 2.2)

#### Slope05
1. Slope04 복제
2. 이름을 "Slope05"로 변경
3. **Inspector** → Transform → Position: (0.9, 2.2, 1)

### 6. 공 만들기

#### Sphere 생성
1. **Hierarchy** → Create → 3D Object → Sphere
2. 이름을 "Ball"로 변경
3. **Inspector** → Transform
   - Position: (-4.4, 9.58, 0.7)
   - Scale: (0.4, 0.4, 0.4)

### 7. 물리 동작 설정

#### Rigidbody 추가
1. **Hierarchy** → Ball 선택
2. **Component** → Physics → Rigidbody
3. **Use Gravity** 체크 확인

#### 물리 재질 생성 (Bounce)
1. **Project** → Create → Physic Material
2. 이름을 "Bounce"로 변경
3. **Inspector** → Bounciness: 0.6

#### Ball에 물리 재질 적용
1. **Hierarchy** → Ball 선택
2. **Inspector** → Sphere Collider → Material에 "Bounce" 드래그

### 8. 색상 적용

#### Material 생성
1. **Project** → Create → Material
2. 이름을 "Ball"로 변경
3. **Inspector** → Main Maps → Albedo → 원하는 색상 선택
4. Material을 Ball 오브젝트에 드래그

### 9. 실행
- **Play 버튼** 클릭하여 게임 실행
- 공이 경사면을 따라 굴러내려가는 것 확인

---

## 캐릭터 이동 구현

### 프로젝트 개요
3D 지형 위에서 캐릭터를 방향키로 이동시키고 점프시키는 기능 구현

### 1. 프로젝트 설정

#### 새 프로젝트 생성
1. Unity Hub에서 새 3D 프로젝트 생성
2. 프로젝트 이름 설정

#### 리소스 가져오기
1. **Menu** → Assets → Import Package → Custom Package
2. `Chapter4 Terrain.unitypackage` 선택
3. Import Unity Package 창에서 "All" → "Import"

### 2. 캐릭터 컨트롤러 스크립트 작성

#### 스크립트 생성
1. **Project** → Assets → Script (폴더 생성)
2. 마우스 우클릭 → Create → C# Script
3. 이름을 "QueryChanController"로 변경
4. 더블클릭하여 스크립트 열기

#### 코드 작성

```csharp
using UnityEngine;

public class QueryChanController : MonoBehaviour
{
    public float speed = 3.0f;
    public float jumpPower = 6.0f;
    private Vector3 direction;
    private CharacterController controller;
    private Animator anim;

    void Start()
    {
        controller = GetComponent<CharacterController>();
        anim = GetComponent<Animator>();
    }

    void Update()
    {
        float inputX = Input.GetAxis("Horizontal");
        float inputY = Input.GetAxis("Vertical");
        Vector3 inputDirection = new Vector3(inputX, 0, inputY);
        
        direction = Vector3.zero;
        
        if (inputDirection.magnitude > 0.1f)
        {
            transform.LookAt(transform.position + inputDirection);
            direction += transform.forward * speed;
            anim.SetFloat("Speed", direction.magnitude);
        }
        else
        {
            anim.SetFloat("Speed", 0);
        }
        
        if (Input.GetButton("Jump"))
        {
            anim.SetTrigger("Jump");
            direction.y += jumpPower;
        }
        
        controller.Move(direction * Time.deltaTime);
        direction.y += Physics.gravity.y * Time.deltaTime;
    }
}
```

#### 스크립트 적용
1. **Project** → Assets → PQchan (prefab) 선택
2. **Inspector** → Open → Script 슬롯에 "QueryChanController" 드래그

### 3. 지형(Terrain) 만들기

#### Terrain 추가
1. **Hierarchy** → Create → 3D Object → Terrain

#### Terrain 크기 설정
1. **Hierarchy** → Terrain 선택
2. **Inspector** → Terrain → Terrain Settings
3. Mesh Resolution 설정
   - Terrain Width: 100
   - Terrain Length: 100

#### 카메라 위치 조정
1. **Hierarchy** → Main Camera 선택
2. **Inspector** → Transform
   - Position: (53, 26.5, -4)
   - Rotation: (41.7, 0, 0)

### 4. 지형 텍스처링

#### 잔디 텍스처 추가
1. **Hierarchy** → Terrain 선택
2. **Inspector** → Terrain → Paint Terrain → Paint Texture
3. Terrain Layers → Edit Terrain Layers → Create Layer → Grass 선택

#### 흙 텍스처 추가
1. **Inspector** → Terrain Layers → Edit Terrain Layers → Create Layer → Sand
2. Sand Layer 선택
3. Brush Size: 20, Opacity: 20
4. 브러시 크기 조절: `[` 와 `]` 키 사용
5. Scene 뷰에서 원하는 부분 클릭하여 텍스처 페인팅

### 5. 산 만들기

1. **Hierarchy** → Terrain 선택
2. **Inspector** → Terrain → Paint Terrain → Raise or Lower Terrain
3. Brush Size와 Opacity 선택
4. Scene 뷰에서 클릭하여 지형 높이 조절

### 6. 캐릭터 배치 및 테스트

#### 캐릭터 배치
1. **Project** → Assets → PQchan을 **Hierarchy**로 드래그
2. **Hierarchy** → PQchan 선택
3. **Inspector** → Transform → Position: (50, 0.2, 50)

#### 카메라 재조정
1. **Hierarchy** → Main Camera 선택
2. **Inspector** → Transform → Position: (50, 2.5, 46)

#### 게임 실행
1. **Play 버튼** 클릭
2. **방향키**로 캐릭터 이동
3. **Space bar**로 점프

### 💾 저장하기
작업 후 **Ctrl + S** 또는 **File** → **Save**로 씬 저장을 잊지 마세요!

---


## 팁 & 단축키

### Scene 뷰 조작
| 기능 | 단축키 |
|------|--------|
| 시점 선회 | Alt + 드래그 |
| 시점 평행 이동 | Ctrl + Alt + 드래그 |
| 줌 인/아웃 | 마우스 휠 |
| 오브젝트에 포커스 | F 키 |
| 툴바 활용 | Q W E R T Y |

### 주요 용어
- **Directional Light**: 거리나 위치에 관계없이 한 방향으로 비추는 광원
- **Rigidbody**: 오브젝트에 물리 엔진을 적용하는 컴포넌트
- **CharacterController**: 캐릭터 이동을 제어하는 컴포넌트
- **Animator**: 애니메이션을 제어하는 컴포넌트

---
