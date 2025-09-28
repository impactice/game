
# C언어 게임 프로그래밍 예제 코드

이 저장소는 C언어를 활용한 간단한 콘솔 기반 프로그래밍 예제들을 포함하고 있습니다. 숫자 다루기, 콘솔 UI, 도형 제어 등 다양한 주제를 다룹니다.

## 목차
1.  [문자열을 이용한 숫자 단위 출력](#1-문자열을-이용한-숫자-단위-출력)
2.  [정수형 연산을 이용한 숫자 단위 출력 (반복문)](#2-정수형-연산을-이용한-숫자-단위-출력-반복문)
3.  [정수형 연산을 이용한 숫자 단위 출력 (재귀 호출)](#3-정수형-연산을-이용한-숫자-단위-출력-재귀-호출)
4.  [디지털 숫자 출력](#4-디지털-숫자-출력)
5.  [수평 및 수직 슬라이드 바](#5-수평-및-수직-슬라이드-바)
6.  [도형 이동 및 회전](#6-도형-이동-및-회전)

---

## 1. 문자열을 이용한 숫자 단위 출력

입력된 숫자를 문자열로 처리하여 각 자릿수를 출력하는 예제입니다.

### 높은 단위부터 출력
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char number[20];
    int length, i;

    printf("금액을 입력하고 Enter>");
    scanf("%s", number);

    length = strlen(number);

    for(i = 0; i < length; i++)
        printf("%c\n", number[i]);

    return 0;
}
```

### 낮은 단위부터 출력
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char number[20];
    int length, i;

    printf("금액을 입력하고 Enter>");
    scanf("%s", number);

    length = strlen(number);

    for(i = length; i >= 0; i--)
        printf("%c\n", number[i]);

    return 0;
}
```

---

## 2. 정수형 연산을 이용한 숫자 단위 출력 (반복문)

정수형 숫자를 `log10`과 `pow` 함수 또는 나머지 연산자를 이용해 자릿수별로 분리하여 출력합니다.

### 높은 단위부터 출력 (함수)
```c
void serial_number(long number) {
    int num;
    int i, length = 0;

    length = (int)(log10(number) + 1); //최대 자리수 계산

    for(i = length; i >= 1; i--)
    {
        num = number / (long) pow(10, i - 1);
        printf("%ld\n", num);
        number = number - num * (long)pow(10, i - 1);
    }
    printf("\n");
}
```

### 낮은 단위부터 출력 (함수)
```c
void reverse_number(long number) {
    while(number > 0)
    {
        printf("%ld\n", number % 10);
        number /= 10;
    }
}
```

### 통합 실행 코드 (반복문)
```c
#include <stdio.h>
#include <conio.h>
#include <math.h>

void serial_number(long number);
void reverse_number(long number);

int main(void) {
    long number = 12345698;

    printf("입력 숫자 : %ld\n\n", number);

    printf("높은 단위부터 출력\n");
    serial_number(number);

    printf("\n낮은 단위부터 출력\n");
    reverse_number(number);

    printf("press any key to continue.......");
    getch();

    return 0;
}
// serial_number, reverse_number 함수 구현은 위와 동일
```

---

## 3. 정수형 연산을 이용한 숫자 단위 출력 (재귀 호출)

재귀 함수를 사용하여 각 자릿수를 출력하는 더 간결한 방식의 예제입니다.

### 높은 단위부터 출력 (재귀 함수)
```c
void serial_number(long number) {
    if (number > 0)
    {
        serial_number(number / 10);
        printf("%ld\n", number % 10);
    }
    else
        return;
}
```

### 낮은 단위부터 출력 (재귀 함수)
```c
void reverse_number(long number) {
    printf("%ld\n", number % 10);
    if((number / 10) > 0)
        reverse_number(number / 10);
    else
        return;
}
```
---

## 4. 디지털 숫자 출력

입력된 정수를 콘솔에 디지털 형태(`■`)로 출력하는 프로그램입니다.

```c
#include <stdio.h>

void number_check(int k, int i);
void digit_print(int dim[], int line);

// 0-9 디지털 숫자 모양 정의 (배열 생략)
int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
// ... (one ~ nine 배열) ...

int main(void) {
    int num, line;
    printf("디지털 숫자 출력 프로그램\n");
    printf("1 이상의 정수만 입력합니다. \n\n");
    printf("\n정수 숫자입력 후 Enter> ");
    scanf("%d", &num);
    printf("\n\n");
    for(line = 0; line <= 4; line++) {
        number_check(num, line);
        printf("\n");
    }
    return 0;
}

void number_check(int k, int i) {
    if (k >= 1) {
        number_check(k / 10, i);
        switch(k % 10) {
            case 0: digit_print(zero, i); break;
            case 1: digit_print(one, i); break;
            // ... (case 2 ~ 9) ...
        }
    }
}

void digit_print(int dim[], int line) {
    int i;
    for(i = line * 4; i <= line * 4 + 3; i++)
        if (dim[i] == 1)
            printf("■");
        else
            printf("  ");
    printf(" ");
}
```

---

## 5. 수평 및 수직 슬라이드 바

콘솔 창에서 화살표 키로 움직이는 슬라이드 바를 구현한 예제입니다. `windows.h` 헤더가 필요합니다.

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void draw_horizontal_slide(int x, int y, int length, char *s);
void draw_vertical_slide(int x, int y, int length, char *s);
void draw_rectangle(int c, int r);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);

int main(void) {
    char *slide = "■", key;
    int x = 1, y = 1;
    int h_slide_length, v_slide_length;

    printf("슬라이드바 표시\n\n");
    printf("수평 슬라이드바의 길이(최대 70)를 입력하고 Enter>");
    scanf("%d", &h_slide_length);
    printf("수직 슬라이드바의 길이(최대 19)를 입력하고 Enter>");
    scanf("%d", &v_slide_length);
    system("cls");

    do {
        draw_vertical_slide(1, y, v_slide_length, slide);
        draw_horizontal_slide(x, v_slide_length + 3, h_slide_length, slide);
        key = getch();
        move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);
    } while(key != 27);

    return 0;
}
// ... (함수 구현 생략) ...
```

---

## 6. 도형 이동 및 회전

콘솔 화면에 표시된 도형을 화살표 키로 이동시키고 스페이스 키로 회전시키는 프로그램입니다.

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// 함수 선언
void rotation_right(int m[][3]);
void move_shape(int m[][3]);
void print_shape(int m[][3]);
void move_control(int m[][3]);
void gotoxy(int x, int y);
void print_direction(void);

// 전역 변수
int x = 35, y = 12;
int inx = 0, iny = 0;

int main(void) {
    int shape1[3][3] = { 
        {0,1,0},
        {1,1,1},
        {0,1,0} 
    };
    move_control(shape1);
    return 0;
}
// ... (함수 구현 생략) ...
```
