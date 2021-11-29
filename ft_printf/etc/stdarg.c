#include <stdio.h>
#include <stdarg.h>

float average(int num, ...);

int main(void)
{
    float   x;

    x = average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("avg : %0.1f\n", x);
    x = average(5, 1, 2, 3, 4, 5);
    printf("avg : %0.1f\n", x);
}

float average(int num, ...)
{
    va_list arg_ptr;
    int     cnt;
    int     total;

    total = 0;
    va_start(arg_ptr, num); // arg_ptr의 시작지접은 num
    for (cnt = 0; cnt < num; cnt++)
        total += va_arg(arg_ptr, int); // va_arg로 인수들을 읽어들이면서 (int형으로) total에 더해주기
    va_end(arg_ptr); // 정리 동작
    return ((float)total / num);
}
