# C언어를 이용한 게임 프로그래밍 기본
이 문서는 C언어를 사용하여 콘솔 기반 게임을 제작하는 데 필요한 기본적인 프로그래밍 기술들을 정리합니다.

1. 개발 환경
IDE: Dev-C++ 5.11


2. 콘솔 제어
2.1. 커서 위치 제어 (gotoxy)
콘솔 화면의 특정 위치로 커서를 이동시키는 기능입니다. windows.h 헤더 파일이 필요합니다.

구분

Visual C++

Turbo C/C++

커서 위치 제어 함수

없음 (직접 구현 필요)
```
#include <conio.h> <br> gotoxy(int x, int y);

gotoxy 함수 구현 (Windows API 사용)

#include <windows.h>

// 지정된 위치(x, y)로 커서를 이동시키는 함수
void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1}; // COORD는 x, y 좌표를 저장하는 구조체
    // 콘솔 출력 핸들을 가져와 커서 위치를 설정
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```
사용 예제: Hello 출력
```
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y); // 함수 원형 선언

int main(void) {
    gotoxy(2, 4);
    printf("Hello");
    
    gotoxy(40, 20);
    printf("Hello");
    
    return 0;
}

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```
2.2. 화면 지우기
콘솔 화면의 모든 내용을 지웁니다.

구분

Visual C++

Turbo C/C++

화면 지우기 함수
```
#include <stdlib.h> <br> system("cls");

#include <conio.h> <br> clrscr();

사용 예제: 구구단 출력기

#include <stdio.h>
#include <stdlib.h> // system 함수
#include <conio.h>  // getch 함수

int main(void) {
    for (int j = 1; j <= 9; j++) {
        system("cls"); // 화면을 깨끗하게 지움
        for (int i = 1; i <= 9; i++) {
            printf("%d * %d = %d\n", j, i, j * i);
        }
        printf("\n아무 키나 누르면 다음 단으로 넘어갑니다.");
        getch(); // 사용자가 아무 키나 누를 때까지 대기
    }
    return 0;
}
```
3. 키보드 입력 처리
3.1. ASCII 코드와 스캔 코드
아스키 코드(ASCII Code): 'a', '1', '!' 등 문자에 부여된 고유한 숫자 값입니다.

스캔 코드(Scan Code): 키보드의 각 키(하드웨어)에 할당된 고유한 코드 값입니다. 화살표 키, F1~F12 키, Home, End 키 등 아스키코드로 표현할 수 없는 확장 키를 입력받을 때 사용됩니다.

getch() 함수로 확장 키를 입력받으면, 첫 번째 값으로 0 또는 224(0xe0)가 반환되고, 두 번째 값으로 실제 스캔 코드가 반환됩니다.

키 코드 확인 예제
```
#include <stdio.h>
#include <conio.h>

int main(void) {
    int key;
    printf("키를 누르세요 (종료: ESC)...\n");
    while(1) {
        key = getch();
        if (key == 27) break; // ESC 키를 누르면 종료

        if (key == 0 || key == 0xe0) { // 확장 키인 경우
            printf("확장 키 입력됨. ");
            key = getch(); // 실제 스캔 코드 읽기
            printf("스캔 코드 = %d\n", key);
        } else { // 아스키 키인 경우
            printf("아스키 코드 = %d, 문자 = %c\n", key, key);
        }
    }
    return 0;
}
```
3.2. 화살표 키를 이용한 이동
화살표 키

스캔 코드 (10진수)

x 변화

y 변화

위(↑)

72

y--

없음

아래(↓)

80

y++

없음

왼쪽(←)

75

x--

없음

오른쪽(→)

77

x++

없음

