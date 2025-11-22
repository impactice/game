# 장애물 런 게임 제작 가이드

> Unity 2019.2.5f1 버전에서 테스트 완료

---

## 1. 프로젝트 만들기 (RUN)

### 1.1 새 프로젝트 생성
1. 유니티 허브 실행
2. **새로 생성** 클릭
3. 프로젝트 이름 입력: `RUN`
   - ⚠️ 프로젝트 이름은 영문자로 설정하는 것을 추천합니다
4. 저장 경로 지정 (임의의 폴더)
5. **생성** 클릭

### 1.2 씬 설정 (Main)
1. `Assets > Scenes`에 있는 `SampleScene`의 이름을 `Main`으로 변경

---

## 2. 에셋 임포트하기

### 2.1 Standard Assets 다운로드
1. **Window** → **Asset Store** 선택
2. Asset Store 탭에서 `standard assets` 검색
3. `Standard Assets (for Unity…` 클릭
4. **Download** 클릭 후 **Import** 클릭

### 2.2 필요한 에셋만 선택하여 임포트
1. 왼쪽 아래의 **None**을 클릭하여 모든 체크 해제
2. 다음 항목만 선택:
   - `Cameras`
   - `Characters`
   - `CrossPlatformInput`
   - `Prototyping`
   - `Utility`
3. **Import** 클릭

### 2.3 씬 방향 설정
- 원뿔 부분을 클릭하여 씬의 방향을 회전
- X가 오른쪽, Y가 위쪽에 오도록 변경

---

## 3. 스테이지 바닥 만들기

### 3.1 바닥 생성
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `FloorPrototype08x01x08`
2. Hierarchy로 드래그 앤 드롭
3. 이름 변경: `Floor1`

### 3.2 바닥 위치와 크기 설정
- **Transform** 값 설정:
  - Position: `0, 0, 0`
  - Rotation: `0, 0, 0`
  - Scale: `1, 1, 1`

---

## 4. 캐릭터 준비

### 4.1 캐릭터 배치
1. **Project** → **Assets** → **Standard Assets** → **Characters** → **ThirdPersonCharacters** → **Prefabs** → `ThirdPersonController`
2. Hierarchy로 드래그 앤 드롭
3. 이름 변경: `Player`

### 4.2 캐릭터 위치와 크기 설정
- **Transform** 값 설정:
  - Position: `0, 0, 0`
  - Rotation: `0, 0, 0`
  - Scale: `1, 1, 1`

### 4.3 태그 설정
1. **Inspector** → **Tag** → **Player** 선택

### 4.4 테스트
1. **Play** 버튼 클릭
2. `a, s, d, f` 키와 상하좌우 방향키로 이동 테스트

---

## 5. 게임 화면 스크롤 (카메라 설정)

### 5.1 카메라 배치
1. **Project** → **Assets** → **Standard Assets** → **Cameras** → **Prefabs** → `MultipurposeCameraRig`
2. Hierarchy로 드래그 앤 드롭
3. 기존 **Main Camera** 삭제 (Delete)

### 5.2 캐릭터 시작 위치 설정
1. **Hierarchy** → **Player** 선택
2. **Inspector** → **Transform** → Position:
   - X: `0`
   - Y: `0`
   - Z: `-1` (처음 위치보다 조금 뒤로 배치)

---

## 6. 길(바닥) 만들기

### 6.1 Floor2 만들기
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `FloorPrototype04x01x04`
2. 이름 변경: `Floor2`
3. **Transform** 값:
   - Position: `0, 0, 12`
   - Rotation: `0, 0, 0`
   - Scale: `1, 1, 4`

### 6.2 Floor3 만들기
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `FloorPrototype08x01x08`
2. 이름 변경: `Floor3`
3. **Transform** 값:
   - Position: `0, 0, 36`
   - Rotation: `0, 0, 0`
   - Scale: `4, 1, 4`

### 6.3 Floor4 만들기
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `FloorPrototype04x01x04`
2. 이름 변경: `Floor4`
3. **Transform** 값:
   - Position: `0, 0, 54`
   - Rotation: `0, 0, 0`
   - Scale: `1, 1, 1`

### 6.4 BigBlock 만들기
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `CubePrototype04x04x04`
2. 이름 변경: `BigBlock`
3. **Transform** 값:
   - Position: `0, 0, 36`
   - Rotation: `0, 0, 0`
   - Scale: `5, 1, 5`

---

## 7. 스테이지 배경 만들기

### 7.1 Wall1 만들기
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `PillaPrototype02x08x02`
2. 이름 변경: `Wall1`
3. **Transform** 값:
   - Position: `32, -10, 36`
   - Rotation: `0, 0, 0`
   - Scale: `1, 6, 30`

### 7.2 Wall2 만들기
1. **Hierarchy** → **Wall1** 우클릭 → **Duplicate**
2. 우클릭 → **Rename** → `Wall2`
3. **Transform** 값:
   - Position: `-32, -10, 36`
   - Rotation: `0, 0, 0`
   - Scale: `1, 6, 30`

> 💡 분위기 연출을 위한 물체 배치

---

## 8. 배경 장식품 만들기

### 8.1 Pillar 만들기
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `JoinInnerPrototype01x06x01`
2. 이름 변경: `Pillar`
3. **Transform** 값:
   - Position: `0, -15, 100`
   - Rotation: `0, 315, 0`
   - Scale: `20, 10, 20`

---

## 9. 장애물 배치하기

### 9.1 Block 생성
1. **Project** → **Assets** → **Standard Assets** → **Prototyping** → **Prefabs** → `BlockPrototype04x04x04`
2. 우클릭 → **Duplicate** 4번 반복
3. 이름 변경: `Block1`, `Block2`, `Block3`, `Block4`, `Block5`

### 9.2 각 Block의 위치 및 크기 설정

#### Block1
- Position: `0, 0, 8`
- Rotation: `0, 0, 0`
- Scale: `0.5, 0.5, 0.5`

#### Block2
- Position: `12, 0, 24.5`
- Rotation: `0, 0, 0`
- Scale: `0.5, 0.5, 0.75`

#### Block3
- Position: `12, 0, 33`
- Rotation: `0, 0, 0`
- Scale: `1, 1, 1`

#### Block4
- Position: `-11, 0, 32`
- Rotation: `0, 0, 0`
- Scale: `0.5, 0.5, 0.5`

#### Block5
- Position: `-13.5, 0, 38`
- Rotation: `0, 0, 0`
- Scale: `0.5, 0.5, 0.5`

---

## 10. 텍스처 구하기

