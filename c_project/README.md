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


## 팩맨 게임 추가하기 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define MAX_ALARMS 10

// ===================================================================
// 전역 변수 및 시계 숫자 데이터
// ===================================================================

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

// ===================================================================
// 유틸리티 및 시계 관련 함수
// ===================================================================

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

void draw_frame() {
    for (int x = 1; x <= 80; x++) { gotoxy(x, 1); printf("═"); gotoxy(x, 11); printf("═"); }
    for (int y = 2; y <= 10; y++) { gotoxy(1, y); printf("║"); gotoxy(80, y); printf("║"); }
    gotoxy(1, 1); printf("╔"); gotoxy(80, 1); printf("╗"); gotoxy(1, 11); printf("╚"); gotoxy(80, 11); printf("╝");
}

long time_to_number(void) {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}

void digit_print(int dim[], int row) {
    set_text_color(10);
    for (int i = row * 4; i <= row * 4 + 3; i++) { printf(dim[i] ? "█" : " "); }
    printf("   ");
    set_text_color(15);
}

void print_time_digits(int time_number) {
    int digits[6];
    for (int i = 5; i >= 0; i--) { digits[i] = time_number % 10; time_number /= 10; }
    int start_x = 5, start_y = 3, spacing = 8;
    for (int row = 0; row < 5; row++) {
        gotoxy(start_x, start_y + row);
        for (int i = 0; i < 6; i++) {
            switch (digits[i]) {
                case 0: digit_print(zero, row); break; case 1: digit_print(one, row); break;
                case 2: digit_print(two, row); break; case 3: digit_print(three, row); break;
                case 4: digit_print(four, row); break; case 5: digit_print(five, row); break;
                case 6: digit_print(six, row); break; case 7: digit_print(seven, row); break;
                case 8: digit_print(eight, row); break; case 9: digit_print(nine, row); break;
            }
            if (i == 1 || i == 3) printf("   ");
        }
    }
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■"); gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■"); gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm *d = localtime(&current);
    char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 9); printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void print_alarm_list() {
    gotoxy(5, 13); printf("╔════════════════════════════════════╗");
    if (alarm_count == 0) {
        gotoxy(5, 14); printf("║ 설정된 알람이 없습니다.            ║");
    } else {
        for (int i = 0; i < alarm_count; i++) {
            gotoxy(5, 14 + i); printf("║ 알람 %d: %02d:%02d   [삭제:%d]           ║", i + 1, alarm_hours[i], alarm_minutes[i], i + 1);
        }
    }
    gotoxy(5, 14 + (alarm_count == 0 ? 1 : alarm_count)); printf("╚════════════════════════════════════╝");
}

void sort_alarms() { for (int i = 0; i < alarm_count - 1; i++) for (int j = i + 1; j < alarm_count; j++) if (alarm_hours[i] > alarm_hours[j] || (alarm_hours[i] == alarm_hours[j] && alarm_minutes[i] > alarm_minutes[j])) { int temp_h = alarm_hours[i]; int temp_m = alarm_minutes[i]; alarm_hours[i] = alarm_hours[j]; alarm_minutes[i] = alarm_minutes[j]; alarm_hours[j] = temp_h; alarm_minutes[j] = temp_m; } }
void delete_alarm(int index) { if (index < 0 || index >= alarm_count) return; for (int i = index; i < alarm_count - 1; i++) { alarm_hours[i] = alarm_hours[i + 1]; alarm_minutes[i] = alarm_minutes[i + 1]; } alarm_count--; }

