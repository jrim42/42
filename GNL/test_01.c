#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	int		fd;
	int		byte;

	fd = open("test", O_RDONLY);
	byte = read(fd, buf, BUFFER_SIZE);
	while (byte > 0)
	{
		printf("%s", buf);
		byte = read(fd, buf, BUFFER_SIZE);
	}
}
