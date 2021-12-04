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

    printf("-------- alt form ---------\n");
	printf("|%#3x|\n", 255);
	printf("|%#3X|\n", 255);
    printf("|%#10x|\n", 255);
	printf("|%#10X|\n", 255);
    printf("|%#010x|\n", 255);
	printf("|%#010X|\n", 255);
    printf("|%#3x|\n", -1);
	printf("|%#3X|\n", -1);
    printf("|%#10x|\n", -1);
	printf("|%#10X|\n", -1);
    ft_printf("---------------------------\n");
    ft_printf("|%#3x|\n", 255);
	ft_printf("|%#3X|\n", 255);
    ft_printf("|%#10x|\n", 255);
	ft_printf("|%#10X|\n", 255);
    ft_printf("|%#010x|\n", 255);
	ft_printf("|%#010X|\n", 255);
    ft_printf("|%#3x|\n", -1);
	ft_printf("|%#3X|\n", -1);
    ft_printf("|%#10x|\n", -1);
	ft_printf("|%#10X|\n", -1);
    ft_printf("---------------------------\n");
    ft_printf("|%#x|\n", 0);
	ft_printf("|%#X|\n", 10);
}