void handle_alarm_deletion() {
    char input_buffer[20];
    int del;
    gotoxy(5, 16 + (alarm_count == 0 ? 1 : alarm_count));
    printf("삭제할 알람 번호를 입력하세요 (0 입력 시 취소): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    sscanf(input_buffer, "%d", &del);
    if (del > 0 && del <= alarm_count) {
        delete_alarm(del - 1);
        sort_alarms();
        gotoxy(5, 17 + (alarm_count == 0 ? 1 : alarm_count));
        printf("알람 %d이(가) 삭제되었습니다. 잠시 후 돌아갑니다.", del);
        Sleep(1500);
    }
}

void check_alarm(int hour, int minute) {
    static int triggered[MAX_ALARMS] = {0};
    for (int i = 0; i < alarm_count; i++) {
        if (hour == alarm_hours[i] && minute == alarm_minutes[i] && !triggered[i]) {
            for (int j = 0; j < 3; j++) { Beep(1000, 300); Sleep(200); }
            triggered[i] = 1;
            gotoxy(40, 10); printf("🔔 알람 %d 시간입니다! 🔔", i + 1);
        } else if (hour != alarm_hours[i] || minute != alarm_minutes[i]) {
            triggered[i] = 0;
        }
    }
}

// ===================================================================
// 팩맨 게임 함수 (몬스터 추가 및 최종 수정)
// ===================================================================

#define MAP_WIDTH 38
#define MAP_HEIGHT 18

char pacman_map[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "#####################################", "#...................................#", "#.#####.#########.###.#########.###.#", "#.#...#.#.......#.#.#.#.......#.#...#", "#.#...#.#.#####.#.#.#.#.#####.#.#...#", "#.#...#.#.#...#.#...#.#.#...#.#.#...#", "#.#...#.#.#...#.#.#.#.#.#...#.#.#...#", "#.#####.#####.###.###.#####.#.#####.", "#...................................#", "#.#####.###.#########.###.#########", "#.#...#.#.#.#.......#.#.#.#.........#", "#.#...#.#.#.#.#####.#.#.#.#.#######.#", "#.#...#...#.#.#...#.#...#.#.#.....#.#", "#.#...#####.#.#...#.#.###.#.#.###.#.#", "#.#.....#...#.....#.#...#...#...#...#", "#.#######.#########.###.#####.###.#", "#...................................#", "#####################################"
};

void play_pacman_game() {
    int player_x = 1, player_y = 1;
    int score = 0, total_dots = 0;

    // --- 몬스터(고스트) 변수 ---
    int ghost1_x = MAP_WIDTH / 2 - 2, ghost1_y = MAP_HEIGHT / 2 - 1;
    int ghost2_x = MAP_WIDTH / 2 + 2, ghost2_y = MAP_HEIGHT / 2 - 1;
    int ghost_move_counter = 0; // 고스트 이동 속도 조절용

    char current_map[MAP_HEIGHT][MAP_WIDTH + 1];
    for(int y=0; y<MAP_HEIGHT; ++y) {
        strcpy(current_map[y], pacman_map[y]);
        for(int x=0; x<MAP_WIDTH; ++x) {
            if(current_map[y][x] == '.') total_dots++;
        }
    }
    
    char pacman_anim_chars[2] = {'C', 'c'};
    int anim_frame = 0;

    // --- 최초 맵 그리기 ---
    system("cls");
    set_console_cursor_visibility(0);

    for (int y = 0; y < MAP_HEIGHT; y++) {
        gotoxy(0, y);
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (current_map[y][x] == '#') { set_text_color(9); printf("█"); }
            else if (current_map[y][x] == '.') { set_text_color(15); printf("●"); }
            else { printf(" "); }
        }
    }
    gotoxy(0, MAP_HEIGHT + 1);
    set_text_color(15);
    printf("SCORE: %d / %d\n", score, total_dots);
    printf("이동: ←↑↓→ (방향키) | 나가기: Q");

    // --- 게임 루프 시작 ---
    while (1) {
        int prev_x = player_x, prev_y = player_y;
        int prev_g1_x = ghost1_x, prev_g1_y = ghost1_y;
        int prev_g2_x = ghost2_x, prev_g2_y = ghost2_y;

        // --- 플레이어 이동 처리 ---
        if (kbhit()) {
            int key = getch();
            if (key == 224) {
                key = getch();
                switch (key) {
                    case 75: if (current_map[player_y][player_x - 1] != '#') player_x--; break;
                    case 77: if (current_map[player_y][player_x + 1] != '#') player_x++; break;
                    case 72: if (current_map[player_y - 1][player_x] != '#') player_y--; break;
                    case 80: if (current_map[player_y + 1][player_x] != '#') player_y++; break;
                }
            } else {
                if (key == 'q' || key == 'Q') break;
            }
        }

        // --- 고스트 이동 처리 (팩맨이 2번 움직일 때 1번 움직임) ---
        ghost_move_counter++;
        if (ghost_move_counter % 2 == 0) {
            // 고스트 1 (빨강)
            if (ghost1_x < player_x && current_map[ghost1_y][ghost1_x + 1] != '#') ghost1_x++;
            else if (ghost1_x > player_x && current_map[ghost1_y][ghost1_x - 1] != '#') ghost1_x--;
            else if (ghost1_y < player_y && current_map[ghost1_y + 1][ghost1_x] != '#') ghost1_y++;
            else if (ghost1_y > player_y && current_map[ghost1_y - 1][ghost1_x] != '#') ghost1_y--;

            // 고스트 2 (초록)
            if (ghost2_y < player_y && current_map[ghost2_y + 1][ghost2_x] != '#') ghost2_y++;
            else if (ghost2_y > player_y && current_map[ghost2_y - 1][ghost2_x] != '#') ghost2_y--;
            else if (ghost2_x < player_x && current_map[ghost2_y][ghost2_x + 1] != '#') ghost2_x++;
            else if (ghost2_x > player_x && current_map[ghost2_y][ghost2_x - 1] != '#') ghost2_x--;
        }

        // --- 잔상 제거 및 화면 업데이트 ---
        // 이전 플레이어 위치 지우기
        if (prev_x != player_x || prev_y != player_y) {
            gotoxy(prev_x, prev_y);
            printf(" ");
        }
        // 이전 고스트 위치 지우기
        gotoxy(prev_g1_x, prev_g1_y); printf(" ");
        gotoxy(prev_g2_x, prev_g2_y); printf(" ");

        // --- 새로 그리기 ---
        // 고스트 1 그리기
        gotoxy(ghost1_x, ghost1_y); set_text_color(12); printf("M");
        // 고스트 2 그리기
        gotoxy(ghost2_x, ghost2_y); set_text_color(10); printf("W");

        // 점 먹기 및 점수판 업데이트
        if (current_map[player_y][player_x] == '.') {
            current_map[player_y][player_x] = ' '; score++; Beep(600, 50);
            gotoxy(7, MAP_HEIGHT + 1); set_text_color(15); printf("%d", score);
        }

        // 플레이어 그리기
        gotoxy(player_x, player_y); set_text_color(14); printf("%c", pacman_anim_chars[anim_frame % 2]);
        anim_frame++;

        // --- 충돌 검사 (게임 오버 조건) ---
        if ((player_x == ghost1_x && player_y == ghost1_y) || (player_x == ghost2_x && player_y == ghost2_y)) {
            gotoxy((MAP_WIDTH / 2) - 5, MAP_HEIGHT / 2); set_text_color(12);
            printf("GAME OVER");
            Beep(150, 500);
            Sleep(2000);
            break;
        }

        // --- 승리 조건 ---
        if (score >= total_dots) {
            gotoxy((MAP_WIDTH / 2) - 10, MAP_HEIGHT / 2); set_text_color(10);
            printf("YOU WIN! CONGRATULATIONS!");
            Beep(523, 200); Beep(659, 200); Beep(783, 200);
            Sleep(3000);
            break;
        }
        
        Sleep(80); // 게임 전체 속도 조절
    }
}


// ===================================================================
// main 함수 (최종 안정화 버전)
// ===================================================================

