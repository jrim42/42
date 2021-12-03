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

    printf("------------\n");
    printf("|%010d|\n", 1234);
    printf("|%03d|\n", 1234);
    printf("------------\n");
    len = ft_printf("|%010d|\n", 1234);
    // printf("len : %d\n", len);
    len = ft_printf("|%03d|\n", 1234);
    // printf("len : %d\n", len);
}