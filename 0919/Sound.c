#include <stdio.h>
#include <math.h>

// 함수 원형 선언
void print_frequency(int octave);

int main(void)
{
    // 12음계 이름 배열
    char *scale[] = {"도", "도#", "레", "레#", "미", "파", 
                     "파#", "솔", "솔#", "라", "라#", "시"};

    int i, octave;

    printf("음계와 주파수 (A4 = 440Hz)\n\n");
    printf("옥타브\t");

    // 상단에 음계 이름 출력
    for(i = 0; i < 12; i++)
    {
        printf("%-7s", scale[i]);
    }
    printf("\n");

    // 구분선 출력
    for(i = 0; i <= 90; i++)
    {
        printf("-");
    }
    printf("\n");

    // 1옥타브부터 6옥타브까지 주파수 출력
    for(octave = 1; octave < 7; octave++)
    {
        print_frequency(octave);
    }

    return 0;
}

/**
 * @brief 특정 옥타브의 12음계 주파수를 계산하고 출력하는 함수
 * @param octave 계산할 옥타브 (1 ~ 6)
 */
void print_frequency(int octave)
{
    printf("%d\t", octave); // 옥타브 번호 출력

    // 12음계에 대해 반복
    for (int i = 0; i < 12; i++)
    {
        // A4(4옥타브 '라')음을 기준으로 반음(semitone) 거리 계산
        // '라'는 배열에서 9번째(인덱스 9)에 위치함
        int n = (octave - 4) * 12 + (i - 9);

        // 주파수 계산 공식: f = f_ref * (2^(n/12))
        double frequency = 440.0 * pow(2.0, n / 12.0);

        printf("%-7.2f", frequency); // 계산된 주파수를 소수점 둘째 자리까지 출력
    }
    printf("\n"); // 한 옥타브 출력이 끝나면 줄바꿈
}