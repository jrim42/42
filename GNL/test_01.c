#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	int		fd;
	int		byte;
	int		idx;

	fd = open("test", O_RDONLY);
	byte = read(fd, buf, BUFFER_SIZE);
	while (byte == BUFFER_SIZE)
	{
		printf("%s", buf);
		byte = read(fd, buf, BUFFER_SIZE);
	}
	idx = 0;
	if (byte < BUFFER_SIZE)
		while (byte--)
			printf("%c", buf[idx++]);
}
