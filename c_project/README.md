## 원본 
```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

long time_to_number(void);
void number_check(int, int);
void digit_print(int*, int);
void gotoxy(int x, int y);
void dot_print(int hour);

//배열 one[]~배열 nine[]까지의 정의는 [예제 5.4.7]과 [예제 6.1.1]을 이용
int zero[20] =
	{1,1,1,1,
	 1,0,0,1,
	 1,0,0,1,
	 1,0,0,1,
	 1,1,1,1};

int one[20]=
 {0,0,1,0,
  0,0,1,0,
  0,0,1,0,
  0,0,1,0,
  0,0,1,0};

int two[20]=
 {1,1,1,1,
  0,0,0,1,
  1,1,1,1,
  1,0,0,0,
  1,1,1,1};

int three[20]=
 {1,1,1,1,
  0,0,0,1,
  1,1,1,1,
  0,0,0,1,
  1,1,1,1};

int four[20]=
 {1,0,0,1,
  1,0,0,1,
  1,1,1,1,
  0,0,0,1,
  0,0,0,1};

int five[20]=
 {1,1,1,1,
  1,0,0,0,
  1,1,1,1,
  0,0,0,1,
  1,1,1,1};

int six[20]=
 {1,0,0,0,
  1,0,0,0,
  1,1,1,1,
  1,0,0,1,
  1,1,1,1};

int seven[20]=
 {1,1,1,1,
  0,0,0,1,
  0,0,0,1,
  0,0,0,1,
  0,0,0,1};

int eight[20]=
 {1,1,1,1,
  1,0,0,1,
  1,1,1,1,
  1,0,0,1,
  1,1,1,1};

int nine[20] =
	{1,1,1,1,
	 1,0,0,1,
	 1,1,1,1,
	 0,0,0,1,
	 0,0,0,1};


int main(void)
{
	int line; 
	long time_number;
	printf("디지털 시계 프로그램\n\n");
	printf("아무키나 누르면 현재시간을 출력합니다.\n");
	getch();
	system("cls");
	while(!kbhit())
	{
		gotoxy(1,3);
		time_number=time_to_number();
		for(line=0;line<=4;line++)
		{
			number_check(time_number, line);
			printf("\n");
		}
		dot_print(time_number);
		printf("\n\n\n\n아무키나 누르면 종료합니다.\n");
	}
	return 0;
}
long time_to_number(void)
{
	time_t current;
	struct tm *d;
	int hour, min, sec; 
	current=time(NULL);
	d=localtime(&current);
	hour=d->tm_hour*10000;
	min=d->tm_min*100;
	sec=d->tm_sec;
	return hour+min+sec;
}

void number_check(int k, int i)
{
 if (k>=1)
  {
     number_check(k/10, i);
     switch(k%10)
     {
        case 0 : 
	  digit_print(zero, i);
	  break;
        case 1 : 
	  digit_print(one, i);
	  break;
        case 2 : 
	  digit_print(two, i);
	  break;
        case 3 : 
	  digit_print(three, i);
	  break;
        case 4 : 
	  digit_print(four, i);
	  break;
        case 5 : 
	  digit_print(five, i);
	  break;
        case 6 : 
	  digit_print(six, i);
	  break;
        case 7 : 
	  digit_print(seven, i);
	  break;
        case 8 : 
	  digit_print(eight, i);
	  break;
        case 9 : 
          digit_print(nine, i);
	  break;
     }
  }
}
void digit_print(int dim[], int check)
{
 //[함수 5.4.8]의 정의부분 참고
 int i;
 for(i = check*4; i <= check*4+3; i++)
  if (dim[i]==1)
	 printf("■");
  else
	 printf("  ");
 printf("  ");
}
void dot_print(int hour)
{
	int i;
	if (hour<100000)
	{
		for(i=0;i<2;i++)
		{
			gotoxy(10+(i*27), 4);
			printf("■");
			gotoxy(10+(i*27), 6);
			printf("■");
		}
	}
	else
	{
		for(i=0;i<2;i++)
		{
			gotoxy(24+(i*26), 4);
			printf("■");
			gotoxy(24+(i*26), 6);
			printf("■");
		}
	}

}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```

<img width="1727" height="921" alt="image" src="https://github.com/user-attachments/assets/ac8b0eaf-c4a6-43f5-8d63-e830d737ecc6" />

