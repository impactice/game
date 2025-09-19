#include <stdio.h>
#include <math.h>
#include <windows.h> // Beep 함수 사용
#include <conio.h>   // getch 함수 사용

// 함수 원형 선언
void practice_piano(void);
int calc_frequency(int octave, int inx);

int main(void)
{
    printf("디지털 피아노\n");
    printf("키보드 1~8을 눌러 연주하세요. (종료: ESC)\n");
    practice_piano(); // 피아노 함수 호출
    return 0;
}

// 가상 피아노 함수
void practice_piano(void)
{
    // C장조 음계 인덱스
    int index[] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8], code, i;

    // 4옥타브의 C장조 주파수를 미리 계산하여 배열에 저장
    for (i = 0; i < 8; i++)
    {
        freq[i] = calc_frequency(4, index[i]);
    }

    // ESC(ASCII 27)를 누르기 전까지 무한 반복
    do
    {
        // 키보드 입력 대기
        code = getch();

        // 입력된 키가 '1' ~ '8' 사이인 경우
        if ('1' <= code && code <= '8')
        {
            // ASCII 코드('1'은 49)를 배열 인덱스(0)로 변환
            code -= 49; 
            // 해당 음을 0.3초간 연주
            Beep(freq[code], 300);
        }
    } while (code != 27);
}

// 주파수 계산 함수
int calc_frequency(int octave, int inx)
{
    double n = (double)(octave - 4) * 12 + (inx - 9);
    double frequency = 440.0 * pow(2.0, n / 12.0);
    return (int)frequency;
}