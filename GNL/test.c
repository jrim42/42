#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 12

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	int		fd;
	int		byte;

	fd = open("test", O_RDONLY);
	byte = read(fd, buf, BUFFER_SIZE);
	printf("fd : %d\n", fd);
	printf("byte : %d\n", byte);
	printf("buf : %s\n", buf);
}