- 문제점 : 가독성이 안 좋아서 시간을 읽기 힘들다  


## 수정 버전_1
```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

long time_to_number(void);
void print_time_digits(int time_number);
void digit_print(int*, int);
void gotoxy(int x, int y);
void draw_frame(void);

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    int x, y;
    for (x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current;
    struct tm *d;
    int hour, min, sec;
    current = time(NULL);
    d = localtime(&current);
    hour = d->tm_hour;
    min = d->tm_min;
    sec = d->tm_sec;
    return hour * 10000 + min * 100 + sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        if (dim[i] == 1)
            printf("█");
        else
            printf(" ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5;
    int start_y = 4;
    int spacing = 8;

    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) {
                printf("   "); // 공간 확보 (콜론 자리)
            }
        }
    }

    // 콜론 출력
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");

    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

int main(void) {
    long time_number;
    system("chcp 65001 > nul"); // UTF-8 인코딩 설정
    system("color 0A");         // 검정 배경 + 초록 글자
    printf("디지털 시계 프로그램\n\n");
    printf("아무 키나 누르면 현재 시간을 출력합니다.\n");
    getch();
    system("cls");
    draw_frame();
    while (!kbhit()) {
        gotoxy(1, 4);
        time_number = time_to_number();
        print_time_digits(time_number);
        gotoxy(5, 13);
        printf("아무 키나 누르면 종료합니다.");
        Sleep(1000);
    }
    return 0;
}
```

<img width="1732" height="915" alt="image" src="https://github.com/user-attachments/assets/88e9abb7-2a02-4da2-9365-5980991bc329" />

## 날짜와 요일 표시 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

long time_to_number(void);
void print_time_digits(int time_number);
void digit_print(int*, int);
void gotoxy(int x, int y);
void draw_frame(void);
void print_date_and_weekday(void);

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    int x, y;
    for (x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current;
    struct tm *d;
    int hour, min, sec;
    current = time(NULL);
    d = localtime(&current);
    hour = d->tm_hour;
    min = d->tm_min;
    sec = d->tm_sec;
    return hour * 10000 + min * 100 + sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        if (dim[i] == 1)
            printf("█");
        else
            printf(" ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5;
    int start_y = 4;
    int spacing = 8;

    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) {
                printf("   "); // 공간 확보 (콜론 자리)
            }
        }
    }

    // 콜론 출력
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");

    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);

    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 10);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

int main(void) {
    long time_number;
    system("chcp 65001 > nul"); // UTF-8 인코딩 설정
    system("color 0A");         // 검정 배경 + 초록 글자
    printf("디지털 시계 프로그램\n\n");
    printf("아무 키나 누르면 현재 시간을 출력합니다.\n");
    getch();
    system("cls");
    draw_frame();
    while (!kbhit()) {
        gotoxy(1, 4);
        time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();
        gotoxy(5, 13);
        printf("아무 키나 누르면 종료합니다.");
        Sleep(1000);
    }
    return 0;
}
```

<img width="1457" height="640" alt="image" src="https://github.com/user-attachments/assets/86b2e009-df17-403a-a906-c636b74e3414" />

## 알람 기능 추가 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

long time_to_number(void);
void print_time_digits(int time_number);
void digit_print(int*, int);
void gotoxy(int x, int y);
void draw_frame(void);
void print_date_and_weekday(void);
void check_alarm(int hour, int minute, int alarm_hour, int alarm_minute);

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    int x, y;
    for (x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current;
    struct tm *d;
    int hour, min, sec;
    current = time(NULL);
    d = localtime(&current);
    hour = d->tm_hour;
    min = d->tm_min;
    sec = d->tm_sec;
    return hour * 10000 + min * 100 + sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        if (dim[i] == 1)
            printf("█");
        else
            printf(" ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5;
    int start_y = 4;
    int spacing = 8;

    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) {
                printf("   "); // 공간 확보 (콜론 자리)
            }
        }
    }

    // 콜론 출력
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");

    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);

    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 10);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void check_alarm(int hour, int minute, int alarm_hour, int alarm_minute) {
    static int alarm_triggered = 0;
    if (hour == alarm_hour && minute == alarm_minute && !alarm_triggered) {
        for (int i = 0; i < 3; i++) {
            Beep(1000, 300); // 1000Hz, 300ms
            Sleep(200);
        }
        alarm_triggered = 1;
        gotoxy(5, 11);
        printf("🔔 알람 시간입니다! 🔔");
    }
}

int main(void) {
    long time_number;
    int alarm_hour, alarm_minute;

    system("chcp 65001 > nul"); // UTF-8 인코딩 설정
    system("color 0A");         // 검정 배경 + 초록 글자

    system("cls");
    printf("디지털 시계 프로그램\n\n");
    printf("알람 시간을 입력하세요 (24시간제)\n");
    printf("시: ");
    scanf("%d", &alarm_hour);
    printf("분: ");
    scanf("%d", &alarm_minute);
    printf("\n알람이 설정되었습니다. 아무 키나 누르면 시계를 시작합니다.\n");
    getch();
    system("cls");
    draw_frame();

    while (!kbhit()) {
        gotoxy(1, 4);
        time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();

        time_t current = time(NULL);
        struct tm *d = localtime(&current);
        check_alarm(d->tm_hour, d->tm_min, alarm_hour, alarm_minute);

        gotoxy(5, 13);
        printf("아무 키나 누르면 종료합니다.");
        Sleep(1000);
    }
    return 0;
}
```

