#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int print_1(int num, ...);
int print_2(int num, ...);

int main(void)
{
    int   x;

    x = print_1(4, 'a', 'b', 'c', 'd');
    x = print_2(2, "42seoul", "cadet");
    // x += 97;
    // write(1, &x, 1);
}

int print_1(int num, ...)
{
    va_list arg_ptr;
    int     cnt;
    int     total;
    int     ch;

    total = 0;
    va_start(arg_ptr, num); // arg_ptr의 시작지접은 num
    for (cnt = 0; cnt < num; cnt++)
    {
        ch = va_arg(arg_ptr, int);
        write(1, &ch, 1);
    }
    printf("\n");
    va_end(arg_ptr); // 정리 동작
    return (0);
}

int print_2(int num, ...)
{
    va_list arg_ptr;
    int     cnt;

    va_start(arg_ptr, num); // arg_ptr의 시작지접은 num
    for (cnt = 0; cnt < num; cnt++)
    {
        printf("va_arg %d : %s\n", cnt, va_arg(arg_ptr, char *));
    }
    va_end(arg_ptr); // 정리 동작
    return (0);
}
