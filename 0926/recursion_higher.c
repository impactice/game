#include <stdio.h>

void serial_number(long number)
{
    if (number > 0)
    {
        serial_number(number / 10);
        printf("%ld\n", number % 10);
    }
}

int main()
{
    long num;
    printf("숫자를 입력하세요: ");
    scanf("%ld", &num);

    if (num == 0)
        printf("0\n");
    else
        serial_number(num);

    return 0;
} 
// 재귀 높은 단위부터