
[C 프로젝트 발표.pptx](https://github.com/user-attachments/files/22961970/C.pptx)



# 디지털 시계 & 팩맨 게임

Windows 콘솔 기반의 디지털 시계 프로그램으로, 알람 기능과 팩맨 미니게임이 통합되어 있습니다.

## 목차
- [주요 기능](#주요-기능)
- [필요 파일](#필요-파일)
- [코드 구조 분석](#코드-구조-분석)
- [사용 방법](#사용-방법)

---

## 주요 기능

### 1. 디지털 시계
- 시, 분, 초를 큰 ASCII 아트 숫자로 표시
- 현재 날짜와 요일 표시
- 깜빡이는 애니메이션 캐릭터

### 2. 알람 시스템
- 최대 10개의 알람 설정 가능
- 알람 시간에 비프음 알림
- 알람 추가/삭제 기능

### 3. 팩맨 미니게임
- 외부 맵 파일(`level1.txt`)을 불러와서 게임 진행
- 2개의 AI 유령이 플레이어 추적
- 모든 점을 먹으면 승리

### 4. 인트로 화면
- GDI+를 사용한 이미지 표시
- BMP 이미지 파일(`in2.bmp`) 로드

---

## 필요 파일

프로그램 실행을 위해 다음 파일들이 실행 파일과 같은 디렉토리에 있어야 합니다:

1. **watch.exe** - 컴파일된 실행 파일
2. **level1.txt** - 팩맨 게임 맵 데이터 (38x18 크기)
3. **in2.bmp** - 인트로 화면 이미지

---

## 코드 구조 분석

### 1. 헤더 및 전역 설정

```cpp
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "gdi32.lib")

using namespace Gdiplus;
```

**설명**: GDI+ 라이브러리를 사용하여 BMP 이미지를 로드하고 표시합니다. 인트로 화면에서 이미지를 렌더링하는 데 사용됩니다.

---

### 2. 색상 상수 정의

```cpp
#define COLOR_DEFAULT        15 // 기본 흰색
#define COLOR_FRAME_BORDER   15 // 프레임 테두리
#define COLOR_CLOCK_DIGIT    10 // 시계 숫자 (밝은 녹색)
#define COLOR_CLOCK_COLON    10 // 시계 콜론
#define COLOR_ANIMATION      14 // 애니메이션 캐릭터 (밝은 노란색)
#define COLOR_PACMAN_WALL    9  // 팩맨 벽 (밝은 파란색)
#define COLOR_PACMAN_GHOST1  12 // 팩맨 유령1 (밝은 빨간색)
#define COLOR_PACMAN_GHOST2  10 // 팩맨 유령2 (밝은 녹색)
#define COLOR_PACMAN         14 // 팩맨 캐릭터
#define COLOR_ERROR          12 // 오류 메시지 (밝은 빨간색)
#define COLOR_SUCCESS        10 // 성공 메시지 (밝은 녹색)
```

**설명**: Windows 콘솔의 색상 코드를 정의합니다. 각 UI 요소마다 다른 색상을 적용하여 시각적으로 구분됩니다.

---

### 3. 데이터 구조

```cpp
struct Alarm {
    int hour;
    int minute;
};

struct Alarm alarms[MAX_ALARMS];
int alarm_count = 0;
```

**설명**: 알람 데이터를 저장하는 구조체입니다. 시와 분 정보를 가지며, 최대 10개까지 저장할 수 있습니다.

---

### 4. 디지털 숫자 데이터

```cpp
int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
// ... 3~9까지 동일한 패턴
```

**설명**: 각 숫자(0-9)를 5x4 그리드로 표현한 비트맵 데이터입니다. 1은 블록(█)으로, 0은 공백으로 렌더링됩니다.

---

### 5. 맵 파일 로드 함수

```cpp
bool load_map_from_file(const char* filename) {
    std::ifstream mapFile(filename);
    if (!mapFile.is_open()) {
        return false;
    }

    std::string line;
    int currentRow = 0;
    while (currentRow < MAP_HEIGHT && std::getline(mapFile, line)) {
        strncpy(pacman_map[currentRow], line.c_str(), MAP_WIDTH);
        pacman_map[currentRow][MAP_WIDTH] = '\0';
        currentRow++;
    }

    mapFile.close();

    if (currentRow != MAP_HEIGHT) {
        return false;
    }

    return true;
}
```

**설명**: 
- `level1.txt` 파일을 한 줄씩 읽어서 `pacman_map` 배열에 저장합니다.
- 파일의 줄 수가 `MAP_HEIGHT`(18줄)와 일치하는지 검증합니다.
- 파일을 열 수 없거나 크기가 맞지 않으면 `false`를 반환합니다.

---

### 6. 콘솔 유틸리티 함수

```cpp
void gotoxy(int x, int y) {
    COORD pos = { (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_console_cursor_visibility(int visible) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void set_text_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
```

**설명**:
- `gotoxy`: 콘솔 커서를 특정 좌표로 이동시킵니다.
- `set_console_cursor_visibility`: 커서의 깜빡임을 켜거나 끕니다.
- `set_text_color`: 텍스트 색상을 변경합니다.

---

### 7. 프레임 그리기

```cpp
void draw_frame() {
    set_text_color(COLOR_FRAME_BORDER);
    for (int x = 1; x <= 80; x++) {
        gotoxy(x, 1); printf("═");
        gotoxy(x, 11); printf("═");
    }
    for (int y = 2; y <= 10; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 1); printf("╔");
    gotoxy(80, 1); printf("╗");
    gotoxy(1, 11); printf("╚");
    gotoxy(80, 11); printf("╝");
    set_text_color(COLOR_DEFAULT);
}
```

**설명**: Box Drawing 문자를 사용하여 시계 영역 주변에 테두리를 그립니다. 80x10 크기의 박스를 생성합니다.

---

### 8. 시간 변환 함수

```cpp
long time_to_number(void) {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}
```

**설명**: 현재 시간을 HHMMSS 형태의 6자리 숫자로 변환합니다. 예: 14시 35분 22초 → 143522

---

### 9. 디지털 숫자 출력

```cpp
void digit_print(int dim[], int row) {
    set_text_color(COLOR_CLOCK_DIGIT);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        printf(dim[i] ? "█" : " ");
    }
    printf("   ");
    set_text_color(COLOR_DEFAULT);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }
    int start_x = 5, start_y = 3, spacing = 8;
    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                // ... 2~9까지 동일
            }
            if (i == 1 || i == 3) printf("   ");
        }
    }
    // 콜론(:) 그리기
    set_text_color(COLOR_CLOCK_COLON);
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
    set_text_color(COLOR_DEFAULT);
}
```

**설명**:
- 시간 숫자를 6자리로 분해하여 각 자리를 큰 ASCII 아트로 표시합니다.
- 시와 분, 분과 초 사이에 콜론(■)을 표시합니다.

---

### 10. 날짜 및 요일 표시

```cpp
void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    const char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", 
                              "목요일", "금요일", "토요일"};
    gotoxy(5, 9);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", 
           d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}
```

**설명**: 현재 날짜와 요일을 한글로 표시합니다. `tm_wday`(0-6)를 사용하여 요일 배열에서 해당 요일을 가져옵니다.

---

### 11. 알람 목록 표시

```cpp
void print_alarm_list() {
    clear_alarm_list_area();
    gotoxy(5, 13);
    printf("╔════════════════════════════════════╗");
    if (alarm_count == 0) {
        gotoxy(5, 14);
        printf("║ 설정된 알람이 없습니다.            ║");
    } else {
        for (int i = 0; i < alarm_count; i++) {
            gotoxy(5, 14 + i);
            printf("║ 알람 %d: %02d:%02d  [삭제:%d]            ║", 
                   i + 1, alarms[i].hour, alarms[i].minute, i + 1);
        }
    }
    gotoxy(5, 14 + (alarm_count == 0 ? 1 : alarm_count));
    printf("╚════════════════════════════════════╝");
}
```

**설명**: 
- 설정된 알람 목록을 박스 형태로 표시합니다.
- 각 알람마다 번호와 시간, 삭제 키를 안내합니다.

---

### 12. 알람 정렬 및 삭제

```cpp
void sort_alarms() {
    for (int i = 0; i < alarm_count - 1; i++) {
        for (int j = i + 1; j < alarm_count; j++) {
            if (alarms[i].hour > alarms[j].hour || 
                (alarms[i].hour == alarms[j].hour && alarms[i].minute > alarms[j].minute)) {
                struct Alarm temp = alarms[i];
                alarms[i] = alarms[j];
                alarms[j] = temp;
            }
        }
    }
}

void delete_alarm(int index) {
    if (index < 0 || index >= alarm_count) return;
    for (int i = index; i < alarm_count - 1; i++) {
        alarms[i] = alarms[i + 1];
    }
    alarm_count--;
}
```

**설명**:
- `sort_alarms`: 버블 정렬을 사용하여 알람을 시간 순서대로 정렬합니다.
- `delete_alarm`: 특정 인덱스의 알람을 삭제하고 배열을 재정렬합니다.

---

### 13. 알람 확인 및 알림

```cpp
void check_alarm(int hour, int minute) {
    static int triggered[MAX_ALARMS] = {0};
    for (int i = 0; i < alarm_count; i++) {
        if (hour == alarms[i].hour && minute == alarms[i].minute && !triggered[i]) {
            gotoxy(40, 10);
            printf("🔔 알람 %d 시간입니다! 🔔", i + 1);
            for (int j = 0; j < 3; j++) {
                Beep(1000, 300);
                Sleep(200);
            }
            triggered[i] = 1;
        } else if (hour != alarms[i].hour || minute != alarms[i].minute) {
            triggered[i] = 0;
            gotoxy(40, 10);
            printf("                             ");
        }
    }
}
```

**설명**:
- 현재 시간과 알람 시간을 비교합니다.
- 알람이 울리면 비프음을 3번 반복하고 화면에 메시지를 표시합니다.
- `triggered` 배열로 같은 알람이 중복으로 울리지 않도록 관리합니다.

---

### 14. 애니메이션 캐릭터

```cpp
void draw_animation_frame(int frame) {
    int start_x = 55, start_y = 4;
    const char* eyes[] = {"+", ">", "+", "<"};
    const char* current_eyes = eyes[frame % 4];
    set_text_color(COLOR_ANIMATION);
    gotoxy(start_x, start_y + 0); printf("  ████  ");
    gotoxy(start_x, start_y + 1); printf("██    ██");
    gotoxy(start_x, start_y + 2); printf("█ %s  %s █", current_eyes, current_eyes);
    gotoxy(start_x, start_y + 3); printf("██    ██");
    gotoxy(start_x, start_y + 4); printf("  ████  ");
    set_text_color(COLOR_DEFAULT);
}
```

**설명**: 
- 시계 오른쪽에 작은 캐릭터를 표시합니다.
- 눈 모양이 `+` → `>` → `+` → `<` 순서로 변하여 깜빡이는 효과를 만듭니다.

---

### 15. 팩맨 게임 로직

```cpp
void play_pacman_game() {
    system("cls");
    set_console_cursor_visibility(0);

    int player_x = 1, player_y = 1;
    int score = 0, total_dots = 0;
    int ghost1_x = MAP_WIDTH / 2 - 2, ghost1_y = MAP_HEIGHT / 2 - 1;
    int ghost2_x = MAP_WIDTH / 2 + 2, ghost2_y = MAP_HEIGHT / 2 - 1;
    int ghost_move_counter = 0;
    char current_map[MAP_HEIGHT][MAP_WIDTH + 1];

    // 맵 초기화 및 점 개수 계산
    for(int y=0; y<MAP_HEIGHT; ++y) {
        strcpy(current_map[y], pacman_map[y]);
        for(int x=0; x<MAP_WIDTH; ++x) {
            if(current_map[y][x] == '.') total_dots++;
        }
    }

    // ... 게임 루프 ...
}
```

**설명**:
- 플레이어는 (1, 1)에서 시작합니다.
- 유령 2개는 맵 중앙 근처에 배치됩니다.
- 맵에 있는 모든 점(`.`)의 개수를 세어 총 점수를 계산합니다.

---

### 16. 게임 입력 처리

```cpp
if (kbhit()) {
    int key = getch();
    if (key == 224) {
        key = getch();
        switch (key) {
            case 75: if (current_map[player_y][player_x - 1] != '#') player_x--; break; // ←
            case 77: if (current_map[player_y][player_x + 1] != '#') player_x++; break; // →
            case 72: if (current_map[player_y - 1][player_x] != '#') player_y--; break; // ↑
            case 80: if (current_map[player_y + 1][player_x] != '#') player_y++; break; // ↓
        }
    } else if (key == 'q' || key == 'Q') {
        break;
    }
}
```

**설명**:
- 방향키 입력을 감지합니다(224는 확장 키 코드).
- 이동하려는 위치에 벽(`#`)이 없는 경우에만 이동합니다.
- `Q` 키를 누르면 게임을 종료합니다.

---

### 17. AI 유령 이동

```cpp
ghost_move_counter++;
if (ghost_move_counter % 2 == 0) {
    // 유령 1: X축 우선, Y축 보조
    if (ghost1_x < player_x && current_map[ghost1_y][ghost1_x + 1] != '#') ghost1_x++;
    else if (ghost1_x > player_x && current_map[ghost1_y][ghost1_x - 1] != '#') ghost1_x--;
    else if (ghost1_y < player_y && current_map[ghost1_y + 1][ghost1_x] != '#') ghost1_y++;
    else if (ghost1_y > player_y && current_map[ghost1_y - 1][ghost1_x] != '#') ghost1_y--;

    // 유령 2: Y축 우선, X축 보조
    if (ghost2_y < player_y && current_map[ghost2_y + 1][ghost2_x] != '#') ghost2_y++;
    else if (ghost2_y > player_y && current_map[ghost2_y - 1][ghost2_x] != '#') ghost2_y--;
    else if (ghost2_x < player_x && current_map[ghost2_y][ghost2_x + 1] != '#') ghost2_x++;
    else if (ghost2_x > player_x && current_map[ghost2_y][ghost2_x - 1] != '#') ghost2_x--;
}
```

**설명**:
- 유령은 2프레임마다 한 번씩 움직입니다(플레이어보다 느림).
- 유령 1은 X축(좌우)을 우선으로 플레이어를 추적합니다.
- 유령 2는 Y축(상하)을 우선으로 플레이어를 추적합니다.
- 서로 다른 패턴으로 움직여 게임에 변화를 줍니다.

---

### 18. 충돌 감지 및 게임 종료

```cpp
// 점 먹기
if (current_map[player_y][player_x] == '.') {
    current_map[player_y][player_x] = ' ';
    score++;
    Beep(600, 50);
    gotoxy(7, MAP_HEIGHT + 1);
    set_text_color(COLOR_DEFAULT);
    printf("%d", score);
}

// 유령과 충돌 체크
if ((player_x == ghost1_x && player_y == ghost1_y) || 
    (player_x == ghost2_x && player_y == ghost2_y)) {
    gotoxy((MAP_WIDTH / 2) - 5, MAP_HEIGHT / 2);
    set_text_color(COLOR_ERROR);
    printf("GAME OVER");
    Beep(150, 500);
    Sleep(2000);
    break;
}

// 승리 조건
if (score >= total_dots) {
    gotoxy((MAP_WIDTH / 2) - 10, MAP_HEIGHT / 2);
    set_text_color(COLOR_SUCCESS);
    printf("YOU WIN! CONGRATULATIONS!");
    Beep(523, 200); Beep(659, 200); Beep(783, 200);
    Sleep(3000);
    break;
}
```

**설명**:
- 플레이어가 점 위를 지나가면 점수가 증가하고 짧은 비프음이 울립니다.
- 유령과 같은 위치에 있으면 게임 오버됩니다.
- 모든 점을 먹으면 승리 메시지와 함께 음악이 재생됩니다.

---

### 19. 인트로 화면 (GDI+)

```cpp
void show_intro_with_image() {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    g_pIntroImage = new Image(L"in2.bmp");
    
    if (g_pIntroImage->GetLastStatus() != Ok) {
        // 오류 처리
        set_text_color(COLOR_ERROR);
        printf("\n=== 이미지 로드 실패 ===\n\n");
        // ... 오류 메시지 ...
        return;
    }

    // 윈도우 생성 및 이미지 표시
    // ...
}
```

**설명**:
- GDI+를 초기화하고 BMP 이미지를 로드합니다.
- 이미지 로드에 실패하면 자세한 오류 정보를 표시합니다.
- 성공하면 800x600 윈도우를 생성하여 이미지를 표시합니다.

---

### 20. 윈도우 프로시저

```cpp
LRESULT CALLBACK IntroWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            if (g_pIntroImage && g_pIntroImage->GetLastStatus() == Ok) {
                Graphics graphics(hdc);
                RECT rect;
                GetClientRect(hwnd, &rect);
                graphics.DrawImage(g_pIntroImage, 0, 0, rect.right, rect.bottom);
            }
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_KEYDOWN:
        case WM_LBUTTONDOWN:
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

**설명**:
- `WM_PAINT`: 윈도우가 다시 그려져야 할 때 이미지를 렌더링합니다.
- `WM_KEYDOWN`, `WM_LBUTTONDOWN`: 키를 누르거나 마우스를 클릭하면 창을 닫습니다.
- `WM_CLOSE`: 창 닫기 버튼을 누르면 윈도우를 파괴합니다.

---

### 21. 메인 루프

```cpp
int main(void) {
    system("chcp 65001 > nul");  // UTF-8 인코딩 설정
    system("title 디지털 시계 & 팩맨");
    system("mode con: cols=82 lines=30");

    // 맵 파일 로드
    if (!load_map_from_file("level1.txt")) {
        // 오류 처리
        return 1;
    }

    show_intro_with_image();  // 인트로 화면

    int animation_frame = 0;
    long last_time_number = -1;
    bool needs_redraw = true;

    set_console_cursor_visibility(0);
    
    while (1) {
        if (needs_redraw) {
            redraw_main_screen();
            last_time_number = -1;
            needs_redraw = false;
        }

        long time_number = time_to_number();

        if (time_number != last_time_number) {
            print_time_digits(time_number);
            draw_animation_frame(animation_frame++);

            if (time_number / 10000 != last_time_number / 10000 || last_time_number == -1) {
                print_date_and_weekday();
            }
            last_time_number = time_number;

            time_t current = time(NULL);
            struct tm* d = localtime(&current);
            check_alarm(d->tm_hour, d->tm_min);
        }

        // 키보드 입력 처리
        if (kbhit()) {
            char ch = getch();
            if (ch == 'd' || ch == 'D') {
                handle_alarm_deletion();
                needs_redraw = true;
            } else if (ch == 'g' || ch == 'G') {
                play_pacman_game();
                needs_redraw = true;
            } else if (ch == 'p' || ch == 'P') {
                handle_alarm_addition();
                needs_redraw = true;
            } else {
                break;
            }
        }
        
        Sleep(100);  // CPU 사용률 감소
    }

    system("cls");
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    return 0;
}
```

**설명**:
- 콘솔을 UTF-8로 설정하고 창 크기를 조정합니다.
- 맵 파일과 인트로 이미지를 로드합니다.
- 메인 루프에서 시간을 표시하고 사용자 입력을 처리합니다.
- `p`: 알람 추가, `d`: 알람 삭제, `g`: 팩맨 게임, 기타: 종료

---


## 사용 방법

1. **프로그램 시작**
   - `watch.exe` 실행
   - 인트로 이미지가 표시됩니다 (아무 키나 눌러 건너뛰기)
   - 디지털 시계 화면으로 전환됩니다

2. **알람 설정**
   - `P` 키를 누릅니다
   - 시(0-23)와 분(0-59)을 입력합니다
   - 여러 개의 알람을 추가할 수 있습니다
   - 시에 `-1`을 입력하면 설정을 종료합니다

3. **알람 삭제**
   - `D` 키를 누릅니다
   - 삭제할 알람 번호를 입력합니다
   - `0`을 입력하면 취소됩니다

4. **팩맨 게임**
   - `G` 키를 누릅니다
   - 방향키(←↑↓→)로 이동합니다
   - 모든 점(`.`)을 먹으면 승리합니다
   - 유령(`M`, `W`)에 닿으면 게임 오버됩니다
   - `Q` 키로 게임을 종료하고 시계로 돌아갑니다

5. **프로그램 종료**
   - 시계 화면에서 `P`, `D`, `G` 외의 키를 누르면 종료됩니다

---

## 맵 파일 형식 (level1.txt)

```
#####################################
#...................................#
#.#####.###..####.###.#########.###.#
#.....#.#.......#.#.#.#.......#.#...#
#.#...#.#.#####.#.#.#.#.#####.#.#...#
#.#...#.#.#...#.#...#.#.#...#.#.#...#
#.#...#.#.#...#.#.#.#.#.#...#.#.#...#
#.#####.#####.###.###.#####.#.#####.
#...................................#
#.#####.###.#########.###.#########
#.#...#.#.#.#.......#.#.#.#.........#
#.#...#.#.#.#.#####.#.#.#.#.#######.#
#.#...#...#.#.#...#.#...#.#.#.....#.#
#.#...#####.#.#...#.#.###.#.#.###.#.#
#.#.....#...#.....#.#...#...#...#...#
#.##.####.#########.###.#####.###.#
#...................................#
#####################################
```

**구조**:
- 크기: 38(가로) x 18(세로)
- `#`: 벽 (통과 불가)
- `.`: 점 (먹을 수 있는 아이템)
- 공백: 이동 가능한 빈 공간

**맵 제작 팁**:
- 파일은 반드시 18줄이어야 합니다
- 각 줄은 정확히 38글자여야 합니다
- 플레이어 시작 위치 (1, 1)에 벽이 없어야 합니다
- 유령 시작 위치 근처에 충분한 공간이 필요합니다

---

## 기술적 세부사항

### 시간 업데이트 최적화
```cpp
long time_number = time_to_number();

if (time_number != last_time_number) {
    print_time_digits(time_number);
    // ...
    last_time_number = time_number;
}
```
- 초가 바뀔 때만 화면을 업데이트하여 CPU 사용률을 줄입니다
- 불필요한 깜빡임을 방지합니다

### 날짜 업데이트 최적화
```cpp
if (time_number / 10000 != last_time_number / 10000 || last_time_number == -1) {
    print_date_and_weekday();
}
```
- 시간이 바뀔 때만 날짜를 업데이트합니다
- 시간 대비 날짜 업데이트 빈도를 크게 줄입니다

### 화면 갱신 전략
```cpp
bool needs_redraw = true;

if (needs_redraw) {
    redraw_main_screen();
    last_time_number = -1;
    needs_redraw = false;
}
```
- 게임이나 알람 설정 화면에서 돌아올 때만 전체 화면을 다시 그립니다
- 일반적인 시간 업데이트는 필요한 부분만 갱신합니다

### 유령 이동 속도 제어
```cpp
ghost_move_counter++;
if (ghost_move_counter % 2 == 0) {
    // 유령 이동 로직
}
```
- 카운터를 사용하여 유령을 플레이어보다 느리게 이동시킵니다
- 게임 난이도를 적절하게 유지합니다

---

## 색상 코드 참조

Windows 콘솔 색상 코드:

| 코드 | 색상 |
|------|------|
| 0 | 검은색 |
| 1 | 파란색 |
| 2 | 녹색 |
| 3 | 청록색 |
| 4 | 빨간색 |
| 5 | 자홍색 |
| 6 | 노란색 |
| 7 | 흰색 |
| 8 | 회색 |
| 9 | 밝은 파란색 |
| 10 | 밝은 녹색 |
| 11 | 밝은 청록색 |
| 12 | 밝은 빨간색 |
| 13 | 밝은 자홍색 |
| 14 | 밝은 노란색 |
| 15 | 밝은 흰색 |

---

## 문제 해결

### 이미지 파일을 찾을 수 없습니다
**증상**: "이미지 로드 실패" 오류 메시지
**해결 방법**:
- `in2.bmp` 파일이 실행 파일과 같은 폴더에 있는지 확인
- 파일 이름이 정확한지 확인 (대소문자 구분)
- BMP 형식이 올바른지 확인

### 맵 파일을 찾을 수 없습니다
**증상**: "level1.txt 파일을 열 수 없습니다" 오류
**해결 방법**:
- `level1.txt` 파일이 실행 파일과 같은 폴더에 있는지 확인
- 파일이 정확히 18줄, 각 줄이 38글자인지 확인
- UTF-8 인코딩으로 저장되었는지 확인

### 한글이 깨져 보입니다
**증상**: 날짜, 요일, 메시지가 깨짐
**해결 방법**:
- 소스 코드를 UTF-8 인코딩으로 저장
- Windows 콘솔 설정에서 글꼴을 "굴림체" 또는 "맑은 고딕"으로 변경
- `chcp 65001` 명령이 정상 실행되는지 확인

### 알람이 울리지 않습니다
**증상**: 설정한 시간에 알람이 작동하지 않음
**해결 방법**:
- 24시간 형식으로 올바르게 입력했는지 확인 (예: 오후 2시 = 14시)
- 프로그램이 계속 실행 중인지 확인
- 시스템 볼륨이 음소거되지 않았는지 확인

### 게임이 너무 빠르거나 느립니다
**해결 방법**:
- `Sleep(80)` 값을 조정하여 게임 속도 변경 (값이 클수록 느려짐)
- 유령 이동 속도는 `ghost_move_counter % 2` 부분을 수정 (2 → 3으로 변경하면 더 느려짐)

---

## 커스터마이징 가이드

### 시계 색상 변경
```cpp
#define COLOR_CLOCK_DIGIT    10 // 현재: 밝은 녹색
// 다른 색상으로 변경: 예) 14 (노란색), 12 (빨간색)
```

### 알람 최대 개수 변경
```cpp
#define MAX_ALARMS 10  // 원하는 숫자로 변경
```

### 게임 난이도 조정
```cpp
// 유령 속도 변경 (숫자가 클수록 느림)
if (ghost_move_counter % 2 == 0) {  // 2 → 3 또는 4로 변경

// 게임 속도 변경
Sleep(80);  // 80 → 100 (느리게) 또는 50 (빠르게)
```

### 콘솔 창 크기 변경
```cpp
system("mode con: cols=82 lines=30");
// cols: 가로 크기, lines: 세로 크기
```

### 새로운 맵 추가
1. 새 텍스트 파일 생성 (예: `level2.txt`)
2. 38x18 크기로 맵 디자인
3. 코드에서 파일 이름 변경:
```cpp
if (!load_map_from_file("level2.txt")) {
```

---

## 프로젝트 구조

```
project/
│
├── watch.cpp           # 메인 소스 코드
├── watch.exe           # 컴파일된 실행 파일
├── level1.txt          # 팩맨 게임 맵 파일
├── in2.bmp             # 인트로 이미지 파일
└── README.md           # 이 파일
```

---

## 개발 환경

- **언어**: C++ (C++11 이상)
- **플랫폼**: Windows
- **필수 라이브러리**:
  - `windows.h` - Windows API
  - `gdiplus.h` - 이미지 처리
  - `conio.h` - 키보드 입력 (_getch, kbhit)
  - Standard C++ Libraries (iostream, fstream, string)

---

## 주요 함수 요약

| 함수 | 설명 |
|------|------|
| `load_map_from_file()` | 맵 파일을 읽어 배열에 저장 |
| `gotoxy()` | 콘솔 커서 위치 이동 |
| `set_text_color()` | 텍스트 색상 변경 |
| `draw_frame()` | 시계 테두리 그리기 |
| `time_to_number()` | 현재 시간을 숫자로 변환 |
| `print_time_digits()` | 큰 숫자로 시간 표시 |
| `print_alarm_list()` | 알람 목록 출력 |
| `check_alarm()` | 알람 시간 확인 및 알림 |
| `play_pacman_game()` | 팩맨 게임 실행 |
| `show_intro_with_image()` | GDI+로 인트로 이미지 표시 |

---

## 향후 개선 방향

- [ ] 여러 레벨의 팩맨 맵 추가
- [ ] 알람 설정을 파일로 저장/불러오기
- [ ] 스톱워치 기능 추가
- [ ] 타이머 기능 추가
- [ ] 배경음악 재생 기능
- [ ] 더 다양한 유령 AI 패턴
- [ ] 파워업 아이템 (유령 잡기)
- [ ] 점수 기록 저장 및 순위표
- [ ] 멀티 언어 지원
- [ ] 설정 메뉴 (색상, 소리 등)

---

## 라이선스

이 프로젝트는 교육 목적으로 제작되었습니다.

---

## 작성자

디지털 시계 & 팩맨 게임 프로젝트

---

## 버전 히스토리

### v1.0 (현재)
- 디지털 시계 기능
- 알람 설정/삭제 기능
- 팩맨 미니게임
- GDI+ 인트로 화면
- 외부 맵 파일 로드

---



---

**Happy Coding! 🎮⏰**
