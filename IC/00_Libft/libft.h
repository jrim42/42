#ifndef	LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int             ft_isalpha(int c);
int             ft_isdigit(int c);
int             ft_isalnum(int c);
int             ft_isascii(int c);
int             ft_isprint(int c);
int             ft_toupper(int c);
int             ft_tolower(int c);

unsigned int    ft_strlen(const char *s);
unsigned int	ft_strlcpy(char *restrict dst, char *restrict src, unsigned int dstsize);
unsigned int	ft_strlcat(char *restrict dst, const char *restrict src, unsigned int dstsize);
char            *ft_strchr(const char *s, int c);
char            *ft_strrchr(const char *s, int c);
int	            ft_strncmp(const char *s1, const char *s2, unsigned int n);
char            *ft_strnstr(const char *haystack, const char *needle, unsigned int len);

void            *ft_memset(void *b, int c, unsigned int len);
void            ft_bzero(void *s, unsigned int n);
void            *ft_memcpy(void *restrict dst, const void *restrict src, unsigned int n);
void            *ft_memmove(void *dst, const void *src, unsigned int len);
void            *ft_memchr(const void *s, int c, unsigned int n);
int             ft_memcmp(const void *s1, const void *s2, unsigned int n);
int	            ft_atoi(const char *str);

#endif