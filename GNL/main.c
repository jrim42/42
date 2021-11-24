#include "get_next_line.h"

int	main(void)
{
    int     fd;
    char    *tmp;
    int     idx;

    fd = open("test", O_RDONLY);
    idx = 1;
    printf ("fd : %d\n", fd);
    while ((tmp = get_next_line(fd)) != 0)
    {
        printf("----- %d -----\n", idx);
        printf("%s", tmp);
        printf("-------------\n");
        idx++;
		free(tmp);

    }
    close(fd);
    return (0);
}