<img width="1721" height="909" alt="image" src="https://github.com/user-attachments/assets/8f43eecd-1bfa-489e-84aa-c33e98df1332" />

<img width="1727" height="920" alt="image" src="https://github.com/user-attachments/assets/b140810a-f6aa-407a-9998-7c33740acb87" />

<img width="1730" height="916" alt="image" src="https://github.com/user-attachments/assets/f7ee893d-9e36-4afe-8b69-e02dd48b63ce" />


## 알람 ver.2
- 설정한 알람을 표시하도록 수정

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

long time_to_number(void);
void print_time_digits(int time_number);
void digit_print(int*, int);
void gotoxy(int x, int y);
void draw_frame(void);
void print_date_and_weekday(void);
void check_alarm(int hour, int minute, int alarm_hour, int alarm_minute);
void print_alarm_time(int alarm_hour, int alarm_minute);

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    int x, y;
    for (x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current;
    struct tm *d;
    int hour, min, sec;
    current = time(NULL);
    d = localtime(&current);
    hour = d->tm_hour;
    min = d->tm_min;
    sec = d->tm_sec;
    return hour * 10000 + min * 100 + sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        if (dim[i] == 1)
            printf("█");
        else
            printf(" ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5;
    int start_y = 4;
    int spacing = 8;

    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) {
                printf("   ");
            }
        }
    }

    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");

    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 10);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void print_alarm_time(int alarm_hour, int alarm_minute) {
    gotoxy(5, 11);
    printf("알람 설정: %02d:%02d", alarm_hour, alarm_minute);
}

void check_alarm(int hour, int minute, int alarm_hour, int alarm_minute) {
    static int alarm_triggered = 0;
    if (hour == alarm_hour && minute == alarm_minute && !alarm_triggered) {
        for (int i = 0; i < 3; i++) {
            Beep(1000, 300);
            Sleep(200);
        }
        alarm_triggered = 1;
        gotoxy(40, 11);
        printf("🔔 알람 시간입니다! 🔔");
    }
}

