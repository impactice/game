#include <stdio.h>
#include <math.h>
#include <windows.h> // Beep, Sleep 함수를 사용하기 위한 헤더

// 함수 원형 선언
int calc_frequency(int octave, int inx);

int main(void)
{
    // C장조 음계의 인덱스 (도, 레, 미, 파, 솔, 라, 시, 도)
    int index[] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8]; // 8개 음의 주파수를 저장할 배열
    int i;

    // 4옥타브의 C장조 음계 주파수를 계산하여 freq 배열에 저장
    for (i = 0; i < 8; i++)
    {
        freq[i] = calc_frequency(4, index[i]);
    }

    // 음계 상행 연주 (각 음을 0.5초씩)
    printf("Playing C Major Scale Up...\n");
    for (i = 0; i < 8; i++)
    {
        Beep(freq[i], 500);
    }

    // 1초 지연
    Sleep(1000); // 주석: 음간의 지연시간 1초

    // 음계 하행 연주 (각 음을 0.5초씩)
    printf("Playing C Major Scale Down...\n");
    for (i = 7; i >= 0; i--)
    {
        Beep(freq[i], 500);
    }

    return 0;
}

/**
 * @brief 옥타브와 음계 인덱스를 이용해 주파수(Hz)를 계산하는 함수
 * @param octave 기준 옥타브
 * @param inx 음계 인덱스 (0~12)
 * @return 계산된 주파수(Hz) 값
 */
int calc_frequency(int octave, int inx)
{
    // A4(4옥타브 '라')음인 440Hz를 기준으로 계산
    // '라'(A) 음의 기준 인덱스는 9
    double n = (double)(octave - 4) * 12 + (inx - 9);
    double frequency = 440.0 * pow(2.0, n / 12.0);
    
    // Beep 함수는 정수형 주파수 값을 사용하므로 정수로 변환하여 반환
    return (int)frequency;
}