int main(void) {
    system("chcp 65001 > nul");
    system("title 디지털 시계 & 팩맨");
    system("mode con: cols=82 lines=25");
    system("color 0A");

    printf("디지털 시계 프로그램\n\n");
    printf("알람 시간을 입력하세요 (24시간제). 모두 입력했다면 시에 -1을 입력하세요.\n");

    while (alarm_count < MAX_ALARMS) {
        int hour = 0, minute = 0;
        char input_buffer[20];

        printf("시: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) break;
        if (sscanf(input_buffer, "%d", &hour) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }

        if (hour == -1) break;
        if (hour < 0 || hour > 23) {
            printf("잘못된 시간입니다. (0-23 사이 입력)\n");
            continue;
        }

        printf("분: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) break;
        if (sscanf(input_buffer, "%d", &minute) != 1) {
            printf("숫자만 입력해주세요.\n");
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

    printf("\n알람 설정이 완료되었습니다. 아무 키나 누르면 시계를 시작합니다.\n");
    getch();

    while (1) {
        system("cls");
        set_console_cursor_visibility(0);
        
        draw_frame();
        long time_number = time_to_number();
        print_time_digits(time_number);
        print_date_and_weekday();
        print_alarm_list();
        
        time_t current = time(NULL);
        struct tm *d = localtime(&current);
        check_alarm(d->tm_hour, d->tm_min);

        gotoxy(5, 12);
        printf("d: 알람 삭제 | g: 팩맨 게임 시작 | Any other key: 종료");
        
        Sleep(1000); 

        if (kbhit()) {
            char ch = getch();
            if (ch == 'd' || ch == 'D') {
                set_console_cursor_visibility(1);
                handle_alarm_deletion();
            } else if (ch == 'g' || ch == 'G') {
                play_pacman_game();
            } else {
                if (ch == -32 || ch == 0 || ch == 224) {
                    getch(); 
                    continue;
                }
                break;
            }
        }
    }

    system("cls");
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    set_console_cursor_visibility(1);
    return 0;
}
```

<img width="1729" height="927" alt="image" src="https://github.com/user-attachments/assets/a413d7d6-446b-4031-845a-4958115ef3e0" />


<img width="1381" height="814" alt="image" src="https://github.com/user-attachments/assets/19987773-a31c-4961-805d-c3adfa088486" />


## 디자인 정리 
- 인트로(사진) 만들기
- 시간 설정 화면 메인 화면에 넣기

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// GDI+ 사용을 위한 헤더 및 라이브러리 링크
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "gdi32.lib") 

// 네임스페이스 사용 (GDI+ 클래스를 위함)
using namespace Gdiplus;

// 색상 상수 정의
#define COLOR_DEFAULT       15 // 기본 흰색
#define COLOR_FRAME_BORDER  15 // 프레임 테두리
#define COLOR_CLOCK_DIGIT   10 // 시계 숫자 (밝은 녹색)
#define COLOR_CLOCK_COLON   10 // 시계 콜론
#define COLOR_ANIMATION     14 // 애니메이션 캐릭터 (밝은 노란색)
#define COLOR_PACMAN_WALL   9  // 팩맨 벽 (밝은 파란색)
#define COLOR_PACMAN_GHOST1 12 // 팩맨 유령1 (밝은 빨간색)
#define COLOR_PACMAN_GHOST2 10 // 팩맨 유령2 (밝은 녹색)
#define COLOR_PACMAN        14 // 팩맨 캐릭터
#define COLOR_ERROR         12 // 오류 메시지 (밝은 빨간색)
#define COLOR_SUCCESS       10 // 성공 메시지 (밝은 녹색)

#define MAX_ALARMS 10
#define MAP_WIDTH 38
#define MAP_HEIGHT 18

// 알람 데이터 구조화
struct Alarm {
    int hour;
    int minute;
};

// 전역 변수
Image* g_pIntroImage = nullptr;
struct Alarm alarms[MAX_ALARMS];
int alarm_count = 0;

// 시계 숫자 데이터
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

char pacman_map[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "#####################################",
    "#...................................#",
    "#.#####.#########.###.#########.###.#",
    "#.....#.#.......#.#.#.#.......#.#...#",
    "#.#...#.#.#####.#.#.#.#.#####.#.#...#",
    "#.#...#.#.#...#.#...#.#.#...#.#.#...#",
    "#.#...#.#.#...#.#.#.#.#.#...#.#.#...#",
    "#.#####.#####.###.###.#####.#.#####.",
    "#...................................#",
    "#.#####.###.#########.###.#########",
    "#.#...#.#.#.#.......#.#.#.#.........#",
    "#.#...#.#.#.#.#####.#.#.#.#.#######.#",
    "#.#...#...#.#.#...#.#...#.#.#.....#.#",
    "#.#...#####.#.#...#.#.###.#.#.###.#.#",
    "#.#.....#...#.....#.#...#...#...#...#",
    "#.##.####.#########.###.#####.###.#",
    "#...................................#",
    "#####################################"
};

// 유틸리티 함수들
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

long time_to_number(void) {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}

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
    set_text_color(COLOR_CLOCK_COLON);
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
    set_text_color(COLOR_DEFAULT);
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    const char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 9);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void clear_alarm_list_area() {
    for (int i = 0; i < MAX_ALARMS + 4; ++i) {
        gotoxy(5, 13 + i);
        printf("                                                                        ");
    }
}

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
            printf("║ 알람 %d: %02d:%02d  [삭제:%d]            ║", i + 1, alarms[i].hour, alarms[i].minute, i + 1);
        }
    }
    gotoxy(5, 14 + (alarm_count == 0 ? 1 : alarm_count));
    printf("╚════════════════════════════════════╝");
}

void sort_alarms() {
    for (int i = 0; i < alarm_count - 1; i++) {
        for (int j = i + 1; j < alarm_count; j++) {
            if (alarms[i].hour > alarms[j].hour || (alarms[i].hour == alarms[j].hour && alarms[i].minute > alarms[j].minute)) {
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

void handle_alarm_deletion() {
    char input_buffer[20];
    int del;
    gotoxy(5, 16 + (alarm_count == 0 ? 1 : alarm_count));
    printf("삭제할 알람 번호를 입력하세요 (0 입력 시 취소): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    sscanf(input_buffer, "%d", &del);

    if (del > 0 && del <= alarm_count) {
        delete_alarm(del - 1);
        sort_alarms();
        gotoxy(5, 17 + (alarm_count == 0 ? 1 : alarm_count));
        printf("알람 %d이(가) 삭제되었습니다. 잠시 후 돌아갑니다.", del);
        Sleep(1500);
    }
}

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
            printf("                          ");
        }
    }
}

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

void handle_alarm_addition() {
    system("cls");
    set_console_cursor_visibility(1);
    printf("알람 추가/설정 (최대 %d개)\n", MAX_ALARMS);
    printf("알람 시간을 입력하세요 (24시간제). 모두 입력했다면 시에 -1을 입력하세요.\n");
    while (alarm_count < MAX_ALARMS) {
        int hour = 0, minute = 0;
        char input_buffer[20];
        printf("\n현재 알람 개수: %d\n", alarm_count);
        printf("시: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || strlen(input_buffer) <= 1) continue;
        if (sscanf(input_buffer, "%d", &hour) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }
        if (hour == -1) break;
        if (hour < 0 || hour > 23) {
            printf("잘못된 시간입니다. (0-23 사이 입력)\n");
            continue;
        }
        printf("분: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || strlen(input_buffer) <= 1) continue;
        if (sscanf(input_buffer, "%d", &minute) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }
        if (minute < 0 || minute > 59) {
            printf("잘못된 분입니다. (0-59 사이 입력)\n");
            continue;
        }
        alarms[alarm_count].hour = hour;
        alarms[alarm_count].minute = minute;
        alarm_count++;
        sort_alarms();
        printf(" -> %02d:%02d 알람이 추가되었습니다.\n", hour, minute);
    }
    printf("\n알람 설정이 완료되었습니다. 아무 키나 누르면 시계 화면으로 돌아갑니다.\n");
    getch();
}

void play_pacman_game() {
    system("cls");
    set_console_cursor_visibility(0);

    int player_x = 1, player_y = 1;
    int score = 0, total_dots = 0;
    int ghost1_x = MAP_WIDTH / 2 - 2, ghost1_y = MAP_HEIGHT / 2 - 1;
    int ghost2_x = MAP_WIDTH / 2 + 2, ghost2_y = MAP_HEIGHT / 2 - 1;
    int ghost_move_counter = 0;
    char current_map[MAP_HEIGHT][MAP_WIDTH + 1];

    for(int y=0; y<MAP_HEIGHT; ++y) {
        strcpy(current_map[y], pacman_map[y]);
        for(int x=0; x<MAP_WIDTH; ++x) {
            if(current_map[y][x] == '.') total_dots++;
        }
    }

    char pacman_anim_chars[2] = {'C', 'c'};
    int anim_frame = 0;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        gotoxy(0, y);
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (current_map[y][x] == '#') {
                set_text_color(COLOR_PACMAN_WALL);
                printf("█");
            } else if (current_map[y][x] == '.') {
                set_text_color(COLOR_DEFAULT);
                printf("·");
            } else {
                printf(" ");
            }
        }
    }

    gotoxy(0, MAP_HEIGHT + 1);
    set_text_color(COLOR_DEFAULT);
    printf("SCORE: %d / %d\n", score, total_dots);
    printf("이동: ←↑↓→ (방향키) | 나가기: Q");

    while (1) {
        int prev_x = player_x, prev_y = player_y;
        int prev_g1_x = ghost1_x, prev_g1_y = ghost1_y;
        int prev_g2_x = ghost2_x, prev_g2_y = ghost2_y;

        if (kbhit()) {
            int key = getch();
            if (key == 224) {
                key = getch();
                switch (key) {
                    case 75: if (current_map[player_y][player_x - 1] != '#') player_x--; break;
                    case 77: if (current_map[player_y][player_x + 1] != '#') player_x++; break;
                    case 72: if (current_map[player_y - 1][player_x] != '#') player_y--; break;
                    case 80: if (current_map[player_y + 1][player_x] != '#') player_y++; break;
                }
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        }

        ghost_move_counter++;
        if (ghost_move_counter % 2 == 0) {
            if (ghost1_x < player_x && current_map[ghost1_y][ghost1_x + 1] != '#') ghost1_x++;
            else if (ghost1_x > player_x && current_map[ghost1_y][ghost1_x - 1] != '#') ghost1_x--;
            else if (ghost1_y < player_y && current_map[ghost1_y + 1][ghost1_x] != '#') ghost1_y++;
            else if (ghost1_y > player_y && current_map[ghost1_y - 1][ghost1_x] != '#') ghost1_y--;

            if (ghost2_y < player_y && current_map[ghost2_y + 1][ghost2_x] != '#') ghost2_y++;
            else if (ghost2_y > player_y && current_map[ghost2_y - 1][ghost2_x] != '#') ghost2_y--;
            else if (ghost2_x < player_x && current_map[ghost2_y][ghost2_x + 1] != '#') ghost2_x++;
            else if (ghost2_x > player_x && current_map[ghost2_y][ghost2_x - 1] != '#') ghost2_x--;
        }
        
        gotoxy(prev_x, prev_y); printf(" ");
        gotoxy(prev_g1_x, prev_g1_y); printf(" ");
        gotoxy(prev_g2_x, prev_g2_y); printf(" ");

        gotoxy(ghost1_x, ghost1_y); set_text_color(COLOR_PACMAN_GHOST1); printf("M");
        gotoxy(ghost2_x, ghost2_y); set_text_color(COLOR_PACMAN_GHOST2); printf("W");
        
        if (current_map[player_y][player_x] == '.') {
            current_map[player_y][player_x] = ' ';
            score++;
            Beep(600, 50);
            gotoxy(7, MAP_HEIGHT + 1);
            set_text_color(COLOR_DEFAULT);
            printf("%d", score);
        }

        gotoxy(player_x, player_y);
        set_text_color(COLOR_PACMAN);
        printf("%c", pacman_anim_chars[anim_frame % 2]);
        anim_frame++;

        if ((player_x == ghost1_x && player_y == ghost1_y) || (player_x == ghost2_x && player_y == ghost2_y)) {
            gotoxy((MAP_WIDTH / 2) - 5, MAP_HEIGHT / 2);
            set_text_color(COLOR_ERROR);
            printf("GAME OVER");
            Beep(150, 500);
            Sleep(2000);
            break;
        }

        if (score >= total_dots) {
            gotoxy((MAP_WIDTH / 2) - 10, MAP_HEIGHT / 2);
            set_text_color(COLOR_SUCCESS);
            printf("YOU WIN! CONGRATULATIONS!");
            Beep(523, 200); Beep(659, 200); Beep(783, 200);
            Sleep(3000);
            break;
        }
        Sleep(80);
    }
}

// 윈도우 프로시저
// 윈도우 프로시저
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
        
        // 💡 이 부분을 변경합니다.
        case WM_KEYDOWN:
        case WM_LBUTTONDOWN:
        case WM_CLOSE:
            DestroyWindow(hwnd); // PostQuitMessage(0) 대신 DestroyWindow(hwnd) 호출
            return 0;
            
        case WM_DESTROY:
            PostQuitMessage(0); // 이 부분은 그대로 둡니다.
            return 0;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void show_intro_with_image() {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    g_pIntroImage = new Image(L"in2.bmp");
    
    if (g_pIntroImage->GetLastStatus() != Ok) {
        system("cls");
        set_text_color(COLOR_ERROR);
        printf("\n=== 이미지 로드 실패 ===\n\n");
        printf("오류 코드: %d\n\n", g_pIntroImage->GetLastStatus());
        
        char cwd[1024];
        if (GetCurrentDirectoryA(sizeof(cwd), cwd)) {
            printf("현재 작업 디렉토리: %s\n\n", cwd);
        }
        
        printf("확인사항:\n");
        printf("1. 위 디렉토리에 in2.bmp 파일이 있는가?\n");
        printf("2. 파일 이름이 정확한가? (대소문자 구분)\n");
        printf("3. 파일이 손상되지 않았는가?\n\n");
        printf("아무 키나 눌러 계속...\n");
        set_text_color(COLOR_DEFAULT);
        
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    WNDCLASSW wc = {0};
    wc.lpfnWndProc = IntroWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"IntroImageWindow";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    
    if (!RegisterClassW(&wc)) {
        printf("윈도우 클래스 등록 실패\n");
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int windowWidth = 800;
    int windowHeight = 600;
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    HWND hwnd = CreateWindowExW(
        0,
        L"IntroImageWindow",
        L"시작 화면 - 아무 키나 누르세요",
        WS_OVERLAPPEDWINDOW,
        x, y, windowWidth, windowHeight,
        NULL, NULL, GetModuleHandle(NULL), NULL
    );

    if (!hwnd) {
        printf("윈도우 생성 실패\n");
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnregisterClassW(L"IntroImageWindow", GetModuleHandle(NULL));
    delete g_pIntroImage;
    g_pIntroImage = nullptr;
    GdiplusShutdown(gdiplusToken);
}

void redraw_main_screen() {
    system("cls");
    draw_frame();
    print_date_and_weekday();
    print_alarm_list();
    gotoxy(5, 12);
    printf("p: 알람 설정 | d: 알람 삭제 | g: 팩맨 게임 시작 | Any other key: 종료");
}

int main(void) {
    system("chcp 65001 > nul");
    system("title 디지털 시계 & 팩맨");
    system("mode con: cols=82 lines=30");

    show_intro_with_image();

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

        if (kbhit()) {
            char ch = getch();
            if (ch == 'd' || ch == 'D') {
                set_console_cursor_visibility(1);
                handle_alarm_deletion();
                needs_redraw = true;
            } else if (ch == 'g' || ch == 'G') {
                play_pacman_game();
                needs_redraw = true;
            } else if (ch == 'p' || ch == 'P') {
                handle_alarm_addition();
                needs_redraw = true;
            } else {
                 if (ch == -32 || ch == 0 || ch == 224) {
                    getch(); 
                    continue;
                 }
                break;
            }
            set_console_cursor_visibility(0);
        }
        
        Sleep(100);
    }

    system("cls");
    set_text_color(COLOR_DEFAULT);
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    set_console_cursor_visibility(1);
    return 0;
}
```

<img width="1728" height="918" alt="image" src="https://github.com/user-attachments/assets/be016a29-3767-421a-9c8c-02297bb71321" />

tasks.json (수정)

```
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe build active file",
            "command": "C:\\msys64\\ucrt64\\bin\\g++.exe", // C++ 컴파일러 g++.exe로 변경
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-lgdiplus", // GDI+ 라이브러리 링크 옵션
                "-lgdi32",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true // 이 작업을 기본 빌드로 설정
            },
            "detail": "compiler: C:\\msys64\\ucrt64\\bin\\g++.exe"
        }
    ]
}
```

## 팩맨 2
<img width="810" height="625" alt="image" src="https://github.com/user-attachments/assets/ffb74927-2b02-44a4-b27a-b2dc8ed51b8d" />

- 팩맨 게임이 다른 컴퓨터에서 깨지는 현상 발견
- 유령 캐릭터가 .을 먹는 문제 해결

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// GDI+ 사용을 위한 헤더 및 라이브러리 링크
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "gdi32.lib") 

// 네임스페이스 사용 (GDI+ 클래스를 위함)
using namespace Gdiplus;

// 색상 상수 정의
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

#define MAX_ALARMS 10
#define MAP_WIDTH 38
#define MAP_HEIGHT 18

// 알람 데이터 구조화
struct Alarm {
    int hour;
    int minute;
};

// 전역 변수
Image* g_pIntroImage = nullptr;
struct Alarm alarms[MAX_ALARMS];
int alarm_count = 0;

// 시계 숫자 데이터
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

char pacman_map[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "#####################################",
    "#...................................#",
    "#.#####.###..####.###.#########.###.#",
    "#.....#.#.......#.#.#.#.......#.#...#",
    "#.#...#.#.#####.#.#.#.#.#####.#.#...#",
    "#.#...#.#.#...#.#...#.#.#...#.#.#...#",
    "#.#...#.#.#...#.#.#.#.#.#...#.#.#...#",
    "#.#####.#####.###.###.#####.#.#####.",
    "#...................................#",
    "#.#####.###.#########.###.#########",
    "#.#...#.#.#.#.......#.#.#.#.........#",
    "#.#...#.#.#.#.#####.#.#.#.#.#######.#",
    "#.#...#...#.#.#...#.#...#.#.#.....#.#",
    "#.#...#####.#.#...#.#.###.#.#.###.#.#",
    "#.#.....#...#.....#.#...#...#...#...#",
    "#.##.####.#########.###.#####.###.#",
    "#...................................#",
    "#####################################"
};

// 유틸리티 함수들
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

long time_to_number(void) {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}

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
    set_text_color(COLOR_CLOCK_COLON);
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
    set_text_color(COLOR_DEFAULT);
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    const char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 9);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void clear_alarm_list_area() {
    for (int i = 0; i < MAX_ALARMS + 4; ++i) {
        gotoxy(5, 13 + i);
        printf("                                                                                ");
    }
}

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
            printf("║ 알람 %d: %02d:%02d  [삭제:%d]            ║", i + 1, alarms[i].hour, alarms[i].minute, i + 1);
        }
    }
    gotoxy(5, 14 + (alarm_count == 0 ? 1 : alarm_count));
    printf("╚════════════════════════════════════╝");
}