### 10.1 Asset Store에서 다운로드
1. **Window** → **Asset Store**
2. `yughues free metal materials` 검색
3. `Yughues Free Metal Materials` 클릭
4. **Download** 클릭 후 **Import** 클릭
5. **Import** 클릭

---

## 11. 텍스처 입히기

### 11.1 Floor1 ~ Floor4에 텍스처 적용
- **Project** → **Assets** → **Metal textures pack** → **pattern 13** → **diffuse**를 Floor1 ~ Floor4에 드래그 앤 드롭

### 11.2 Wall1, Wall2에 텍스처 적용
- **Project** → **Assets** → **Metal textures pack** → **pattern 09** → **diffuse**를 Wall1, Wall2에 드래그 앤 드롭

### 11.3 Block1 ~ Block5에 텍스처 적용
- **Project** → **Assets** → **Metal textures pack** → **pattern 02** → **diffuse**를 Block1 ~ Block5에 드래그 앤 드롭

### 11.4 BigBlock에 텍스처 적용
- **Project** → **Assets** → **Metal textures pack** → **pattern 10** → **diffuse**를 BigBlock에 드래그 앤 드롭

### 11.5 Pillar에 텍스처 적용
- **Project** → **Assets** → **Metal textures pack** → **pattern 14** → **diffuse**를 Pillar에 드래그 앤 드롭

---

## 12. 라이트 추가하기

### 12.1 Directional Light 조정
1. **Hierarchy** → **Directional Light** 선택
2. **Inspector** → **Light** → **Intensity**: `0.2`

### 12.2 Spotlight 추가
1. **Hierarchy** → **Create** → **Light** → **Spotlight**
2. 우클릭 → **Duplicate** 2번
3. 이름 변경: `Spotlight1`, `Spotlight2`, `Spotlight3`

#### Spotlight1 설정
- **Transform**:
  - Position: `0, 10, 0`
  - Rotation: `90, 0, 0`
  - Scale: `1, 1, 1`
- **Light**:
  - Range: `23`
  - Spot Angle: `50`
  - Intensity: `8`

#### Spotlight2 설정
- **Transform**:
  - Position: `0, 11, 24.6`
  - Rotation: `90, 0, 0`
  - Scale: `1, 1, 1`
- **Light**:
  - Range: `25`
  - Spot Angle: `56`

#### Spotlight3 설정
- **Transform**:
  - Position: `0, 7.5, 54`
  - Rotation: `90, 0, 0`
  - Scale: `1, 1, 1`
- **Light**:
  - Range: `20`
  - Spot Angle: `34`

### 12.3 Point Light 추가
1. **Hierarchy** → **Create** → **Light** → **Point Light**
2. 우클릭 → **Duplicate** 1번
3. 이름 변경: `Pointlight1`, `Pointlight2`

#### Pointlight1 설정
- **Transform**:
  - Position: `-19.2, 6, 32`
  - Rotation: `0, 0, 0`
  - Scale: `1, 1, 1`
- **Light**:
  - Range: `28`
  - Intensity: `8`

#### Pointlight2 설정
- **Transform**:
  - Position: `13, 3.5, 39`
  - Rotation: `0, 0, 0`
  - Scale: `1, 1, 1`
- **Light**:
  - Range: `8`
  - Intensity: `6`

---

## 13. 낙하 판정 영역 만들기

### 13.1 OutArea 생성
1. **Hierarchy** → **Create** → **3D Object** → **Cube**
2. 이름 변경: `OutArea`
3. **Transform** 값:
   - Position: `0, -33, 0`
   - Rotation: `0, 0, 0`
   - Scale: `1000, 1, 1000`

### 13.2 Mesh Renderer 제거
1. **Hierarchy** → **OutArea** 선택
2. **Inspector** → **Mesh Renderer** → 설정(톱니바퀴 아이콘) → **Remove Component**

### 13.3 Trigger 영역으로 설정
1. **Inspector** → **Box Collider** → **Is Trigger** 체크

### 13.4 스크립트 추가
1. **Hierarchy** → **OutArea** 선택
2. **Inspector** → **Add Component** → **New Script**
3. Name: `Out`
4. **Create and Add** 클릭

### 13.5 스크립트 작성
1. **Project** → **Assets** → **Out** 더블클릭
2. 스크립트 작성

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Out : MonoBehaviour
{
    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            SceneManager.LoadScene("Main");
        }
    }
}
```

---

## 14. 목표 지점 만들기

### 14.1 GoalArea 생성
1. **Hierarchy** → **Create** → **3D Object** → **Cube**
2. 이름 변경: `GoalArea`
3. **Transform** 값:
   - Position: `0, 1, 54.5`
   - Rotation: `0, 0, 0`
   - Scale: `4, 2, 3`

### 14.2 Mesh Renderer 제거
1. **Hierarchy** → **GoalArea** 선택
2. **Inspector** → **Mesh Renderer** → 설정(톱니바퀴 아이콘) → **Remove Component**

### 14.3 Trigger 영역으로 설정
1. **Inspector** → **Box Collider** → **Is Trigger** 체크

### 14.4 스크립트 추가
1. **Hierarchy** → **GoalArea** 선택
2. **Inspector** → **Add Component** → **New Script**
3. Name: `GoalArea`
4. **Create and Add** 클릭

### 14.5 스크립트 작성
1. **Project** → **Assets** → **GoalArea** 더블클릭
2. 스크립트 작성

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GoalArea : MonoBehaviour
{
    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            GameObject.Find("Canvas").GetComponent<GameResult>().SetResult();
        }
    }
}
```

---

## 15. 타이머 텍스트 만들기

### 15.1 TimeText 생성
1. **Hierarchy** → **Create** → **UI** → **Text**
2. 이름 변경: `TimeText`

### 15.2 위치 설정
1. **Inspector** → **Rect Transform** → **Anchor Presets** (조준선 그림) → **left, top** 선택
2. **Rect Transform** 값:
   - Pos X: `90`
   - Pos Y: `-20`
   - Pos Z: `0`

### 15.3 텍스트 속성 설정
1. **Inspector** → **Text (Script)**:
   - Text: `Time : 0`
   - Font Size: `22`
   - Color: Red (`255, 0, 0, 255`)

### 15.4 확인
- **Hierarchy** → **TimeText** 더블클릭하여 확인

### 15.5 스크립트 추가
1. **Hierarchy** → **TimeText** 선택
2. **Inspector** → **Add Component** → **New Script**
3. Name: `Timer`
4. **Create and Add** 클릭

