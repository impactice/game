# PROJECT: DESTROYER (striker2945)

## 🎮 프로젝트 소개
Canvas 기반 세로 슈팅 게임입니다. 플레이어는 기체를 선택하고 다양한 스테이지를 클리어하며 적을 물리치고 보스를 격파합니다.

## 🚀 주요 기능

### 게임플레이
- **3가지 조작 방식**: 방향키, WASD, 마우스 중 선택 가능
- **자동 사격 시스템**: 플레이어 탄환 자동 발사
- **다양한 적 패턴**: straight, aim, spread3, spread5 등
- **보스전**: 중간 보스 및 최종 보스 등장
- **난이도 선택**: Easy 모드와 Hard 모드 지원

### 업그레이드 시스템
- **기관포 강화**: 1발 → 2발 → 3발 패턴
- **연사력 강화**: 4단계 업그레이드
- **데미지 강화**: 4단계 업그레이드
- **체력 강화**: 4단계 업그레이드
- **보스 격파 후 상점**: 코인으로 업그레이드 구매

### 진행 시스템
- **스테이지 해금**: 클리어 시 다음 스테이지 자동 해금
- **진행도 저장**: localStorage를 통한 자동 저장
- **총 20개 스테이지**: Easy 10개, Hard 10개

### 기체 선택
- **TYPE-A: Striker** - 표준형 (속도: 200, 체력: 3)
- **TYPE-B: Interceptor** - 고속형 (속도: 260, 체력: 2)

## 📁 프로젝트 구조
```
project-destroyer/
├── index.html (intro.html로 리다이렉트)
├── intro.html              # 인트로 화면
├── main.html               # 메인 메뉴
├── hangar.html             # 기체 선택
├── select_stage.html       # 난이도 선택
├── stage_list_easy.html    # Easy 스테이지 목록
├── stage_list_hard.html    # Hard 스테이지 목록
├── game.html               # 게임 플레이 화면
│
├── assets/
│   ├── css/
│   │   ├── base.css           # 공통 기본 스타일
│   │   ├── intro.css          # 인트로 스타일
│   │   ├── main.css           # 메인 메뉴 스타일
│   │   ├── main_layout.css    # 레이아웃 공통 스타일
│   │   ├── hangar.css         # 격납고 스타일
│   │   ├── stage_list.css     # 스테이지 목록 스타일
│   │   └── game.css           # 게임 화면 스타일
│   │
│   ├── js/
│   │   ├── script.js              # 인트로 스크립트
│   │   ├── hangar.js              # 기체 선택 로직
│   │   ├── stage_list_easy.js     # Easy 목록 생성
│   │   ├── stage_list_hard.js     # Hard 목록 생성
│   │   ├── game.js                # 핵심 게임 로직
│   │   ├── player_upgrade.js      # 업그레이드 시스템
│   │   ├── monster.js             # 몬스터 패턴
│   │   │
│   │   ├── events/
│   │   │   ├── shop_event.js      # 상점 이벤트
│   │   │   └── carrier_event.js   # 캐리어 이벤트 (미구현)
│   │   │
│   │   └── stages/
│   │       ├── stage_defs.js      # 스테이지 정의
│   │       └── stage_manager.js   # 스테이지 관리
│   │
│   ├── images/
│   │   ├── intro_image.png        # 인트로 배경
│   │   ├── main.jpg               # 메인 배경
│   │   ├── moring.jpg             # Easy 모드 배경
│   │   ├── night.png              # Hard 모드 배경
│   │   ├── carrier1.png           # 캐리어 이미지
│   │   │
│   │   ├── player/
│   │   │   ├── player1_frame1.png # TYPE-A 기체
│   │   │   ├── player1_frame2.png
│   │   │   ├── player1_frame3.png
│   │   │   ├── player1_frame4.png
│   │   │   └── player2_frame1.png # TYPE-B 기체
│   │   │
│   │   ├── enemy/
│   │   │   ├── en1.png ~ en13.png # 일반 적 이미지
│   │   │   └── boss1.png ~ boss5.png # 보스 이미지
│   │   │
│   │   ├── bullets/
│   │   │   └── bullet1.png        # 플레이어 탄환
│   │   │
│   │   └── enemy_bullet/
│   │       └── enemy_bullet.png   # 적 탄환
│   │
│   └── audio/
│       ├── intro_music.mp3    # 인트로 음악
│       ├── hit.mp3            # 피격 효과음
│       └── game_over.mp3      # 게임 오버 사운드
```

