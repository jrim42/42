#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *get_result_and_backup(char *str, char **backup);
int     find_new_line(char *str);
char    *my_strjoin(char *s1, char *s2, int read_size);
char    *my_strndup(char *src, int size);
int     my_strlen(char *s);
#endif