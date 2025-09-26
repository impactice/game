#include <stdio.h>
#include <math.h>

void reverse_serial_number(long number)
{
    int num;
    int i, length = 0;

    length = (int)(log10(number) + 1); // 자리수 계산

    for(i = 1; i <= length; i++)
    {
        num = number % 10; // 가장 낮은 자리수 추출
        printf("%d\n", num);
        number = number / 10; // 다음 자리수로 이동
    }
    printf("\n");
}

int main(void)
{
    long input = 12345; // 테스트용 숫자
    reverse_serial_number(input);
    return 0;
}