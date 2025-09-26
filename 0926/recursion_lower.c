#include <stdio.h>

void reverse_number(long number)
{
    printf("%ld\n", number % 10);
    if ((number / 10) > 0)
        reverse_number(number / 10);
}

int main()
{
    long num;
    printf("숫자를 입력하세요: ");
    scanf("%ld", &num);

    if (num == 0)
        printf("0\n");
    else
        reverse_number(num);

    return 0;
} 
// 재귀 낮은 단위부터