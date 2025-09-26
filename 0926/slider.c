#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // Windows API 함수 사용을 위해 필요

// 함수 선언
void draw_horizontal_slide(int x, int y, int length, char *s);
void draw_vertical_slide(int x, int y, int length, char *s);
void draw_rectangle(int c, int r);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);

int main(void)
{
    // 👇 system("chcp 65001") 대신 아래 코드를 사용합니다. (더 안정적)
    SetConsoleOutputCP(65001); // 콘솔 출력 인코딩을 UTF-8로 설정
    SetConsoleCP(65001);       // 콘솔 입력 인코딩을 UTF-8로 설정

    system("cls");

    char *slide = "■", key;
    int x = 1, y = 1;
    int h_slide_length, v_slide_length;

    printf("슬라이드바 표시\n\n");
    printf("수평 슬라이드바의 길이(최대 70)를 입력하고 Enter > ");
    scanf("%d", &h_slide_length);
    printf("수직 슬라이드바의 길이(최대 19)를 입력하고 Enter > ");
    scanf("%d", &v_slide_length);

    do
    {
        system("cls");

        draw_vertical_slide(1, y, v_slide_length, slide);
        draw_horizontal_slide(x, v_slide_length + 3, h_slide_length, slide);
        
        key = getch();
        if (key == 0 || key == 224) { // 확장 키 입력 처리
            key = getch();
        }

        move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);

    } while(key != 27); // 27은 ESC 키입니다.

    return 0;
}

void draw_horizontal_slide(int x, int y, int length, char *s)
{
    if (x > length) x = length;
    if (x < 1) x = 1;

    gotoxy(1, y);
    draw_rectangle(length, 3); // 너비, 높이

    gotoxy(x, y + 1);
    printf("%s", s);
    
    gotoxy(length * 2 + 2, y + 1);
    printf("%2d", x);
}

void draw_vertical_slide(int x, int y, int length, char *s)
{
    if (y > length) y = length;
    if (y < 1) y = 1;

    gotoxy(x, 1);
    draw_rectangle(3, length); // 너비, 높이

    gotoxy(x + 1, y);
    printf("%s", s);

    gotoxy(x + 5, length + 1);
    printf("%2d", y);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
    switch(key)
    {
        case 72: // 위
            (*y1)--;
            if (*y1 < 1) *y1 = 1;
            break;
        case 80: // 아래
            (*y1)++;
            if (*y1 > y_b) *y1 = y_b;
            break;
        case 75: // 왼쪽
            (*x1)--;
            if (*x1 < 1) *x1 = 1;
            break;
        case 77: // 오른쪽
            (*x1)++;
            if (*x1 > x_b) *x1 = x_b;
            break;
        default:
            return;
    }
}

// 확장 아스키 문자로 사각형 그리기
void draw_rectangle(int c, int r) {
    int i, j;
    // 윗쪽 테두리 (┌───┐)
    printf("┌");
    for (i = 0; i < c - 2; i++) printf("─");
    printf("┐\n");

    // 중간 부분 (│   │)
    for (i = 0; i < r - 2; i++) {
        printf("│");
        for (j = 0; j < c - 2; j++) printf(" ");
        printf("│\n");
    }

    // 아랫쪽 테두리 (└───┘)
    printf("└");
    for (i = 0; i < c - 2; i++) printf("─");
    printf("┘\n");
}

void gotoxy(int x, int y)
{
    COORD Pos = { (short)(x - 1), (short)(y - 1) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// 수직 슬라이드 바