## 🎯 게임 흐름
```
인트로 화면 (intro.html)
    ↓
메인 메뉴 (main.html)
    ↓
격납고 (hangar.html) - 기체 선택
    ↓
난이도 선택 (select_stage.html)
    ↓
스테이지 선택 (stage_list_easy/hard.html)
    ↓
게임 플레이 (game.html)
    ↓
보스 격파 → 상점 → 스테이지 클리어
```

## 🛠️ 기술 스택

- **HTML5 Canvas**: 게임 렌더링
- **Vanilla JavaScript**: 게임 로직
- **CSS3**: 스타일링 및 애니메이션
- **localStorage**: 진행도 저장

## 🎮 조작법

### 키보드 조작
- **방향키 모드**: ←↑↓→ 이동
- **WASD 모드**: W/A/S/D 이동
- **Shift**: 저속 이동

### 마우스 조작
- 마우스 커서를 따라 자동 이동

## 📊 게임 시스템

### 체력 시스템
- 기본 체력: 선택한 기체에 따라 다름
- 업그레이드로 최대 6까지 증가 가능
- 피격 시 1.5초 무적 시간

### 코인 시스템
- 적 격파: 1 코인
- 보스 격파: 10 코인
- 상점에서 업그레이드 구매에 사용

### 스테이지 클리어 조건
- 모든 웨이브 처리 완료
- 모든 적 제거
- 보스 격파 (보스 스테이지의 경우)

## 🎨 업그레이드 정보

### 상점 아이템
1. **기관포 2줄** - 평행 2발 사격
2. **기관포 3줄** - 평행 3발 사격 (1번 구매 후)
3. **미사일 해금** - 미사일 기능 활성화
4. **미사일 2발** - 미사일 2발 발사 (3번 구매 후)
5. **연사력 강화** - 발사 속도 증가 (4단계)
6. **데미지 강화** - 데미지 증가 및 탄환 스킨 변경 (4단계)
7. **체력 강화** - 최대 체력 증가 (4단계)

### 연사력 단계
- Lv 0: 333ms
- Lv 1: 120ms
- Lv 2: 110ms
- Lv 3: 95ms
- Lv 4: 84ms

### 데미지 단계
- Lv 0: 2 (bulletB1)
- Lv 1: 4 (bulletR1)
- Lv 2: 8 (bulletG1)
- Lv 3: 16 (bulletW1)

## 🐛 알려진 이슈

1. **carrier_event.js**: 캐리어 이벤트 미니게임 미구현
2. **game.js 인코딩**: 일부 한글 주석 깨짐 현상
3. **이미지 로딩**: 일부 이미지 경로 확인 필요

## 📝 개발 계획

- [ ] 캐리어 이벤트 미니게임 구현
- [ ] 추가 기체 타입
- [ ] 더 많은 보스 패턴
- [ ] 사운드 트랙 추가
- [ ] 모바일 터치 최적화
- [ ] 랭킹 시스템

## 🎯 설치 및 실행

1. 프로젝트 클론 또는 다운로드
2. 웹 서버로 실행 (로컬 파일로는 일부 기능 제한)
3. `intro.html` 또는 `index.html` 열기
```bash
# 간단한 로컬 서버 실행 예시
python -m http.server 8000
# 또는
npx serve
```

4. 브라우저에서 `http://localhost:8000` 접속