화살표 키로 'A' 문자 이동시키기
```
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X_MAX 79
#define Y_MAX 24

void gotoxy(int x, int y);
void move_arrow_key(char key, int *x, int *y);

int main(void) {
    char key;
    int x = 10, y = 5;

    do {
        system("cls");
        gotoxy(x, y);
        printf("A");
        printf("\n\n(이동: 화살표 키, 종료: ESC)");

        key = getch();
        if (key == 0 || key == 0xe0) {
            key = getch(); // 실제 스캔 코드 읽기
            move_arrow_key(key, &x, &y);
        }
    } while (key != 27); // ESC 키

    return 0;
}

void move_arrow_key(char key, int *x, int *y) {
    switch (key) {
        case 72: // 위
            *y -= 1;
            if (*y < 1) *y = 1;
            break;
        case 80: // 아래
            *y += 1;
            if (*y > Y_MAX) *y = Y_MAX;
            break;
        case 75: // 왼쪽
            *x -= 1;
            if (*x < 1) *x = 1;
            break;
        case 77: // 오른쪽
            *x += 1;
            if (*x > X_MAX) *x = X_MAX;
            break;
    }
}

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```
4. 도형 그리기
확장 완성형 코드를 사용하여 텍스트 모드에서 사각형과 같은 도형을 그립니다.

정사각형 그리기 예제
```
#include <stdio.h>

void draw_square(int size);

int main(void) {
    int n;
    printf("정사각형 그리기\n");
    printf("정사각형의 길이(최대 37)를 입력하고 Enter > ");
    scanf("%d", &n);
    draw_square(n);
    return 0;
}

void draw_square(int size) {
    int i, j;
    // ┌ ─ ┐ │ └ ┘ 문자에 해당하는 코드
    unsigned char corner_tl = 218; // ┌
    unsigned char corner_tr = 191; // ┐
    unsigned char corner_bl = 192; // └
    unsigned char corner_br = 217; // ┘
    unsigned char line_h = 196;    // ─
    unsigned char line_v = 179;    // │

    // 윗변
    printf("%c", corner_tl);
    for (i = 0; i < size; i++) printf("%c", line_h);
    printf("%c\n", corner_tr);

    // 중단
    for (i = 0; i < size; i++) {
        printf("%c", line_v);
        for (j = 0; j < size; j++) printf(" ");
        printf("%c\n", line_v);
    }

    // 아랫변
    printf("%c", corner_bl);
    for (i = 0; i < size; i++) printf("%c", line_h);
    printf("%c\n", corner_br);
}
```
5. 난수 생성
stdlib.h와 time.h를 사용하여 난수를 생성합니다. srand(time(NULL))로 시드값을 초기화하여 매번 다른 난수를 얻을 수 있습니다.

범위 내의 난수 생성
% 연산자를 사용하여 특정 범위의 난수를 생성합니다.

생성 범위

연산식

설명

1 ~ 6

rand() % 6 + 1

0~5 사이의 나머지에 1을 더함

1 ~ 45

rand() % 45 + 1

0~44 사이의 나머지에 1을 더함

0 ~ 99

rand() % 100

0~99 사이의 나머지를 구함

중복 없는 난수 생성 (로또 번호) 
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, j, lotto[6];
    srand(time(NULL)); // 현재 시간을 시드로 난수 생성기 초기화

    for (i = 0; i < 6; i++) {
        lotto[i] = rand() % 45 + 1; // 1 ~ 45 사이의 난수 생성
        // 중복 검사
        for (j = 0; j < i; j++) {
            if (lotto[i] == lotto[j]) {
                i--; // 중복이면 현재 인덱스 다시 추첨
                break;
            }
        }
    }

    printf("생성된 로또 번호: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", lotto[i]);
    }
    printf("\n");
    
    return 0;
}
```
6. 가변 인수
printf처럼 인수의 개수가 정해지지 않은 함수를 만들 때 사용합니다. stdarg.h 헤더 파일이 필요합니다.

va_list: 가변 인수를 저장할 포인터 변수 타입

va_start(ap, last_arg): 가변 인수 처리 시작

va_arg(ap, type): 인수를 하나씩 읽어옴

va_end(ap): 가변 인수 처리 종료

가변 인수를 사용한 합계 함수
```
#include <stdio.h>
#include <stdarg.h>

// count개의 double형 인수를 더하는 함수
double sum(int count, ...);

int main(void) {
    printf("합계(2개) = %f\n", sum(2, 10.5, 20.23));
    printf("합계(5개) = %f\n", sum(5, 1.0, 2.0, 3.0, 4.0, 5.0));
    return 0;
}

double sum(int count, ...) {
    double total = 0.0;
    va_list ap; // 가변 인수 목록 포인터

    va_start(ap, count); // 가변 인수 처리 시작 (count 다음부터)
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, double); // double 타입의 인수를 읽어옴
    }
    va_end(ap); // 가변 인수 처리 종료

    return total;
}
```