int main(void) {
    long time_number;
    int alarm_hour, alarm_minute;

    system("chcp 65001 > nul");
    system("color 0A");

    system("cls");
    printf("디지털 시계 프로그램\n\n");
    printf("알람 시간을 입력하세요 (24시간제)\n");
    printf("시: ");
    scanf("%d", &alarm_hour);
    printf("분: ");
    scanf("%d", &alarm_minute);
    printf("\n알람이 설정되었습니다. 아무 키나 누르면 시계를 시작합니다.\n");
    getch();
    system("cls");
    draw_frame();

    while (!kbhit()) {
        gotoxy(1, 4);
        time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();
        print_alarm_time(alarm_hour, alarm_minute);

        time_t current = time(NULL);
        struct tm *d = localtime(&current);
        check_alarm(d->tm_hour, d->tm_min, alarm_hour, alarm_minute);

        gotoxy(5, 13);
        printf("아무 키나 누르면 종료합니다.");
        Sleep(1000);
    }

    return 0;
}
```

<img width="1729" height="909" alt="image" src="https://github.com/user-attachments/assets/79d6f756-297a-4595-b813-a878aa5c6e74" />


## 알람 ver.3
- 알람 설정을 여러 개 할 수 있고, 설정한 알람을 여러개 보이기 밑 디자인 정리 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX_ALARMS 10

int alarm_hours[MAX_ALARMS];
int alarm_minutes[MAX_ALARMS];
int alarm_count = 0;

long time_to_number(void);
void print_time_digits(int time_number);
void digit_print(int*, int);
void gotoxy(int x, int y);
void draw_frame(void);
void print_date_and_weekday(void);
void check_alarm(int hour, int minute);
void print_alarm_list(void);

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    int x, y;
    for (x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current;
    struct tm *d;
    int hour, min, sec;
    current = time(NULL);
    d = localtime(&current);
    hour = d->tm_hour;
    min = d->tm_min;
    sec = d->tm_sec;
    return hour * 10000 + min * 100 + sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        printf(dim[i] ? "█" : " ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5;
    int start_y = 4;
    int spacing = 8;

    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) printf("   ");
        }
    }

    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 10);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void print_alarm_list() {
    gotoxy(5, 14);
    printf("╔══════════════════════════════╗");
    for (int i = 0; i < alarm_count; i++) {
        gotoxy(5, 15 + i);
        printf("║ 알람 %d: %02d:%02d                ║", i + 1, alarm_hours[i], alarm_minutes[i]);
    }
    gotoxy(5, 15 + alarm_count);
    printf("╚══════════════════════════════╝");
}

void check_alarm(int hour, int minute) {
    static int triggered[MAX_ALARMS] = {0};
    for (int i = 0; i < alarm_count; i++) {
        if (hour == alarm_hours[i] && minute == alarm_minutes[i] && !triggered[i]) {
            for (int j = 0; j < 3; j++) {
                Beep(1000, 300);
                Sleep(200);
            }
            triggered[i] = 1;
            gotoxy(40, 11);
            printf("🔔 알람 %d 시간입니다! 🔔", i + 1);
        }
    }
}

int main(void) {
    long time_number;

    system("chcp 65001 > nul");
    system("color 0A");

    system("cls");
    printf("디지털 시계 프로그램\n\n");
    printf("알람 시간을 여러 개 입력하세요 (24시간제, -1 입력 시 종료)\n");

    while (alarm_count < MAX_ALARMS) {
        int hour, minute;
        printf("시: ");
        scanf("%d", &hour);
        if (hour == -1) break;
        printf("분: ");
        scanf("%d", &minute);
        alarm_hours[alarm_count] = hour;
        alarm_minutes[alarm_count] = minute;
        alarm_count++;
    }

    printf("\n알람이 설정되었습니다. 아무 키나 누르면 시계를 시작합니다.\n");
    getch();
    system("cls");
    draw_frame();

    while (!kbhit()) {
        gotoxy(1, 4);
        time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();
        print_alarm_list();
        time_t current = time(NULL);
        struct tm *d = localtime(&current);
        check_alarm(d->tm_hour, d->tm_min);

        gotoxy(5, 13);
        printf("아무 키나 누르면 종료합니다.");
        Sleep(1000);
    }

    system("cls");
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    return 0;
}
```

<img width="1366" height="698" alt="image" src="https://github.com/user-attachments/assets/a4297a03-e0a9-4cff-be11-4933f97da0a3" />

<img width="1365" height="699" alt="image" src="https://github.com/user-attachments/assets/00d49354-edc4-42a1-a8a5-f06e2cdd6710" />

## 알람 ver.4
- 알람 삭제 기능, 알람을 설정했으면 순서대로 보이도록 변경 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX_ALARMS 10

int alarm_hours[MAX_ALARMS];
int alarm_minutes[MAX_ALARMS];
int alarm_count = 0;

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    for (int x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (int y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        printf(dim[i] ? "█" : " ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5, start_y = 4, spacing = 8;
    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) printf("   ");
        }
    }

    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 10);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void print_alarm_list() {
    gotoxy(5, 14);
    printf("╔══════════════════════════════╗");
    for (int i = 0; i < alarm_count; i++) {
        gotoxy(5, 15 + i);
        printf("║ 알람 %d: %02d:%02d                ║", i + 1, alarm_hours[i], alarm_minutes[i]);
    }
    gotoxy(5, 15 + alarm_count);
    printf("╚══════════════════════════════╝");
}