### 15.6 스크립트 작성
1. **Project** → **Assets** → **Timer** 더블클릭
2. 스크립트 작성

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public static float time = 0.0f;
    private Text timeText;

    void Start()
    {
        time = 0.0f;
        timeText = GetComponent<Text>();
    }

    void Update()
    {
        time += Time.deltaTime;
        timeText.text = "Time : " + time.ToString("f2");
    }
}
```

---

## 16. 결과 화면 텍스트

### 16.1 ResultTitle 만들기
1. **Hierarchy** → **Create** → **UI** → **Text**
2. 이름 변경: `ResultTitle`

#### 위치 설정
- **Inspector** → **Rect Transform**:
  - **Anchor Presets**: middle, center
  - Pos X: `0`, Pos Y: `80`, Pos Z: `50`
  - Width: `200`, Height: `50`

#### 텍스트 속성
- **Text (Script)**:
  - Text: `Game Result`
  - Font Size: `32`
  - Alignment: Center, Center
  - Color: Red (`255, 0, 0, 255`)

### 16.2 ResultTimeText 만들기
1. **Hierarchy** → **Create** → **UI** → **Text**
2. 이름 변경: `ResultTimeText`

#### 위치 설정
- **Inspector** → **Rect Transform**:
  - **Anchor Presets**: middle, center
  - Pos X: `0`, Pos Y: `-30`, Pos Z: `0`
  - Width: `200`, Height: `40`

#### 텍스트 속성
- **Text (Script)**:
  - Text: `ResultTime : 0`
  - Font Size: `24`
  - Alignment: Center, Center
  - Color: Sky (`0, 255, 255, 255`)

### 16.3 BestTimeText 만들기
1. **Hierarchy** → **Create** → **UI** → **Text**
2. 이름 변경: `BestTimeText`

#### 위치 설정
- **Inspector** → **Rect Transform**:
  - **Anchor Presets**: middle, center
  - Pos X: `0`, Pos Y: `0`, Pos Z: `0`
  - Width: `200`, Height: `40`

#### 텍스트 속성
- **Text (Script)**:
  - Text: `BestTime : 0`
  - Font Size: `24`
  - Alignment: Center, Center
  - Color: Sky (`0, 255, 255, 255`)

---

## 17. 재시작 버튼

### 17.1 RetryButton 만들기
1. **Hierarchy** → **Create** → **UI** → **Button**
2. 이름 변경: `RetryButton`

### 17.2 위치 설정
- **Inspector** → **Rect Transform**:
  - **Anchor Presets**: middle, center
  - Pos X: `0`, Pos Y: `-80`, Pos Z: `0`
  - Width: `160`, Height: `30`

### 17.3 텍스트 설정
1. **Hierarchy** → **RetryButton** → **Text** 선택
2. **Inspector** → **Text (Script)**:
   - Text: `Retry?`
   - Font Size: `14`
   - Alignment: Center, Center

---

## 18. 결과 화면 그룹화

### 18.1 Empty 오브젝트 추가
1. **Hierarchy** → **Create** → **Create Empty**
2. 이름 변경: `Result`

### 18.2 부모-자식 관계 설정
1. **Result**를 **Canvas** 아래 **TimeText** 다음에 위치하도록 드래그 앤 드롭
2. **ResultTitle**, **ResultTimeText**, **BestTimeText**, **RetryButton**을 **Result**로 드래그 앤 드롭

### 18.3 Result 비활성화
1. **Hierarchy** → **Result** 선택
2. **Inspector** → Tag 위의 체크박스 해제

---

## 19. 결과 화면 스크립트

### 19.1 스크립트 추가
1. **Hierarchy** → **Canvas** 선택
2. **Inspector** → **Add Component** → **New Script**
3. Name: `GameResult`
4. **Create and Add** 클릭

### 19.2 스크립트 작성
1. **Project** → **Assets** → **GameResult** 더블클릭
2. 스크립트 작성

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameResult : MonoBehaviour
{
    public Text resultTime;
    public Text bestTime;
    public GameObject parts;

    void Start()
    {
        parts.SetActive(false);
    }

    public void SetResult()
    {
        resultTime.text = "ResultTime : " + Timer.time.ToString("f2");
        
        if (PlayerPrefs.HasKey("bestTime"))
        {
            float best = PlayerPrefs.GetFloat("bestTime");
            if (best > Timer.time)
            {
                best = Timer.time;
                PlayerPrefs.SetFloat("bestTime", best);
            }
            bestTime.text = "BestTime : " + best.ToString("f2");
        }
        else
        {
            PlayerPrefs.SetFloat("bestTime", Timer.time);
            bestTime.text = "BestTime : " + Timer.time.ToString("f2");
        }

        parts.SetActive(true);
        Time.timeScale = 0.0f;
    }

    public void OnRetry()
    {
        Time.timeScale = 1.0f;
        SceneManager.LoadScene("Main");
    }
}
```

---

## 20. 속성값 설정하기

### 20.1 GameResult 스크립트 연결
1. **Hierarchy** → **Canvas** 선택
2. **Inspector** → **Game Result (Script)**:
   - **Result Time**: Canvas → Result → ResultTimeText를 드래그 앤 드롭
   - **Best Time**: Canvas → Result → BestTimeText를 드래그 앤 드롭
   - **Parts**: Canvas → Result를 드래그 앤 드롭

---

## 21. 버튼 클릭 이벤트 연결

### 21.1 이벤트 설정
1. **Hierarchy** → **Canvas** → **Result** → **RetryButton** 선택
2. **Inspector** → **Button (Script)** → **On Click()** → `+` 클릭
3. **Canvas**를 **None** 영역으로 드래그 앤 드롭

### 21.2 함수 선택
1. **On Click()** → **No Function** 드롭다운
2. **GameResult** → **OnRetry()** 선택

---

## 22. 사운드 추가하기

### 22.1 Asset Store에서 다운로드
1. **Window** → **Asset Store**
2. `Free music pack` 검색
3. `Free Music Pack` 클릭
4. **Download** 클릭 후 **Import** 클릭

### 22.2 Audio Source 설정
1. **Hierarchy** → **Pillar** 선택
2. **Inspector** → **Add Component** → **Audio** → **Audio Source**

### 22.3 오디오 클립 선택
1. **Inspector** → **Audio Source** → **AudioClip** 옆 동그라미 아이콘 클릭
2. `Road Hard - Solo` 선택

### 22.4 반복 재생 설정
- **Inspector** → **Audio Source** → **Loop** 체크

### 22.5 3D 사운드 설정
- **Inspector** → **Audio Source** → **Spatial Blend** → `1`로 설정

---

## 23. 플레이 및 최종 설정

### 23.1 게임 실행
- **Play** 버튼을 클릭하여 게임 테스트

