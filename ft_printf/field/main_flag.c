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
    // printf("|%-10d|\n", 1234);
    // printf("|%-3d|\n", 1234);
    // printf("|%10d|\n", 1234);
    // printf("|%3d|\n", 1234);
    // printf("------------\n");
    // len = ft_printf("|%-10d|\n", 1234);
    // // printf("len : %d\n", len);
    // len = ft_printf("|%-3d|\n", 1234);
    // // printf("len : %d\n", len);
    // len = ft_printf("|%10d|\n", 1234);
    // // printf("len : %d\n", len);
    // len = ft_printf("|%3d|\n", 1234);
    // // printf("len : %d\n", len);

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

    // ft_printf(" %#x \n", 0);
    // ft_printf(" %#x \n", -42);
    // ft_printf(" %#x \n", INT_MAX);
    // ft_printf(" %#x \n", INT_MIN);
    // ft_printf(" %#x \n", LONG_MAX);
    // ft_printf(" %#x \n", LONG_MIN);
    // ft_printf(" %#x \n", ULONG_MAX);

    printf(" %04d \n", -14);
    printf(" %05d \n", -15);
    printf(" %06d \n", -16);
    printf(" %011d \n", LONG_MAX);
    ft_printf(" %04d \n", -14);
    ft_printf(" %05d \n", -15);
    ft_printf(" %06d \n", -16);
    ft_printf(" %011d \n", LONG_MAX);

    printf(" %01d \n", 0);
    ft_printf(" %01d \n", 0);
}