void sort_alarms() {
    for (int i = 0; i < alarm_count - 1; i++) {
        for (int j = i + 1; j < alarm_count; j++) {
            if (alarm_hours[i] > alarm_hours[j] ||
               (alarm_hours[i] == alarm_hours[j] && alarm_minutes[i] > alarm_minutes[j])) {
                int temp_h = alarm_hours[i];
                int temp_m = alarm_minutes[i];
                alarm_hours[i] = alarm_hours[j];
                alarm_minutes[i] = alarm_minutes[j];
                alarm_hours[j] = temp_h;
                alarm_minutes[j] = temp_m;
            }
        }
    }
}

void delete_alarm(int index) {
    if (index < 0 || index >= alarm_count) return;
    for (int i = index; i < alarm_count - 1; i++) {
        alarm_hours[i] = alarm_hours[i + 1];
        alarm_minutes[i] = alarm_minutes[i + 1];
    }
    alarm_count--;
}

void check_alarm(int hour, int minute) {
    static int triggered[MAX_ALARMS] = {0};
    for (int i = 0; i < alarm_count; i++) {
        if (hour == alarm_hours[i] && minute == alarm_minutes[i] && !triggered[i]) {
            for (int j = 0; j < 3; j++) {
                Beep(1000, 300);
                Sleep(200);
            }
            triggered[i] = 1;
            gotoxy(40, 11);
            printf("🔔 알람 %d 시간입니다! 🔔", i + 1);
        }
    }
}

int main(void) {
    system("chcp 65001 > nul");
    system("color 0A");
    system("cls");

    printf("디지털 시계 프로그램\n\n");
    printf("알람 시간을 여러 개 입력하세요 (24시간제, -1 입력 시 종료)\n");

    while (alarm_count < MAX_ALARMS) {
        int hour, minute;
        printf("시: ");
        scanf("%d", &hour);
        if (hour == -1) break;
        printf("분: ");
        scanf("%d", &minute);
        alarm_hours[alarm_count] = hour;
        alarm_minutes[alarm_count] = minute;
        alarm_count++;
        sort_alarms();
    }

    int choice;
    do {
        system("cls");
        printf("현재 설정된 알람 목록:\n");
        for (int i = 0; i < alarm_count; i++) {
            printf("  [%d] %02d:%02d\n", i + 1, alarm_hours[i], alarm_minutes[i]);
        }
        printf("\n삭제할 알람 번호를 입력하세요 (0 입력 시 계속 진행): ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= alarm_count) {
            delete_alarm(choice - 1);
            printf("알람이 삭제되었습니다.\n");
            Sleep(1000);
        }
    } while (choice != 0);

    printf("\n알람이 설정되었습니다. 아무 키나 누르면 시계를 시작합니다.\n");
    getch();
    system("cls");
    draw_frame();

    while (!kbhit()) {
        gotoxy(1, 4);
        long time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();
        print_alarm_list();

        time_t current = time(NULL);
        struct tm *d = localtime(&current);
        check_alarm(d->tm_hour, d->tm_min);

        gotoxy(5, 13);
        printf("아무 키나 누르면 종료합니다.");
        Sleep(1000);
    }

    system("cls");
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    return 0;
}
```

<img width="1364" height="692" alt="image" src="https://github.com/user-attachments/assets/f470487b-ccbf-4c38-a5f2-127d62546b0b" />


<img width="1366" height="702" alt="image" src="https://github.com/user-attachments/assets/5cd39760-cc60-47ac-92e6-eda05087999c" />


<img width="1366" height="693" alt="image" src="https://github.com/user-attachments/assets/9c3744a0-6872-4e33-9d07-021742d859fa" />

## 디자인 다듬기
- 화면이 축소 되었다가 다시 늘리면 화면이 깨지는 문제 발견 -> 화면이 늘리면 안 깨지게 변경과 알람을 시계 나오는 화면에서 삭제 되도록 변경 

<img width="1334" height="749" alt="image" src="https://github.com/user-attachments/assets/1f16fe35-f511-4615-8b99-39a0988c162b" />



```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX_ALARMS 10