### 23.2 라이팅 설정 (Retry 시 조명 문제 해결)
1. **Window** → **Rendering** → **Lighting Settings**
2. **Auto Generate** 체크 해제
3. **Generate Lighting** 클릭

---


## ✅ 완료!

모든 단계를 완료하면 장애물을 피해 목표 지점까지 도달하는 런 게임이 완성됩니다.

### 게임 플레이 방법
- **이동**: `WASD` 키 또는 방향키
- **목표**: 장애물을 피하며 최대한 빠르게 골인 지점에 도달
- **재도전**: 게임 종료 후 Retry 버튼 클릭

--- 

# Unity C# Script 입문 가이드

> Unity 2021.3.6f1 버전 기준  
> GameObject & Script 학습

---

## 목차
1. [스테이지 만들기](#1-스테이지-만들기)
2. [볼 만들기](#2-볼-만들기)
3. [위치 출력하기](#3-위치-출력하기)
4. [조건문과 논리 제어](#4-조건문과-논리-제어)
5. [컴포넌트 제어](#5-컴포넌트-제어)
6. [카메라 제어](#6-카메라-제어)
7. [입력 처리](#7-입력-처리)
8. [물리 시뮬레이션](#8-물리-시뮬레이션)
9. [충돌 처리](#9-충돌-처리)
10. [씬 관리](#10-씬-관리)
11. [태그 시스템](#11-태그-시스템)
12. [게임 매니저](#12-게임-매니저)
13. [UI 시스템](#13-ui-시스템)
14. [프리팹과 인스턴스화](#14-프리팹과-인스턴스화)
15. [상속](#15-상속)

---

## 1. 스테이지 만들기

### 1.1 Ground 오브젝트 생성
1. **Hierarchy** → **3D Object** → **Cube**
2. **Hierarchy** → **Cube** → 우클릭 → **Rename** → `Ground`

### 1.2 카메라 및 라이트 설정
1. **Hierarchy** → **Main Camera** → **Inspector** → **Transform**
   - Position: `0, 11, -52`

2. **Hierarchy** → **Directional Light** → **Inspector** → **Transform**
   - Position: `40, 23, 40`
   - Rotation: `50, -30, 1`

### 1.3 Ground 변형
1. **Hierarchy** → **Ground** → **Inspector** → **Transform**
   - Rotation: `10, 0, 0`
   - Scale: `20, 1, 70`

### 1.4 Material 생성 및 적용
1. **Project** → **Assets** → **Create** → **Material**
2. 이름 변경: `GroundMaterial`
3. **Inspector** → **Main Maps** → **Albedo** → 원하는 색 선택
4. `GroundMaterial`을 **Hierarchy** → **Ground**로 드래그 앤 드롭

---

## 2. 볼 만들기

### 2.1 Sphere 오브젝트 생성
1. **Hierarchy** → **3D Object** → **Sphere**
2. 이름 변경: `Ball`

### 2.2 위치 설정
1. **Hierarchy** → **Ball** → **Inspector** → **Transform**
   - Position: `0, 15, -30`

### 2.3 물리 컴포넌트 추가
1. **Hierarchy** → **Ball** → **Inspector**
2. **Add Component** → **Physics** → **Rigidbody**

> 💡 **Rigidbody**: 게임 오브젝트가 물리력의 영향을 받도록 하는 컴포넌트

### 2.4 테스트
- **Play** 버튼 클릭하여 볼이 떨어지는지 확인

---

## 3. 위치 출력하기

### 3.1 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `PrtPosition`
3. `PrtPosition` 더블클릭

### 3.2 코드 작성

```csharp
using UnityEngine;

public class PrtPosition : MonoBehaviour
{
    float startingPoint;
    
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Start");
        startingPoint = transform.position.z;
    }
    
    // Update is called once per frame
    void Update()
    {
        float distance;
        distance = transform.position.z - startingPoint;
        Debug.Log("Distance: " + distance);
    }
}
```

### 3.3 스크립트 연결
1. **Hierarchy** → **Ball** → **Inspector**
2. **Add Component** → **Scripts** → `PrtPosition`
   - 또는 스크립트 파일을 Ball로 드래그 앤 드롭

### 3.4 확인
1. **Play** 버튼 클릭
2. **Window** → **Console** 창에서 거리 값 확인

---

## 4. 조건문과 논리 제어

### 4.1 if문을 사용하여 위치 출력하기

#### 코드 수정

```csharp
using UnityEngine;

public class PrtPosition : MonoBehaviour
{
    float startingPoint;
    
    void Start()
    {
        Debug.Log("Start");
        startingPoint = transform.position.z;
    }
    
    void Update()
    {
        float distance;
        distance = transform.position.z - startingPoint;
        
        if (distance > 40)
            Debug.Log("Over 40: " + distance);
        else if (distance > 20)
            Debug.Log("Over 20: " + distance);
        else
            Debug.Log("Less than 20: " + distance);
    }
}
```

### 4.2 조건에 맞을 때 한 번만 출력하기

#### 코드 작성

```csharp
using UnityEngine;

public class PrtPosition : MonoBehaviour
{
    float startingPoint;
    bool isOver20 = true;
    bool isOver40 = true;
    
    void Start()
    {
        startingPoint = transform.position.z;
    }
    
    void Update()
    {
        float distance;
        distance = transform.position.z - startingPoint;
        
        if (distance > 40)
        {
            if (isOver40)
            {
                Debug.Log("Over 40 distance: " + distance);
                isOver40 = false;
            }
        }
        else if (distance > 20)
        {
            if (isOver20)
            {
                Debug.Log("Over 20 distance: " + distance);
                isOver20 = false;
            }
        }
    }
}
```

---

## 5. 컴포넌트 제어

### 5.1 볼의 반지름 변경하기

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `RadiusChange`

#### 코드 작성

```csharp
using UnityEngine;

public class RadiusChange : MonoBehaviour
{
    SphereCollider myCollider = new SphereCollider();
    
    // Start is called before the first frame update
    void Start()
    {
        Rigidbody myRigidbody = GetComponent<Rigidbody>();
        Debug.Log("UseGravity: " + myRigidbody.useGravity);
        
        myCollider = GetComponent<SphereCollider>();
    }
    
    // Update is called once per frame
    void Update()
    {
        myCollider.radius = myCollider.radius + 0.01f;
    }
}
```

> 💡 **Collider 컴포넌트**: 오브젝트의 충돌을 체크

#### 스크립트 연결 및 실행
1. **Hierarchy** → **Ball** → **Inspector** → **Add Component** → **Scripts** → `RadiusChange`
2. **Play** 버튼 클릭

#### 컴포넌트 제거
- **Hierarchy** → **Ball** → **Inspector** → **RadiusChange (Script)** → Kebab Menu → **Remove Component**

---

## 6. 카메라 제어

### 6.1 오브젝트 따라가는 카메라

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `CameraFollow`

#### 코드 작성

```csharp
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    GameObject ball;
    
    // Start is called before the first frame update
    void Start()
    {
        ball = GameObject.Find("Ball");
    }
    
    // Update is called once per frame
    void Update()
    {
        transform.position = new Vector3(0,
            ball.transform.position.y + 3,
            ball.transform.position.z - 14);
    }
}
```

#### 스크립트 연결
1. **Hierarchy** → **Main Camera** → **Inspector**
2. **Add Component** → **Scripts** → `CameraFollow`
3. **Play** 버튼 클릭

---

## 7. 입력 처리

### 7.1 키보드로 Ground 움직이기 (←, → 키)

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `GroundMove`

#### 코드 작성

```csharp
using UnityEngine;

public class GroundMove : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
    }
    
    // Update is called once per frame
    void Update()
    {
        //Debug.Log(Input.GetAxis("Horizontal"));
        //Debug.Log(Input.GetAxis("Vertical"));
        
        float zRotation = transform.localEulerAngles.z;
        zRotation = zRotation - Input.GetAxis("Horizontal") * 0.1f;
        transform.localEulerAngles = new Vector3(10, 0, zRotation);
    }
}
```

#### 스크립트 연결
1. **Hierarchy** → **Ground** → **Inspector**
2. **Add Component** → **Scripts** → `GroundMove`
3. **Play** 버튼 클릭 후 ←, → 키로 테스트

---

## 8. 물리 시뮬레이션

### 8.1 공 튀어 오르기

#### Physic Material 생성
1. **Project** → **Assets** → **Create** → **Physic Material**
2. 이름 변경: `BallBounce`
3. **Inspector** → **Bounciness**: `0.9`

#### Material 적용
1. **Hierarchy** → **Ball** → **Inspector** → **Sphere Collider** → **Material**
2. `BallBounce`를 드래그 앤 드롭 또는 선택
3. **Play** 버튼 클릭

#### Ground에도 적용
1. **Hierarchy** → **Ground** → **Inspector** → **Box Collider** → **Material**
2. `BallBounce` 선택 (Bounciness: `0.6`으로 조정)
3. **Play** 버튼 클릭

### 8.2 키 입력으로 공 튀어 오르기 (Space 키)

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `BallJump`

#### 코드 작성

```csharp
using UnityEngine;

public class BallJump : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
    }
    
    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            GetComponent<Rigidbody>().AddForce(Vector3.up * 300);
        }
    }
}
```

#### 스크립트 연결
1. **Hierarchy** → **Ball** → **Inspector**
2. **Add Component** → **Scripts** → `BallJump`
3. **Play** 버튼 클릭 후 Space 키로 테스트

---

## 9. 충돌 처리

### 9.1 마우스로 Ground 움직이기

#### GroundMove 스크립트 수정

```csharp
using UnityEngine;

public class GroundMove : MonoBehaviour
{
    void Start()
    {
    }
    
    void Update()
    {
        float zRotation = transform.localEulerAngles.z;
        zRotation = zRotation - Input.GetAxis("Horizontal") * 0.1f;
        transform.localEulerAngles = new Vector3(10, 0, zRotation);
        
        if (Input.touchCount > 0 || Input.GetMouseButton(0))
        {
            Debug.Log("Mouse Down" + Input.mousePosition);
            
            if (Input.mousePosition.x < Screen.width / 2)
            {
                transform.localEulerAngles = new Vector3(10, 0,
                    transform.localEulerAngles.z + 0.05f);
            }
            else
            {
                transform.localEulerAngles = new Vector3(10, 0,
                    transform.localEulerAngles.z - 0.05f);
            }
        }
    }
}
```

### 9.2 장애물 설치 및 좌우 이동

#### 장애물 생성
1. **Hierarchy** → **3D Object** → **Cylinder**
2. 이름 변경: `Obstacle`
3. **Inspector** → **Transform**
   - Position: `0, 2, -7`

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `ObstacleMove`

#### 코드 작성

```csharp
using UnityEngine;

public class ObstacleMove : MonoBehaviour
{
    float delta = 0.01f;
    
    // Start is called before the first frame update
    void Start()
    {
    }
    
    // Update is called once per frame
    void Update()
    {
        float newXPosition = transform.position.x + delta;
        transform.position = new Vector3(newXPosition, 2, -7);
        
        if (transform.position.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.position.x > 9)
        {
            delta = -0.01f;
        }
    }
}
```

#### 스크립트 연결
1. **Hierarchy** → **Obstacle** → **Inspector**
2. **Add Component** → **Scripts** → `ObstacleMove`
3. **Play** 버튼 클릭

### 9.3 장애물과 그라운드 합치기

#### Stage 오브젝트 생성
1. **GameObject** → **Create Empty**
2. 이름 변경: `Stage`
3. **Inspector** → **Transform**
   - Position: `0, 0, 0`
   - Rotation: `10, 0, 0`

#### 부모-자식 관계 설정
1. **Hierarchy**에서 `Ground`와 `Obstacle`을 `Stage`로 드래그 앤 드롭
2. **Hierarchy** → **Stage** → **Ground** → **Inspector** → **Transform**
   - Position: `0, 0, 0`
   - Rotation: `10, 0, 0`
3. **Stage** → **Ground**에서 **Ground Move (Script)** 제거 (Kebab Menu → Remove Component)
4. **Stage** → **Obstacle** → **Inspector** → **Transform**
   - Position: `0, 2, -7`
   - Scale: `1, 1, 1`
5. **Stage** → **Obstacle**에서 **Obstacle Move (Script)** 제거
6. **Hierarchy** → **Stage** → **Inspector**
7. **Add Component** → **Scripts** → `GroundMove`
8. **Play** 버튼 클릭

### 9.4 장애물과 그라운드 같이 움직이기

#### ObstacleMove 스크립트 수정

```csharp
using UnityEngine;

public class ObstacleMove : MonoBehaviour
{
    float delta = 0.01f;
    
    void Start()
    {
    }
    
    void Update()
    {
        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition,
            transform.localPosition.y,
            transform.localPosition.z);
        
        if (transform.localPosition.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
}
```

> 💡 **position vs localPosition**  
> - `position`: 월드 좌표계의 절대 위치  
> - `localPosition`: 부모 오브젝트에 대한 상대적 위치

#### 스크립트 연결
1. **Hierarchy** → **Stage** → **Obstacle** → **Inspector**
2. **Add Component** → **Scripts** → `ObstacleMove`
3. **Play** 버튼 클릭

---

## 10. 씬 관리

### 10.1 C# Method & Parameter

#### ObstacleMove 스크립트에 메서드 추가

```csharp
using UnityEngine;

public class ObstacleMove : MonoBehaviour
{
    void TestMethod(string name, int a)
    {
        float distance = Vector3.Distance(
            GameObject.Find(name).transform.position,
            transform.position);
        Debug.Log(name + "까지 거리: " + distance);
    }
    
    float delta = 0.01f;
    
    void Start()
    {
    }
    
    void Update()
    {
        TestMethod("Ball", 0);
        
        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition,
            transform.localPosition.y,
            transform.localPosition.z);
        
        if (transform.localPosition.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
}
```

### 10.2 물체의 충돌 알아보기

#### OnCollisionEnter 메서드 추가

```csharp
using UnityEngine;

public class ObstacleMove : MonoBehaviour
{
    void OnCollisionEnter(Collision collision)
    {
        //Debug.Log(collision.gameObject.name);
        Vector3 direction = transform.position - 
            collision.gameObject.transform.position;
        // 나의 위치에서 상대의 위치를 빼면 방향이 결정
        direction = direction.normalized * 1000; // 힘 결정
        collision.gameObject.GetComponent<Rigidbody>().AddForce(direction);
    }
    
    float delta = 0f;
    
    void Start()
    {
    }
    
    void Update()
    {
        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition,
            transform.localPosition.y,
            transform.localPosition.z);
        
        if (transform.localPosition.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
}
```

> 💡 **충돌하면 호출되는 메서드**: `OnCollisionEnter(Collision col)`  
> `col`: 충돌체 정보

#### 테스트
- Stage 기울기 변경 실행
- 객체의 Collider 변경 실행
- **Play** 버튼 클릭

### 10.3 볼 낙하 후 게임 재시작하기

#### 빌드 설정
1. **File** → **Build Settings**
2. **Add Open Scenes** 클릭
3. **Build** 클릭
4. 새 폴더 생성: `SceneSave`
5. 폴더 선택

#### FailZone 생성
1. **Hierarchy** → **Stage** → **Ground** 선택 → Ctrl+C, Ctrl+V
2. **Hierarchy** → **Stage** → **Ground(1)**을 상위 레벨로 드래그 앤 드롭
3. 이름 변경: `FailZone`
4. **Inspector** → **Transform**
   - Position: `0, -15, 0`
   - Rotation: `20, 0, 0`
   - Scale: `100, 1, 200`
5. **Inspector** → **Box Collider** → **Is Trigger** 체크
6. **Inspector** → **Mesh Renderer** → Kebab Menu → **Remove Component**

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `FailZone`

#### 코드 작성

```csharp
using UnityEngine;
using UnityEngine.SceneManagement;

public class FailZone : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        //Debug.Log(collider.gameObject.name);
        if (collider.gameObject.name == "Ball")
        {
            SceneManager.LoadScene(0);
        }
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

#### 스크립트 연결
1. **Hierarchy** → **FailZone** → **Inspector**
2. **Add Component** → **Scripts** → `FailZone`
3. **Play** 버튼 클릭

---

## 11. 태그 시스템

### 11.1 코인 표시 및 코인 없애기

#### 코인 생성
1. **Hierarchy** → **3D Object** → **Cylinder**
2. 이름 변경: `Coin`
3. **Inspector** → **Transform**
   - Position: `0, 5, -10`
   - Rotation: `110, 0, 0`
   - Scale: `1, 0.15, 1`

#### Material 생성 및 적용
1. **Project** → **Assets** → **Create** → **Material**
2. 이름 변경: `CoinColor`
3. **Inspector** → **Main Maps** → **Albedo** → Yellow 계열 선택
4. `CoinColor`를 **Hierarchy** → **Coin**으로 드래그 앤 드롭

#### Trigger 설정
1. **Hierarchy** → **Coin** → **Inspector**
2. **Capsule Collider** → **Is Trigger** 체크
3. **Coin**을 **Stage**로 드래그 앤 드롭

#### 스크립트 생성
1. **Project** → **Assets** → **Create** → **C# Script**
2. 이름 변경: `CoinTrigger`

#### 코드 작성

```csharp
using UnityEngine;

public class CoinTrigger : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.name == "Ball")
        {
            Destroy(gameObject);
        }
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

#### 스크립트 연결 및 복사
1. `CoinTrigger`를 **Hierarchy** → **Stage** → **Coin**으로 드래그 앤 드롭
2. **Play** 버튼 클릭
3. **Hierarchy** → **Stage** → **Coin** → Ctrl+C, Ctrl+V 5번
4. 각 코인 위치 조정
5. **Play** 버튼 클릭

### 11.2 Tag 이용하기

#### Tag 생성
1. **Hierarchy** → **Stage** → **Coin** → **Inspector**
2. **Tag (Untagged)** → **Add Tag**
3. `+` 클릭 → `Coin` 입력 → **Save**

#### Tag 적용
1. **Hierarchy** → **Stage** → 모든 Coin 선택 (Shift 또는 Ctrl 이용)
2. **Inspector** → **Tag (Untagged)** → **Coin** 선택

> 💡 **Tag**: 여러 개의 게임 오브젝트를 하나의 이름으로 관리

#### CameraFollow 스크립트에서 Tag 활용

```csharp
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    GameObject ball;
    
    void Start()
    {
        ball = GameObject.Find("Ball");
        
        GameObject[] coins = GameObject.FindGameObjectsWithTag("Coin");
        for (int i = 0; i < coins.Length; i++)
        {
            Debug.Log(coins[i].name);
        }
    }
    
    void Update()
    {
        transform.position = new Vector3(0,
            ball.transform.position.y + 3,
            ball.transform.position.z - 14);
    }
}
```

### 11.3 아이템 먹고 장애물 없애기

#### Obstacle Tag 생성
1. **Hierarchy** → **Stage** → **Obstacle** → **Inspector**
2. **Tag (Untagged)** → **Add Tag**
3. `+` 클릭 → `Obstacle` 입력 → **Save**

#### Obstacle 복사 및 Tag 적용
1. **Hierarchy** → **Stage** → **Obstacle** → Ctrl+C, Ctrl+V 3번
2. 위치 조정
3. 모든 Obstacle 선택 → **Inspector** → **Tag** → **Obstacle**

#### RedCoin 생성
1. **Hierarchy** → **Stage** → **Coin** → Ctrl+C, Ctrl+V
2. 이름 변경: `RedCoin`
3. **Project** → **Assets** → **Create** → **Material**
4. 이름 변경: `RedCoin`
5. Red 색상 선택
6. `RedCoin` Material을 **RedCoin** 오브젝트로 드래그 앤 드롭

#### RedCoinItem 스크립트 생성

```csharp
using UnityEngine;

public class RedCoinItem : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.name == "Ball")
        {
            DestroyObstacles();
            Destroy(gameObject);
        }
    }
    
    void DestroyObstacles()
    {
        GameObject[] obstacles = GameObject.FindGameObjectsWithTag("Obstacle");
        for (int i = 0; i < obstacles.Length; i++)
        {
            Destroy(obstacles[i]);
        }
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

#### RedCoinItem 스크립트 수정

```csharp
using UnityEngine;

public class RedCoinItem : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.name == "Ball")
        {
            GameObject.Find("GameManager").SendMessage("RedCoinStart");
            Destroy(gameObject);
        }
    }
    
    // DestroyObstacles() 메서드 삭제
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

### 12.4 획득한 동전 개수 세기

#### GameManager에 코드 추가

```csharp
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    int coinCount = 0;
    
    void RestartGame()
    {
        SceneManager.LoadScene(0);
    }
    
    void RedCoinStart()
    {
        DestroyObstacles();
    }
    
    void DestroyObstacles()
    {
        GameObject[] obstacles = GameObject.FindGameObjectsWithTag("Obstacle");
        for (int i = 0; i < obstacles.Length; i++)
        {
            Destroy(obstacles[i]);
        }
    }
    
    void GetCoin()
    {
        coinCount++;
        Debug.Log("동전 : " + coinCount);
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

#### CoinTrigger 스크립트 수정

```csharp
using UnityEngine;

public class CoinTrigger : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.name == "Ball")
        {
            GameObject.Find("GameManager").SendMessage("GetCoin");
            Destroy(gameObject);
        }
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

### 12.5 다른 클래스의 필드와 메서드 사용하기

#### public 접근 제어자 사용

##### GameManager 수정

```csharp
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public int coinCount = 0;
    
    public void RestartGame()  // public으로 변경
    {
        SceneManager.LoadScene(0);
    }
    
    void RedCoinStart()
    {
        DestroyObstacles();
    }
    
    void DestroyObstacles()
    {
        GameObject[] obstacles = GameObject.FindGameObjectsWithTag("Obstacle");
        for (int i = 0; i < obstacles.Length; i++)
        {
            Destroy(obstacles[i]);
        }
    }
    
    void GetCoin()
    {
        coinCount++;
        Debug.Log("동전 : " + coinCount);
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

> 💡 **public**: 다른 클래스에서 접근을 허용  
> 필드를 public으로 하면 Inspector 창에 나타나며 값을 입력할 수 있음

##### FailZone 수정 (GetComponent 사용)

```csharp
using UnityEngine;

public class FailZone : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        Debug.Log(collider.gameObject.name);
        
        if (collider.gameObject.name == "Ball")
        {
            // SendMessage 대신 GetComponent 사용
            GameObject gm = GameObject.Find("GameManager");
            GameManager gmComponent = gm.GetComponent<GameManager>();
            
            // 또는 한 줄로:
            // GameManager gmComponent = GameObject.Find("GameManager").GetComponent<GameManager>();
            
            gmComponent.RestartGame();
        }
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

---

## 13. UI 시스템

### 13.1 획득한 동전의 개수 표시하기

#### TextMeshPro 임포트
1. **Hierarchy** → **UI** → **Text - TextMeshPro**
2. **Import TMP Essentials** 클릭
3. **Import TMP Examples & Extras** 클릭

#### GameManager 스크립트 수정

```csharp
using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;  // TextMeshPro 네임스페이스 추가

public class GameManager : MonoBehaviour
{
    public int coinCount = 0;
    public TextMeshProUGUI coinText;  // UI 텍스트 참조
    
    public void RestartGame()
    {
        SceneManager.LoadScene(0);
    }
    
    void RedCoinStart()
    {
        DestroyObstacles();
    }
    
    void DestroyObstacles()
    {
        GameObject[] obstacles = GameObject.FindGameObjectsWithTag("Obstacle");
        for (int i = 0; i < obstacles.Length; i++)
        {
            Destroy(obstacles[i]);
        }
    }
    
    void GetCoin()
    {
        coinCount++;
        coinText.text = coinCount + "";  // UI 업데이트
        Debug.Log("동전 : " + coinCount);
    }
    
    void Start()
    {
    }
    
    void Update()
    {
    }
}
```

> ⚠️ **주의**: 한글을 포함하면 에러 발생. 한글은 따로 처리 필요

#### UI 연결
1. **Hierarchy** → **GameManager** → **Inspector**
2. **Game Manager (Script)** → **Coin Text**
3. **Hierarchy** → **Text (TMP)**를 **Coin Text** 슬롯으로 드래그 앤 드롭
4. **Play** 버튼 클릭

---

## 14. 프리팹과 인스턴스화

### 14.1 돌 던지기 기본 설정

#### Stone 오브젝트 생성
1. **Hierarchy** → **3D Object** → **Cube**
2. 이름 변경: `Stone`

#### Stone 스크립트 생성

```csharp
using UnityEngine;

public class Stone : MonoBehaviour
{
    Vector3 target;
    
    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.Find("Ball").transform.position;  // 위치 지정
    }
    
    // Update is called once per frame
    void Update()
    {
        // target 방향으로 움직이기
        transform.position = Vector3.MoveTowards(transform.position, target, 0.01f);
        // 돌 회전하기
        transform.Rotate(new Vector3(0, 0, 5));
    }
    
    void OnTriggerEnter(Collider collider)
    {
        Debug.Log(collider.gameObject.name);
        
        if (collider.gameObject.name == "Ball")
        {
            GameManager gmComponent = GameObject.Find("GameManager").GetComponent<GameManager>();
            gmComponent.RestartGame();
        }
    }
}
```

#### Stone 설정
1. **Hierarchy** → **Stone** → **Inspector**
2. **Box Collider** → **Is Trigger** 체크
3. `RedCoin` Material을 **Stone**으로 드래그 앤 드롭
4. **Stone**과 **Ball**을 **Stage**의 상단에 위치
5. **Play** 버튼 클릭

### 14.2 일정 간격으로 돌 발사하기

#### Shooter 설정
1. **Hierarchy** → **Stage** → **Obstacle(1)** 선택
2. 이름 변경: `Shooter`
3. **Obstacle Move (Script)** → Kebab Menu → **Remove Component**
4. `RedCoin` Material을 **Shooter**로 드래그 앤 드롭

#### Shooter 스크립트 생성

```csharp
using UnityEngine;

public class Shooter : MonoBehaviour
{
    float timeCount = 0;
    
    void Start()
    {
    }
    
    void Update()
    {
        timeCount += Time.deltaTime;
        
        if (timeCount > 3)
        {
            Debug.Log("돌을 던져라");
            timeCount = 0;
        }
    }
}
```

#### 스크립트 연결
1. `Shooter` 스크립트를 **Hierarchy** → **Stage** → **Shooter**로 드래그 앤 드롭
2. **Play** 버튼 클릭

### 14.3 Prefab 생성 및 사용

#### Prefab 생성
1. **Hierarchy** → **Stone** → **Inspector** → 체크박스 체크 (활성화)
2. **Hierarchy** → **Stone**을 **Project** → **Assets**로 드래그 앤 드롭
3. **Hierarchy** → **Stone** → **Delete** (삭제)

#### Shooter 스크립트 수정

```csharp
using UnityEngine;

public class Shooter : MonoBehaviour
{
    public GameObject stone;  // Prefab 참조
    float timeCount = 0;
    
    void Start()
    {
    }
    
    void Update()
    {
        timeCount += Time.deltaTime;
        
        if (timeCount > 3)
        {
            // Prefab 인스턴스화
            Instantiate(stone, transform.position, Quaternion.identity);
            timeCount = 0;
        }
    }
}
```

#### Prefab 연결
1. **Hierarchy** → **Stage** → **Shooter** → **Inspector**
2. **Shooter (Script)** → **Stone**
3. **Project** → **Assets** → **Stone** (Prefab)을 **Stone** 슬롯으로 드래그 앤 드롭
4. **Play** 버튼 클릭

---

## 15. 상속

### 15.1 ObstacleMove 클래스 수정

#### protected 키워드 추가

```csharp
using UnityEngine;

public class ObstacleMove : MonoBehaviour
{
    void OnCollisionEnter(Collision collision)
    {
        Vector3 direction = transform.position - 
            collision.gameObject.transform.position;
        direction = direction.normalized * 1000;
        collision.gameObject.GetComponent<Rigidbody>().AddForce(direction);
    }
    
    float delta = 0.01f;
    
    void Start()
    {
    }
    
    protected void Update()  // protected로 변경
    {
        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition,
            transform.localPosition.y,
            transform.localPosition.z);
        
        if (transform.localPosition.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
}
```

### 15.2 Shooter 클래스에서 상속 사용

```csharp
using UnityEngine;

public class Shooter : ObstacleMove  // ObstacleMove 상속
{
    public GameObject stone;
    float timeCount = 0;
    
    void Start()
    {
    }
    
    void Update()
    {
        base.Update();  // 부모 클래스의 Update() 호출
        
        timeCount += Time.deltaTime;
        
        if (timeCount > 3)
        {
            Instantiate(stone, transform.position, Quaternion.identity);
            timeCount = 0;
        }
    }
}
```

> 💡 **상속**  
> - `public class Shooter : ObstacleMove`: Shooter가 ObstacleMove를 상속받음
> - `base.Update()`: 부모 클래스의 Update() 메서드 호출
> - 경고 발생 시 `new base.Update()`로 변경

#### 테스트
- **Play** 버튼 클릭
- Shooter가 좌우로 움직이면서 돌을 발사하는지 확인

---

## 💾 저장 팁

모든 작업 후 **저장**을 잊지 마세요!
- **Ctrl + S**: 스크립트 저장
- **File** → **Save**: 씬 저장

---

## 📚 주요 개념 정리

### Unity 스크립트 생명주기
- `Start()`: 게임 오브젝트가 활성화될 때 한 번 실행
- `Update()`: 매 프레임마다 실행

### 충돌 감지 메서드
- `OnCollisionEnter()`: 물리적 충돌이 발생했을 때
- `OnTriggerEnter()`: Trigger 영역에 진입했을 때

### 입력 처리
- `Input.GetAxis()`: 축 입력 값 가져오기
- `Input.GetKeyDown()`: 키가 눌렸는지 확인
- `Input.GetMouseButton()`: 마우스 버튼 상태 확인
- `Input.mousePosition`: 마우스 위치

### 오브젝트 찾기 및 조작
- `GameObject.Find()`: 이름으로 오브젝트 찾기
- `GameObject.FindGameObjectsWithTag()`: 태그로 오브젝트 배열 찾기
- `GetComponent<>()`: 컴포넌트 가져오기
- `SendMessage()`: 다른 오브젝트의 메서드 호출

### Transform
- `transform.position`: 월드 좌표
- `transform.localPosition`: 로컬 좌표 (부모 기준)
- `transform.rotation`: 회전값
- `transform.localEulerAngles`: 오일러 각도 (로컬)

### 물리
- `Rigidbody.AddForce()`: 힘 추가
- `Vector3.MoveTowards()`: 목표 지점으로 이동
- `Vector3.Distance()`: 두 점 사이의 거리

### 게임 오브젝트 관리
- `Instantiate()`: 오브젝트 생성 (Prefab 인스턴스화)
- `Destroy()`: 오브젝트 삭제
- `SetActive()`: 오브젝트 활성화/비활성화

### 접근 제어자
- `public`: 외부에서 접근 가능, Inspector에 표시
- `private`: 클래스 내부에서만 접근 (기본값)
- `protected`: 상속받은 클래스에서도 접근 가능

---

## 🎮 완성된 게임 플레이

1. **이동**: 화살표 키 또는 마우스로 Ground 기울이기
2. **점프**: Space 키로 Ball 점프
3. **목표**: 
   - 코인 수집하기
   - 장애물 피하기
   - RedCoin으로 장애물 제거
   - Shooter의 돌 피하기
4. **재시작**: 낙하 시 자동으로 재시작

---

## ✅ 학습 완료!

이 튜토리얼을 통해 다음을 학습했습니다:
- ✅ Unity 기본 오브젝트 생성 및 조작
- ✅ C# 스크립트 작성 및 연결
- ✅ 조건문과 반복문 활용
- ✅ 컴포넌트 시스템 이해
- ✅ 입력 처리 (키보드, 마우스)
- ✅ 물리 시뮬레이션
- ✅ 충돌 감지 및 처리
- ✅ UI 시스템 활용
- ✅ 태그 시스템
- ✅ 게임 매니저 패턴
- ✅ Prefab 및 인스턴스화
- ✅ 객체 지향 프로그래밍 (상속)


