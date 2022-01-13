#include "gnl_00/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	int		fd;
	int		byte;

	fd = open("testtest", O_RDONLY);
	byte = read(fd, buf, BUFFER_SIZE);
	printf("%d : %s\n", byte, buf);
	while (byte > 0)
	{
		buf[byte] = '\0';
		printf("%d : %s\n", byte, buf);
		byte = read(fd, buf, BUFFER_SIZE);
	}
}