// 전역 변수 (기존과 동일)
int alarm_hours[MAX_ALARMS];
int alarm_minutes[MAX_ALARMS];
int alarm_count = 0;

int zero[20] = {1,1,1,1, 1,0,0,1, 1,0,0,1, 1,0,0,1, 1,1,1,1};
int one[20]  = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};
int two[20]  = {1,1,1,1, 0,0,0,1, 1,1,1,1, 1,0,0,0, 1,1,1,1};
int three[20]= {1,1,1,1, 0,0,0,1, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int four[20] = {1,0,0,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};
int five[20] = {1,1,1,1, 1,0,0,0, 1,1,1,1, 0,0,0,1, 1,1,1,1};
int six[20]  = {1,0,0,0, 1,0,0,0, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int seven[20]= {1,1,1,1, 0,0,0,1, 0,0,0,1, 0,0,0,1, 0,0,0,1};
int eight[20]= {1,1,1,1, 1,0,0,1, 1,1,1,1, 1,0,0,1, 1,1,1,1};
int nine[20] = {1,1,1,1, 1,0,0,1, 1,1,1,1, 0,0,0,1, 0,0,0,1};

// gotoxy 및 다른 함수들 (기존과 동일)
void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_frame() {
    for (int x = 1; x <= 80; x++) {
        gotoxy(x, 2); printf("═");
        gotoxy(x, 12); printf("═");
    }
    for (int y = 3; y <= 11; y++) {
        gotoxy(1, y); printf("║");
        gotoxy(80, y); printf("║");
    }
    gotoxy(1, 2); printf("╔");
    gotoxy(80, 2); printf("╗");
    gotoxy(1, 12); printf("╚");
    gotoxy(80, 12); printf("╝");
}

long time_to_number(void) {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}

void digit_print(int dim[], int row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (int i = row * 4; i <= row * 4 + 3; i++) {
        printf(dim[i] ? "█" : " ");
    }
    printf("   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) {
        digits[i] = time_number % 10;
        time_number /= 10;
    }

    int start_x = 5, start_y = 4, spacing = 8;
    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break;
                case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break;
                case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break;
                case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break;
                case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break;
                case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) printf("   ");
        }
    }

    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 10);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void print_alarm_list() {
    gotoxy(5, 14);
    printf("╔════════════════════════════════════╗");
    if (alarm_count == 0) {
        gotoxy(5, 15);
        printf("║ 설정된 알람이 없습니다.            ║");
    } else {
        for (int i = 0; i < alarm_count; i++) {
            gotoxy(5, 15 + i);
            printf("║ 알람 %d: %02d:%02d   [삭제:%d]           ║", i + 1, alarm_hours[i], alarm_minutes[i], i + 1);
        }
    }
    // 알람 목록 높이에 맞춰 동적으로 프레임 닫기
    gotoxy(5, 15 + (alarm_count == 0 ? 1 : alarm_count));
    printf("╚════════════════════════════════════╝");
}

void sort_alarms() {
    for (int i = 0; i < alarm_count - 1; i++) {
        for (int j = i + 1; j < alarm_count; j++) {
            if (alarm_hours[i] > alarm_hours[j] ||
               (alarm_hours[i] == alarm_hours[j] && alarm_minutes[i] > alarm_minutes[j])) {
                int temp_h = alarm_hours[i];
                int temp_m = alarm_minutes[i];
                alarm_hours[i] = alarm_hours[j];
                alarm_minutes[i] = alarm_minutes[j];
                alarm_hours[j] = temp_h;
                alarm_minutes[j] = temp_m;
            }
        }
    }
}

void delete_alarm(int index) {
    if (index < 0 || index >= alarm_count) return;
    for (int i = index; i < alarm_count - 1; i++) {
        alarm_hours[i] = alarm_hours[i + 1];
        alarm_minutes[i] = alarm_minutes[i + 1];
    }
    alarm_count--;
}

void handle_alarm_deletion() {
    int del;
    // 알람 목록 높이에 맞춰 동적으로 입력 프롬프트 위치 조정
    gotoxy(5, 17 + (alarm_count == 0 ? 1 : alarm_count));
    printf("삭제할 알람 번호를 입력하세요 (0 입력 시 취소): ");
    scanf("%d", &del);
    if (del > 0 && del <= alarm_count) {
        delete_alarm(del - 1);
        sort_alarms();
        gotoxy(5, 18 + (alarm_count == 0 ? 1 : alarm_count));
        printf("알람 %d이(가) 삭제되었습니다. 잠시 후 돌아갑니다.", del);
        Sleep(1500);
    }
}

