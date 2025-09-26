#include <stdio.h>
#include <math.h> 

void serial_number(long number)
{
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
int main(void)
{
    long input = 12345; // 테스트용 숫자
    serial_number(input);
    return 0;
}

// 높은 단위부터