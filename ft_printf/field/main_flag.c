#include "ft_printf.h"

int main(void)
{
    int len;
    
    // printf("------------\n");
    // printf("|%10s|\n", "abcd");
    // printf("|%3s|\n", "abcd");
    // printf("|%10c|\n", 'a');
    // printf("|%3c|\n", 'a');
    // printf("------------\n");
    // len = ft_printf("|%10s|\n", "abcd");
    // // printf("len : %d\n", len);
    // len = ft_printf("|%3s|\n", "abcd");
    // // printf("len : %d\n", len);
    // len = ft_printf("|%10c|\n", 'a');
    // // printf("len : %d\n", len);
    // len = ft_printf("|%3c|\n", 'a');
    // // printf("len : %d\n", len);
    
    // printf("------------\n");
    // printf("|%-10s|\n", "abcd");
    // printf("|%-3s|\n", "abcd");
    // printf("|%-10c|\n", 'a');
    // printf("|%-3c|\n", 'a');
    // printf("------------\n");
    // len = ft_printf("|%-10s|\n", "abcd");
    // // printf("len : %d\n", len);
    // len = ft_printf("|%-3s|\n", "abcd");
    // // printf("len : %d\n", len);
    // len = ft_printf("|%-10c|\n", 'a');
    // // printf("len : %d\n", len);
    // len = ft_printf("|%-3c|\n", 'a');
    // // printf("len : %d\n", len);

    // printf("------------\n");
    // len = printf("|%-10d|\n", 1234);
    // printf("len : %d\n", len);
    // printf("|%-3d|\n", 1234);
    // printf("|%10d|\n", 1234);
    // printf("|%3d|\n", 1234);
    // printf("------------\n");
    // len = ft_printf("|%-10d|\n", 1234);
    // printf("len : %d\n", len);
    // len = ft_printf("|%-3d|\n", 1234);
    // printf("len : %d\n", len);
    // len = ft_printf("|%10d|\n", 1234);
    // printf("len : %d\n", len);
    // len = ft_printf("|%3d|\n", 1234);
    // printf("len : %d\n", len);

    // printf("------------\n");
    // printf("|%010d|\n", 1234);
    // printf("|%03d|\n", 1234);
    // printf("------------\n");
    // len = ft_printf("|%010d|\n", 1234);
    // // printf("len : %d\n", len);
    // len = ft_printf("|%03d|\n", 1234);
    // // printf("len : %d\n", len);

    // printf("-------- alt form ---------\n");
	// printf("|%#3x|\n", 255);
	// printf("|%#3X|\n", 255);
    // printf("|%#10x|\n", 255);
	// printf("|%#10X|\n", 255);
    // printf("|%#010x|\n", 255);
	// printf("|%#010X|\n", 255);
    // printf("|%#3x|\n", -1);
	// printf("|%#3X|\n", -1);
    // printf("|%#10x|\n", -1);
	// printf("|%#10X|\n", -1);
    // ft_printf("---------------------------\n");
    // ft_printf("|%#3x|\n", 255);
	// ft_printf("|%#3X|\n", 255);
    // ft_printf("|%#10x|\n", 255);
	// ft_printf("|%#10X|\n", 255);
    // ft_printf("|%#010x|\n", 255);
	// ft_printf("|%#010X|\n", 255);
    // ft_printf("|%#3x|\n", -1);
	// ft_printf("|%#3X|\n", -1);
    // ft_printf("|%#10x|\n", -1);
	// ft_printf("|%#10X|\n", -1);
    // ft_printf("---------------------------\n");
    // ft_printf("|%#x|\n", 0);
	// ft_printf("|%#X|\n", 10);

    // printf(" %#x \n", 0);
    // printf(" %#x \n", -42);
    // printf(" %#x \n", INT_MAX);
    // printf(" %#x \n", INT_MIN);
    // printf(" %#x \n", LONG_MAX);
    // printf(" %#x \n", LONG_MIN);
    // printf(" %#x \n", ULONG_MAX);

    // len = ft_printf(" %d \n", 0);
    // // printf("len : %d\n", len);
    // len = ft_printf(" %d \n", -42);
    // // printf("len : %d\n", len);
    // len = ft_printf(" %d \n", INT_MAX);
    // // printf("len : %d\n", len);
    // len = ft_printf(" %d \n", INT_MIN);
    // // printf("len : %d\n", len);
    // len = ft_printf(" %d \n", LONG_MAX);
    // // printf("len : %d\n", len);
    // len = ft_printf(" %d \n", LONG_MIN);
    // // printf("len : %d\n", len);
    // len = ft_printf(" %d \n", ULONG_MAX);
    // // printf("len : %d\n", len);

    // printf(" %04d \n", 0);
    // printf(" %04d \n", -14);
    // printf(" %05d \n", -15);
    // printf(" %06d \n", -16);
    // printf(" %011d \n", LONG_MAX);
    // ft_printf(" %04d \n", -14);
    // ft_printf(" %05d \n", -15);
    // ft_printf(" %06d \n", -16);
    // ft_printf(" %011d \n", LONG_MAX);

    // printf(" %d \n", LONG_MIN);
    // ft_printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // printf(" %x \n", 2147483648);
    // ft_printf(" %x \n", 2147483648);
    // printf(" %x \n", -1);
    // ft_printf(" %x \n", -1);
    // printf(" %x \n", -2147483649);
    // ft_printf(" %x \n", -2147483649);

    // printf(" %01d \n", 0);
    // ft_printf(" %01d \n", 0);

    len = printf("|% d|\n", 0);
    printf("len : %d\n", len);
    len = printf("|% d|\n", -1);
    printf("len : %d\n", len);
// 	printf("|% d|\n", -9);
// 	printf("|% d|\n", -10);
// 	printf("|% d|\n", -11);
// 	printf("|% d|\n", -15);
// 	printf("|% d|\n", -16);
// 	printf("|% d|\n", -17);
// 	printf("|% d|\n", -99);
	len = printf("|% d|\n", -100);
    printf("len : %d\n", len);
    len = printf("|% d|\n", 100);
    printf("len : %d\n", len);
// 	printf("|% d|\n", -101);
// 	printf("|% d|\n", INT_MAX);
// 	printf("|% d|\n", LONG_MIN);
// 	printf("% d % d % d % d % d % d % d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    len = ft_printf("|% d|\n", 0);
	printf("len : %d\n", len);
    len = ft_printf("|% d|\n", -1);
    printf("len : %d\n", len);
// 	ft_printf("|% d|\n", -9);
// 	ft_printf("|% d|\n", -10);
// 	ft_printf("|% d|\n", -11);
// 	ft_printf("|% d|\n", -15);
// 	ft_printf("|% d|\n", -16);
// 	ft_printf("|% d|\n", -17);
// 	ft_printf("|% d|\n", -99);
	len = ft_printf("|% d|\n", -100);
    printf("len : %d\n", len);
    len = ft_printf("|% d|\n", 100);
    printf("len : %d\n", len);
// 	ft_printf("|% d|\n", -101);
// 	ft_printf("|% d|\n", INT_MAX);
// 	ft_printf("|% d|\n", LONG_MIN);
// 	ft_printf("% d % d % d % d % d % d % d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // printf("%+u\n", 0);
    // printf("%+u\n", 10);
    // printf("%+u\n", -11);
    // ft_printf("%+u\n", 0);
    // ft_printf("%+u\n", 10);
    // ft_printf("%+u\n", -11);   

    // len = printf("|%-0s|\n", "");
    // printf("len : %d\n", len);
    // len = ft_printf("|%-0s|\n", "");
    // printf("len : %d\n", len);

    printf("%20x|\n", 10);
    printf("%-20x|\n", 10);
    ft_printf("%20x|\n", 10);
    ft_printf("%-20x|\n", 10);
}