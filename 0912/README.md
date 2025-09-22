
# 🎮 게임 프로그래밍 (C 언어 기초)

> 경성대학교 강의자료 기반 정리  

이 자료는 **C 언어를 이용한 게임 프로그래밍 기초**를 다룹니다.  
콘솔 기반 프로그램 작성부터 난수 생성, 메뉴 만들기, 도형 출력, 가변 인수 함수까지 실습 예제를 포함합니다.  

---

## 📌 학습 내용

- **개발 환경**: [Dev-C++ (Orwell)](https://sourceforge.net/projects/orwelldevcpp/)  
- **콘솔 제어**  
  - 커서 위치 제어 (`gotoxy`)  
  - 화면 지우기 (`system("cls")`)  
- **입력 처리**  
  - `getchar`, `getche`, `getch` 차이  
  - ASCII 코드 & 스캔 코드  
  - 화살표 키 입력 처리  
- **그래픽 표현**  
  - 텍스트 모드에서 정사각형/직사각형/격자 출력  
- **메뉴 시스템 구현**  
  - 메인 메뉴 및 서브 메뉴 제작  
- **난수 활용**  
  - 주사위, 로또 번호 생성  
  - 중복 없는 난수 및 정렬  
- **가변 인수 함수**  
  - `printf`, `scanf` 원리  
  - `va_list`, `va_start`, `va_arg`, `va_end`  

---

## 🖥️ 주요 예제 코드

### 1. 커서 제어 (`gotoxy`)
```c
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {
    gotoxy(2,4);
    printf("Hello");
    gotoxy(40, 20);
    printf("Hello");
    return 0;
}
```
### 2. 화살표 키로 문자 이동
```
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X_MAX 79
#define Y_MAX 24

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void move_arrow_key(char key, int *x, int *y, int x_b, int y_b) {
    switch(key) {
        case 72: (*y)--; if(*y<1) *y=1; break;      // ↑
        case 75: (*x)--; if(*x<1) *x=1; break;      // ←
        case 77: (*x)++; if(*x>x_b) *x=x_b; break;  // →
        case 80: (*y)++; if(*y>y_b) *y=y_b; break;  // ↓
    }
}

int main(void) {
    char key;
    int x=10, y=5;
    do {
        gotoxy(x, y);
        printf("A");
        key = getch();
        move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
    } while(key != 27); // ESC 종료
    return 0;
}
```

### 3. 메뉴 만들기 
```
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void) {
    int select;
    system("cls");
    printf("간식 만들기\n\n");
    printf("1. 햄버거 \n");
    printf("2. 스파게티\n");
    printf("3. 프로그램 종료\n\n");
    printf("메뉴번호 입력>");
    select = getch() - 48;
    return select;
}

int main(void) {
    int c;
    while((c = menu_display()) != 3) {
        switch(c) {
            case 1: printf("햄버거 만드는 방법\n"); break;
            case 2: printf("스파게티 만드는 방법\n"); break;
        }
        printf("\n아무 키나 누르면 계속...\n");
        getch();
    }
    return 0;
}
```

### 4. 중복 없는 로또 번호 생성
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, j, lotto[6];
    srand(time(NULL));
    for(i=0;i<6;i++) {
        lotto[i] = rand()%45 + 1;
        for(j=0;j<i;j++) {
            if(lotto[i] == lotto[j]) { i--; break; }
        }
    }
    for(i=0;i<6;i++)
        printf("%2d\n", lotto[i]);
    return 0;
}
```

### 5. 가변 인수 함수
```
#include <stdio.h>
#include <stdarg.h>

double sum(int count, ...) {
    double total = 0, number;
    int i=0;
    va_list ap;
    va_start(ap, count);
    while(i < count) {
        number = va_arg(ap, double);
        total += number;
        i++;
    }
    va_end(ap);
    return total;
}

int main(void) {
    printf("합계 = %lf\n", sum(2, 10.5, 20.23));
    printf("합계 = %lf\n", sum(5, 10.3, 245.67, 0.51, 198345.764));
    return 0;
}
```