void check_alarm(int hour, int minute) {
    static int triggered[MAX_ALARMS] = {0};
    for (int i = 0; i < alarm_count; i++) {
        if (hour == alarm_hours[i] && minute == alarm_minutes[i] && !triggered[i]) {
            for (int j = 0; j < 3; j++) {
                Beep(1000, 300);
                Sleep(200);
            }
            triggered[i] = 1;
            gotoxy(40, 11);
            printf("🔔 알람 %d 시간입니다! 🔔", i + 1);
        } else if (hour != alarm_hours[i] || minute != alarm_minutes[i]) {
            triggered[i] = 0; // 다음 날 같은 시간에 다시 울릴 수 있도록 초기화
        }
    }
}

void set_console_cursor_visibility(int visible) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = visible; // 0 = 숨김, 1 = 보임
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int main(void) {
    system("chcp 65001 > nul");
    system("title 디지털 시계"); // 콘솔 창 제목 설정
    system("mode con: cols=82 lines=25"); // 콘솔 창 크기 고정
    system("color 0A");

    printf("디지털 시계 프로그램\n\n");
    printf("알람 시간을 여러 개 입력하세요 (24시간제, 시에 -1 입력 시 종료)\n");

    while (alarm_count < MAX_ALARMS) {
        int hour, minute;
        printf("시: ");
        if (scanf("%d", &hour) != 1) { // 숫자가 아닌 입력 방지
            while(getchar() != '\n'); // 입력 버퍼 비우기
            printf("숫자를 입력해주세요.\n");
            continue;
        }
        if (hour == -1) break;
        if (hour < 0 || hour > 23) {
            printf("잘못된 시간입니다. (0-23 사이 입력)\n");
            continue;
        }
        printf("분: ");
        if (scanf("%d", &minute) != 1) {
            while(getchar() != '\n');
            printf("숫자를 입력해주세요.\n");
            continue;
        }
        if (minute < 0 || minute > 59) {
            printf("잘못된 분입니다. (0-59 사이 입력)\n");
            continue;
        }
        alarm_hours[alarm_count] = hour;
        alarm_minutes[alarm_count] = minute;
        alarm_count++;
        sort_alarms();
    }

    printf("\n알람이 설정되었습니다. 아무 키나 누르면 시계를 시작합니다.\n");
    getch();

    while (1) {
        // ✨ 핵심 수정: 매번 화면을 지우고 테두리를 다시 그림
        system("cls");
        draw_frame();

        // 커서 숨기기 (화면 깜빡임 방지)
        set_console_cursor_visibility(0);
        
        long time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();
        print_alarm_list();

        time_t current = time(NULL);
        struct tm *d = localtime(&current);
        check_alarm(d->tm_hour, d->tm_min);

        gotoxy(5, 13);
        printf("알람을 삭제하려면 d 키를 누르세요. 종료하려면 아무 키나 누르세요.");
        
        Sleep(1000); // 1초 대기

        if (kbhit()) {
            char ch = getch();
            if (ch == 'd' || ch == 'D') {
                // 입력을 받기 위해 커서를 다시 보이게 함
                set_console_cursor_visibility(1);
                handle_alarm_deletion();
                // 루프 시작 시 다시 숨겨짐
            } else {
                break; // d가 아닌 다른 키를 누르면 루프 종료
            }
        }
    }

    system("cls");
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    set_console_cursor_visibility(1); // 프로그램 종료 시 커서 원상 복구
    return 0;
}
```

<img width="1242" height="789" alt="image" src="https://github.com/user-attachments/assets/d4a68d17-ab43-4747-94d6-46edbcb3ab67" />

<img width="1239" height="785" alt="image" src="https://github.com/user-attachments/assets/4ef04c01-7931-42dc-a7e8-c8a429d4a02f" />

<img width="1241" height="777" alt="image" src="https://github.com/user-attachments/assets/2c1e45b5-1693-4008-967d-efef3d72aded" />

<img width="1238" height="780" alt="image" src="https://github.com/user-attachments/assets/2d2a3643-f09b-4924-8c6d-e2ec933c13e3" />




