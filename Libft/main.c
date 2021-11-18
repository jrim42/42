#include "libft.h"
#include <stdio.h>

//ft_atoi.c
// int main(void)
// {
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("\n\f    -234"));
// 	printf("%d\n", atoi("\n\f    -234"));
// 	printf("%d\n", ft_atoi("+ 123"));
// 	printf("%d\n", atoi("+ 123"));
// 	printf("%d\n", ft_atoi("- 1"));
// 	printf("%d\n", atoi("- 1"));
//     printf("%d\n", ft_atoi("2147483649"));
// 	printf("%d\n", atoi("2147483649"));
// }

//ft_itoa.c
// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
//     printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(-0));
// 	printf("%s\n", ft_itoa(123));
//     printf("%s\n", ft_itoa(987654321));
// 	printf("%s\n", ft_itoa(-123));
//     printf("%s\n", ft_itoa('a'));
// }

//ft_split.c
// int	main(void)
// {
// 	char	**strs;
// 	int		idx;

// 	strs = ft_split("  12 34 56 78 ", ' ');
// 	idx = 0;
// 	while (strs[idx])
// 		printf("%s\n", strs[idx++]);
// 	return (0);
// }

//ft_strchr.c
// int main(void)
// {
//     printf("%s\n", ft_strchr("abc", 'a'));
//     printf("%p\n", ft_strchr("abc", 'a'));
//     printf("%s\n", ft_strchr("abc", 0));
//     printf("%p\n", ft_strchr("abc", 0));
//     printf("%s\n", ft_strchr("abc", 100));
//     printf("%p\n", ft_strchr("abc", 100));
// }

//ft_strchr.c
// int main(void)
// {
//     printf("%s\n", ft_strrchr("abca", 'a'));
//     printf("%p\n", ft_strrchr("abca", 'a'));
//     printf("%s\n", ft_strrchr("abca", 0));
//     printf("%p\n", ft_strrchr("abca", 0));
//     printf("%s\n", ft_strrchr("abca", 100));
//     printf("%p\n", ft_strrchr("abca", 100));
// }

//ft_strtrim.c
// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("0123abcde1", "0123"));
// 	printf("%s\n", ft_strtrim("01231", "0123"));
// 	printf("%s\n", ft_strtrim("012a345", "012345"));
// 	printf("%s\n", ft_strtrim("0abcde1", ""));
//  	printf("%s\n", ft_strtrim("     0    abcde1", " "));
// 	printf("%s\n", ft_strtrim("", "0123"));
// 	printf("%s\n", ft_strtrim("", ""));
// }

//ft_substr.c
int	main(void)
{
	printf("%s\n", ft_substr("abcdefg", 0, 3));
	printf("%s\n", ft_substr("abcdefg", 0, 10));
	printf("%s\n", ft_substr("abcdefg", 5, 1));
	printf("%s\n", ft_substr("abcdefg", 5, 5));
	printf("%s\n", ft_substr("abcdefg", 10, 3));
	printf("%s\n", ft_substr("", 0, 1));
	printf("%s\n", ft_substr("test", 10, 1));
}