void sort_alarms() {
    for (int i = 0; i < alarm_count - 1; i++) {
        for (int j = i + 1; j < alarm_count; j++) {
            if (alarms[i].hour > alarms[j].hour || (alarms[i].hour == alarms[j].hour && alarms[i].minute > alarms[j].minute)) {
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

void handle_alarm_deletion() {
    char input_buffer[20];
    int del;
    gotoxy(5, 16 + (alarm_count == 0 ? 1 : alarm_count));
    printf("삭제할 알람 번호를 입력하세요 (0 입력 시 취소): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    sscanf(input_buffer, "%d", &del);

    if (del > 0 && del <= alarm_count) {
        delete_alarm(del - 1);
        sort_alarms();
        gotoxy(5, 17 + (alarm_count == 0 ? 1 : alarm_count));
        printf("알람 %d이(가) 삭제되었습니다. 잠시 후 돌아갑니다.", del);
        Sleep(1500);
    }
}

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

void handle_alarm_addition() {
    system("cls");
    set_console_cursor_visibility(1);
    printf("알람 추가/설정 (최대 %d개)\n", MAX_ALARMS);
    printf("알람 시간을 입력하세요 (24시간제). 모두 입력했다면 시에 -1을 입력하세요.\n");
    while (alarm_count < MAX_ALARMS) {
        int hour = 0, minute = 0;
        char input_buffer[20];
        printf("\n현재 알람 개수: %d\n", alarm_count);
        printf("시: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || strlen(input_buffer) <= 1) continue;
        if (sscanf(input_buffer, "%d", &hour) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }
        if (hour == -1) break;
        if (hour < 0 || hour > 23) {
            printf("잘못된 시간입니다. (0-23 사이 입력)\n");
            continue;
        }
        printf("분: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || strlen(input_buffer) <= 1) continue;
        if (sscanf(input_buffer, "%d", &minute) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }
        if (minute < 0 || minute > 59) {
            printf("잘못된 분입니다. (0-59 사이 입력)\n");
            continue;
        }
        alarms[alarm_count].hour = hour;
        alarms[alarm_count].minute = minute;
        alarm_count++;
        sort_alarms();
        printf(" -> %02d:%02d 알람이 추가되었습니다.\n", hour, minute);
    }
    printf("\n알람 설정이 완료되었습니다. 아무 키나 누르면 시계 화면으로 돌아갑니다.\n");
    getch();
}

// ================== [수정된 부분] ==================
void play_pacman_game() {
    system("cls");
    set_console_cursor_visibility(0);

    int player_x = 1, player_y = 1;
    int score = 0, total_dots = 0;
    int ghost1_x = MAP_WIDTH / 2 - 2, ghost1_y = MAP_HEIGHT / 2 - 1;
    int ghost2_x = MAP_WIDTH / 2 + 2, ghost2_y = MAP_HEIGHT / 2 - 1;
    int ghost_move_counter = 0;
    char current_map[MAP_HEIGHT][MAP_WIDTH + 1];

    for(int y=0; y<MAP_HEIGHT; ++y) {
        strcpy(current_map[y], pacman_map[y]);
        for(int x=0; x<MAP_WIDTH; ++x) {
            if(current_map[y][x] == '.') total_dots++;
        }
    }

    char pacman_anim_chars[2] = {'C', 'c'};
    int anim_frame = 0;

    // 맵 그리기
    for (int y = 0; y < MAP_HEIGHT; y++) {
        gotoxy(0, y);
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (current_map[y][x] == '#') {
                set_text_color(COLOR_PACMAN_WALL);
                printf("#"); // 👈 변경점: 깨짐 방지를 위해 '#' 문자로 출력
            } else if (current_map[y][x] == '.') {
                set_text_color(COLOR_DEFAULT);
                printf("."); // 👈 변경점: 깨짐 방지를 위해 '.' 문자로 출력
            } else {
                printf(" ");
            }
        }
    }

    // 점수 및 안내문 출력
    gotoxy(0, MAP_HEIGHT + 1);
    set_text_color(COLOR_DEFAULT);
    printf("SCORE: %d / %d\n", score, total_dots);
    printf("이동: ←↑↓→ (방향키) | 나가기: Q");

    while (1) {
        int prev_x = player_x, prev_y = player_y;
        int prev_g1_x = ghost1_x, prev_g1_y = ghost1_y;
        int prev_g2_x = ghost2_x, prev_g2_y = ghost2_y;

        // 키 입력 처리
        if (kbhit()) {
            int key = getch();
            if (key == 224) { // 방향키 입력
                key = getch();
                switch (key) {
                    case 75: if (current_map[player_y][player_x - 1] != '#') player_x--; break; // Left
                    case 77: if (current_map[player_y][player_x + 1] != '#') player_x++; break; // Right
                    case 72: if (current_map[player_y - 1][player_x] != '#') player_y--; break; // Up
                    case 80: if (current_map[player_y + 1][player_x] != '#') player_y++; break; // Down
                }
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        }

        // 유령 이동 로직
        ghost_move_counter++;
        if (ghost_move_counter % 2 == 0) { // 유령 이동 속도 조절
            // Ghost 1
            if (ghost1_x < player_x && current_map[ghost1_y][ghost1_x + 1] != '#') ghost1_x++;
            else if (ghost1_x > player_x && current_map[ghost1_y][ghost1_x - 1] != '#') ghost1_x--;
            else if (ghost1_y < player_y && current_map[ghost1_y + 1][ghost1_x] != '#') ghost1_y++;
            else if (ghost1_y > player_y && current_map[ghost1_y - 1][ghost1_x] != '#') ghost1_y--;

            // Ghost 2
            if (ghost2_y < player_y && current_map[ghost2_y + 1][ghost2_x] != '#') ghost2_y++;
            else if (ghost2_y > player_y && current_map[ghost2_y - 1][ghost2_x] != '#') ghost2_y--;
            else if (ghost2_x < player_x && current_map[ghost2_y][ghost2_x + 1] != '#') ghost2_x++;
            else if (ghost2_x > player_x && current_map[ghost2_y][ghost2_x - 1] != '#') ghost2_x--;
        }
        
        // 이전 위치 지우기
        gotoxy(prev_x, prev_y); printf(" ");
        
        // 유령의 이전 위치 지우기 (점이 있으면 점으로 복원)
        gotoxy(prev_g1_x, prev_g1_y);
        if (current_map[prev_g1_y][prev_g1_x] == '.') {
            set_text_color(COLOR_DEFAULT);
            printf(".");
        } else {
            printf(" ");
        }
        
        gotoxy(prev_g2_x, prev_g2_y);
        if (current_map[prev_g2_y][prev_g2_x] == '.') {
            set_text_color(COLOR_DEFAULT);
            printf(".");
        } else {
            printf(" ");
        }

        // 새 위치에 유령 그리기
        gotoxy(ghost1_x, ghost1_y); set_text_color(COLOR_PACMAN_GHOST1); printf("M");
        gotoxy(ghost2_x, ghost2_y); set_text_color(COLOR_PACMAN_GHOST2); printf("W");
        
        // 점 획득 처리
        if (current_map[player_y][player_x] == '.') {
            current_map[player_y][player_x] = ' ';
            score++;
            Beep(600, 50);
            gotoxy(7, MAP_HEIGHT + 1);
            set_text_color(COLOR_DEFAULT);
            printf("%d", score);
        }

        // 새 위치에 팩맨 그리기
        gotoxy(player_x, player_y);
        set_text_color(COLOR_PACMAN);
        printf("%c", pacman_anim_chars[anim_frame % 2]);
        anim_frame++;

        // 게임 오버 조건 확인
        if ((player_x == ghost1_x && player_y == ghost1_y) || (player_x == ghost2_x && player_y == ghost2_y)) {
            gotoxy((MAP_WIDTH / 2) - 5, MAP_HEIGHT / 2);
            set_text_color(COLOR_ERROR);
            printf("GAME OVER");
            Beep(150, 500);
            Sleep(2000);
            break;
        }

        // 게임 승리 조건 확인
        if (score >= total_dots) {
            gotoxy((MAP_WIDTH / 2) - 10, MAP_HEIGHT / 2);
            set_text_color(COLOR_SUCCESS);
            printf("YOU WIN! CONGRATULATIONS!");
            Beep(523, 200); Beep(659, 200); Beep(783, 200);
            Sleep(3000);
            break;
        }
        Sleep(80);
    }
}
// ======================================================

// 윈도우 프로시저
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
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void show_intro_with_image() {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    g_pIntroImage = new Image(L"in2.bmp");
    
    if (g_pIntroImage->GetLastStatus() != Ok) {
        system("cls");
        set_text_color(COLOR_ERROR);
        printf("\n=== 이미지 로드 실패 ===\n\n");
        printf("오류 코드: %d\n\n", g_pIntroImage->GetLastStatus());
        
        char cwd[1024];
        if (GetCurrentDirectoryA(sizeof(cwd), cwd)) {
            printf("현재 작업 디렉토리: %s\n\n", cwd);
        }
        
        printf("확인사항:\n");
        printf("1. 위 디렉토리에 in2.bmp 파일이 있는가?\n");
        printf("2. 파일 이름이 정확한가? (대소문자 구분)\n");
        printf("3. 파일이 손상되지 않았는가?\n\n");
        printf("아무 키나 눌러 계속...\n");
        set_text_color(COLOR_DEFAULT);
        
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    WNDCLASSW wc = {0};
    wc.lpfnWndProc = IntroWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"IntroImageWindow";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    
    if (!RegisterClassW(&wc)) {
        printf("윈도우 클래스 등록 실패\n");
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int windowWidth = 800;
    int windowHeight = 600;
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    HWND hwnd = CreateWindowExW(
        0,
        L"IntroImageWindow",
        L"시작 화면 - 아무 키나 누르세요",
        WS_OVERLAPPEDWINDOW,
        x, y, windowWidth, windowHeight,
        NULL, NULL, GetModuleHandle(NULL), NULL
    );

    if (!hwnd) {
        printf("윈도우 생성 실패\n");
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnregisterClassW(L"IntroImageWindow", GetModuleHandle(NULL));
    delete g_pIntroImage;
    g_pIntroImage = nullptr;
    GdiplusShutdown(gdiplusToken);
}

void redraw_main_screen() {
    system("cls");
    draw_frame();
    print_date_and_weekday();
    print_alarm_list();
    gotoxy(5, 12);
    printf("p: 알람 설정 | d: 알람 삭제 | g: 팩맨 게임 시작 | Any other key: 종료");
}

int main(void) {
    system("chcp 65001 > nul");
    system("title 디지털 시계 & 팩맨");
    system("mode con: cols=82 lines=30");

    show_intro_with_image();

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

        if (kbhit()) {
            char ch = getch();
            if (ch == 'd' || ch == 'D') {
                set_console_cursor_visibility(1);
                handle_alarm_deletion();
                needs_redraw = true;
            } else if (ch == 'g' || ch == 'G') {
                play_pacman_game();
                needs_redraw = true;
            } else if (ch == 'p' || ch == 'P') {
                handle_alarm_addition();
                needs_redraw = true;
            } else {
                if (ch == -32 || ch == 0 || ch == 224) { // Arrow key special codes
                    getch(); 
                    continue;
                }
                break;
            }
            set_console_cursor_visibility(0);
        }
        
        Sleep(100);
    }

    system("cls");
    set_text_color(COLOR_DEFAULT);
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    set_console_cursor_visibility(1);
    return 0;
}
```
<img width="818" height="640" alt="image" src="https://github.com/user-attachments/assets/64908d96-fed8-4d40-9e9b-04b7ecaa205b" />

## txt 파일 추가 
- 팩맨 게임 필드를 txt 파일에 저장한 다음 txt파일을 호출해서 구현 -> 이렇게 하는 이유는 확장 할 때 더 편하게 작업하기 위해서 

```
#include <iostream> // 👈 추가: C++ 스타일 입출력 (오류 메시지용)
#include <fstream>  // 👈 추가: 파일 입출력을 위한 헤더
#include <string>   // 👈 추가: std::string을 사용하기 위한 헤더
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// GDI+ 사용을 위한 헤더 및 라이브러리 링크
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "gdi32.lib") 

// 네임스페이스 사용 (GDI+ 클래스를 위함)
using namespace Gdiplus;

// 색상 상수 정의
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

#define MAX_ALARMS 10
#define MAP_WIDTH 38
#define MAP_HEIGHT 18

// 알람 데이터 구조화
struct Alarm {
    int hour;
    int minute;
};

// 전역 변수
Image* g_pIntroImage = nullptr;
struct Alarm alarms[MAX_ALARMS];
int alarm_count = 0;

// 시계 숫자 데이터
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

// 맵 데이터는 이제 파일에서 읽어옵니다.
char pacman_map[MAP_HEIGHT][MAP_WIDTH + 1]; // 👈 변경: 배열 선언만 하고 초기화는 하지 않음

// ================== [새로운 함수] ==================
// 파일에서 맵 데이터를 읽어오는 함수
bool load_map_from_file(const char* filename) {
    std::ifstream mapFile(filename);
    if (!mapFile.is_open()) {
        return false; // 파일 열기 실패
    }

    std::string line;
    int currentRow = 0;
    // 맵 높이만큼 한 줄씩 읽어서 pacman_map 배열에 저장
    while (currentRow < MAP_HEIGHT && std::getline(mapFile, line)) {
        strncpy(pacman_map[currentRow], line.c_str(), MAP_WIDTH);
        pacman_map[currentRow][MAP_WIDTH] = '\0'; // 문자열 끝을 위한 NULL 문자 추가
        currentRow++;
    }

    mapFile.close();

    // 맵의 세로 크기가 맞는지 확인
    if (currentRow != MAP_HEIGHT) {
        return false; // 파일의 줄 수가 맵 높이와 다름
    }

    return true;
}
// ======================================================

// 유틸리티 함수들
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

long time_to_number(void) {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    return d->tm_hour * 10000 + d->tm_min * 100 + d->tm_sec;
}

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
    set_text_color(COLOR_CLOCK_COLON);
    gotoxy(start_x + spacing * 2 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 2 - 2, start_y + 3); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 1); printf("■");
    gotoxy(start_x + spacing * 4 - 2, start_y + 3); printf("■");
    set_text_color(COLOR_DEFAULT);
}

void print_date_and_weekday() {
    time_t current = time(NULL);
    struct tm* d = localtime(&current);
    const char* weekdays[] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"};
    gotoxy(5, 9);
    printf("오늘 날짜: %04d-%02d-%02d (%s)", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday, weekdays[d->tm_wday]);
}

void clear_alarm_list_area() {
    for (int i = 0; i < MAX_ALARMS + 4; ++i) {
        gotoxy(5, 13 + i);
        printf("                                                                                ");
    }
}

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
            printf("║ 알람 %d: %02d:%02d  [삭제:%d]            ║", i + 1, alarms[i].hour, alarms[i].minute, i + 1);
        }
    }
    gotoxy(5, 14 + (alarm_count == 0 ? 1 : alarm_count));
    printf("╚════════════════════════════════════╝");
}

void sort_alarms() {
    for (int i = 0; i < alarm_count - 1; i++) {
        for (int j = i + 1; j < alarm_count; j++) {
            if (alarms[i].hour > alarms[j].hour || (alarms[i].hour == alarms[j].hour && alarms[i].minute > alarms[j].minute)) {
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

void handle_alarm_deletion() {
    char input_buffer[20];
    int del;
    gotoxy(5, 16 + (alarm_count == 0 ? 1 : alarm_count));
    printf("삭제할 알람 번호를 입력하세요 (0 입력 시 취소): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    sscanf(input_buffer, "%d", &del);

    if (del > 0 && del <= alarm_count) {
        delete_alarm(del - 1);
        sort_alarms();
        gotoxy(5, 17 + (alarm_count == 0 ? 1 : alarm_count));
        printf("알람 %d이(가) 삭제되었습니다. 잠시 후 돌아갑니다.", del);
        Sleep(1500);
    }
}

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

void handle_alarm_addition() {
    system("cls");
    set_console_cursor_visibility(1);
    printf("알람 추가/설정 (최대 %d개)\n", MAX_ALARMS);
    printf("알람 시간을 입력하세요 (24시간제). 모두 입력했다면 시에 -1을 입력하세요.\n");
    while (alarm_count < MAX_ALARMS) {
        int hour = 0, minute = 0;
        char input_buffer[20];
        printf("\n현재 알람 개수: %d\n", alarm_count);
        printf("시: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || strlen(input_buffer) <= 1) continue;
        if (sscanf(input_buffer, "%d", &hour) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }
        if (hour == -1) break;
        if (hour < 0 || hour > 23) {
            printf("잘못된 시간입니다. (0-23 사이 입력)\n");
            continue;
        }
        printf("분: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || strlen(input_buffer) <= 1) continue;
        if (sscanf(input_buffer, "%d", &minute) != 1) {
            printf("숫자만 입력해주세요.\n");
            continue;
        }
        if (minute < 0 || minute > 59) {
            printf("잘못된 분입니다. (0-59 사이 입력)\n");
            continue;
        }
        alarms[alarm_count].hour = hour;
        alarms[alarm_count].minute = minute;
        alarm_count++;
        sort_alarms();
        printf(" -> %02d:%02d 알람이 추가되었습니다.\n", hour, minute);
    }
    printf("\n알람 설정이 완료되었습니다. 아무 키나 누르면 시계 화면으로 돌아갑니다.\n");
    getch();
}

void play_pacman_game() {
    system("cls");
    set_console_cursor_visibility(0);

    int player_x = 1, player_y = 1;
    int score = 0, total_dots = 0;
    int ghost1_x = MAP_WIDTH / 2 - 2, ghost1_y = MAP_HEIGHT / 2 - 1;
    int ghost2_x = MAP_WIDTH / 2 + 2, ghost2_y = MAP_HEIGHT / 2 - 1;
    int ghost_move_counter = 0;
    char current_map[MAP_HEIGHT][MAP_WIDTH + 1];

    for(int y=0; y<MAP_HEIGHT; ++y) {
        strcpy(current_map[y], pacman_map[y]);
        for(int x=0; x<MAP_WIDTH; ++x) {
            if(current_map[y][x] == '.') total_dots++;
        }
    }

    char pacman_anim_chars[2] = {'C', 'c'};
    int anim_frame = 0;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        gotoxy(0, y);
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (current_map[y][x] == '#') {
                set_text_color(COLOR_PACMAN_WALL);
                printf("#");
            } else if (current_map[y][x] == '.') {
                set_text_color(COLOR_DEFAULT);
                printf(".");
            } else {
                printf(" ");
            }
        }
    }

    gotoxy(0, MAP_HEIGHT + 1);
    set_text_color(COLOR_DEFAULT);
    printf("SCORE: %d / %d\n", score, total_dots);
    printf("이동: ←↑↓→ (방향키) | 나가기: Q");

    while (1) {
        int prev_x = player_x, prev_y = player_y;
        int prev_g1_x = ghost1_x, prev_g1_y = ghost1_y;
        int prev_g2_x = ghost2_x, prev_g2_y = ghost2_y;

        if (kbhit()) {
            int key = getch();
            if (key == 224) {
                key = getch();
                switch (key) {
                    case 75: if (current_map[player_y][player_x - 1] != '#') player_x--; break;
                    case 77: if (current_map[player_y][player_x + 1] != '#') player_x++; break;
                    case 72: if (current_map[player_y - 1][player_x] != '#') player_y--; break;
                    case 80: if (current_map[player_y + 1][player_x] != '#') player_y++; break;
                }
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        }

        ghost_move_counter++;
        if (ghost_move_counter % 2 == 0) {
            if (ghost1_x < player_x && current_map[ghost1_y][ghost1_x + 1] != '#') ghost1_x++;
            else if (ghost1_x > player_x && current_map[ghost1_y][ghost1_x - 1] != '#') ghost1_x--;
            else if (ghost1_y < player_y && current_map[ghost1_y + 1][ghost1_x] != '#') ghost1_y++;
            else if (ghost1_y > player_y && current_map[ghost1_y - 1][ghost1_x] != '#') ghost1_y--;

            if (ghost2_y < player_y && current_map[ghost2_y + 1][ghost2_x] != '#') ghost2_y++;
            else if (ghost2_y > player_y && current_map[ghost2_y - 1][ghost2_x] != '#') ghost2_y--;
            else if (ghost2_x < player_x && current_map[ghost2_y][ghost2_x + 1] != '#') ghost2_x++;
            else if (ghost2_x > player_x && current_map[ghost2_y][ghost2_x - 1] != '#') ghost2_x--;
        }
        
        gotoxy(prev_x, prev_y); printf(" ");
        
        gotoxy(prev_g1_x, prev_g1_y);
        if (current_map[prev_g1_y][prev_g1_x] == '.') {
            set_text_color(COLOR_DEFAULT);
            printf(".");
        } else {
            printf(" ");
        }
        
        gotoxy(prev_g2_x, prev_g2_y);
        if (current_map[prev_g2_y][prev_g2_x] == '.') {
            set_text_color(COLOR_DEFAULT);
            printf(".");
        } else {
            printf(" ");
        }

        gotoxy(ghost1_x, ghost1_y); set_text_color(COLOR_PACMAN_GHOST1); printf("M");
        gotoxy(ghost2_x, ghost2_y); set_text_color(COLOR_PACMAN_GHOST2); printf("W");
        
        if (current_map[player_y][player_x] == '.') {
            current_map[player_y][player_x] = ' ';
            score++;
            Beep(600, 50);
            gotoxy(7, MAP_HEIGHT + 1);
            set_text_color(COLOR_DEFAULT);
            printf("%d", score);
        }

        gotoxy(player_x, player_y);
        set_text_color(COLOR_PACMAN);
        printf("%c", pacman_anim_chars[anim_frame % 2]);
        anim_frame++;

        if ((player_x == ghost1_x && player_y == ghost1_y) || (player_x == ghost2_x && player_y == ghost2_y)) {
            gotoxy((MAP_WIDTH / 2) - 5, MAP_HEIGHT / 2);
            set_text_color(COLOR_ERROR);
            printf("GAME OVER");
            Beep(150, 500);
            Sleep(2000);
            break;
        }

        if (score >= total_dots) {
            gotoxy((MAP_WIDTH / 2) - 10, MAP_HEIGHT / 2);
            set_text_color(COLOR_SUCCESS);
            printf("YOU WIN! CONGRATULATIONS!");
            Beep(523, 200); Beep(659, 200); Beep(783, 200);
            Sleep(3000);
            break;
        }
        Sleep(80);
    }
}

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
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void show_intro_with_image() {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    g_pIntroImage = new Image(L"in2.bmp");
    
    if (g_pIntroImage->GetLastStatus() != Ok) {
        system("cls");
        set_text_color(COLOR_ERROR);
        printf("\n=== 이미지 로드 실패 ===\n\n");
        printf("오류 코드: %d\n\n", g_pIntroImage->GetLastStatus());
        
        char cwd[1024];
        if (GetCurrentDirectoryA(sizeof(cwd), cwd)) {
            printf("현재 작업 디렉토리: %s\n\n", cwd);
        }
        
        printf("확인사항:\n");
        printf("1. 위 디렉토리에 in2.bmp 파일이 있는가?\n");
        printf("2. 파일 이름이 정확한가? (대소문자 구분)\n");
        printf("3. 파일이 손상되지 않았는가?\n\n");
        printf("아무 키나 눌러 계속...\n");
        set_text_color(COLOR_DEFAULT);
        
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    WNDCLASSW wc = {0};
    wc.lpfnWndProc = IntroWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"IntroImageWindow";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    
    if (!RegisterClassW(&wc)) {
        printf("윈도우 클래스 등록 실패\n");
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int windowWidth = 800;
    int windowHeight = 600;
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    HWND hwnd = CreateWindowExW(
        0,
        L"IntroImageWindow",
        L"시작 화면 - 아무 키나 누르세요",
        WS_OVERLAPPEDWINDOW,
        x, y, windowWidth, windowHeight,
        NULL, NULL, GetModuleHandle(NULL), NULL
    );

    if (!hwnd) {
        printf("윈도우 생성 실패\n");
        delete g_pIntroImage;
        g_pIntroImage = nullptr;
        GdiplusShutdown(gdiplusToken);
        _getch();
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnregisterClassW(L"IntroImageWindow", GetModuleHandle(NULL));
    delete g_pIntroImage;
    g_pIntroImage = nullptr;
    GdiplusShutdown(gdiplusToken);
}

void redraw_main_screen() {
    system("cls");
    draw_frame();
    print_date_and_weekday();
    print_alarm_list();
    gotoxy(5, 12);
    printf("p: 알람 설정 | d: 알람 삭제 | g: 팩맨 게임 시작 | Any other key: 종료");
}

// ================== [수정된 부분] ==================
int main(void) {
    system("chcp 65001 > nul");
    system("title 디지털 시계 & 팩맨");
    system("mode con: cols=82 lines=30");

    // 👈 프로그램 시작 시 맵 파일 로드
    if (!load_map_from_file("level1.txt")) {
        system("cls");
        set_text_color(COLOR_ERROR);
        printf("오류: level1.txt 파일을 열 수 없거나 파일 내용이 올바르지 않습니다.\n");
        printf("실행 파일과 같은 위치에 level1.txt 파일이 있는지 확인해주세요.\n\n");
        printf("맵 파일은 %d줄, 각 줄은 %d글자로 구성되어야 합니다.\n", MAP_HEIGHT, MAP_WIDTH);
        set_text_color(COLOR_DEFAULT);
        _getch(); // 사용자가 메시지를 확인할 수 있도록 잠시 대기
        return 1; // 오류 코드와 함께 프로그램 종료
    }

    show_intro_with_image();

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

        if (kbhit()) {
            char ch = getch();
            if (ch == 'd' || ch == 'D') {
                set_console_cursor_visibility(1);
                handle_alarm_deletion();
                needs_redraw = true;
            } else if (ch == 'g' || ch == 'G') {
                play_pacman_game();
                needs_redraw = true;
            } else if (ch == 'p' || ch == 'P') {
                handle_alarm_addition();
                needs_redraw = true;
            } else {
                if (ch == -32 || ch == 0 || ch == 224) { // Arrow key special codes
                    getch(); 
                    continue;
                }
                break;
            }
            set_console_cursor_visibility(0);
        }
        
        Sleep(100);
    }

    system("cls");
    set_text_color(COLOR_DEFAULT);
    printf("프로그램을 종료합니다. 좋은 하루 되세요!\n");
    set_console_cursor_visibility(1);
    return 0;
}
```

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


