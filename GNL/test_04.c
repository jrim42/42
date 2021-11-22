#include "get_next_line.h"

char    *gnl(int fd);
char    *cut_eol(const char *buf);
char	*ft_strdup(const char *s1);

int	main(void)
{
    int     fd;
    char    *tmp;

    fd = open("test", O_RDONLY);
    while ((tmp = gnl(fd)) != 0)
        printf("%s", tmp);
    close(fd);
    return (0);
}

char    *gnl(int fd)
{
    int         byte;
    static char buf[BUFFER_SIZE + 1];
    char        *depot[10];
    int         idx;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    byte = read(fd, buf, BUFFER_SIZE);
    buf[byte] = '\0';
    idx = 0;
    if (byte > 0)
    {
        if (ft_strchr(buf, '\n') != 0) // 읽어들인 문자열 내에 개행이 있는 경우
        {
            // 개행까지 포함해서 문자열을 잘라서 depot에 담아줘야 한다.
            depot[idx] = ft_strjoin(depot[idx], cut_eol(buf));
            // depot[idx + 1]에 자르고 남은 것을 또 붙여준다 
        }
        else
            depot[idx] = ft_strjoin(depot[idx], buf);
    }
    return (depot[idx++]);
}

char    *cut_eol(const char *buf)
{
    char    *ptr;
    char    *eol_pos;

    ptr = (char *)buf;
    eol_pos = ft_strchr(buf, '\n') + 1;
    *(ptr + (int)(eol_pos - ptr)) = '\0';
    return (ft_strdup(ptr));
}

char	*ft_strndup(const char *s1, size_t n)
{
	unsigned int	idx;
	unsigned int	src_len;
	char			*dupstr;

	src_len = ft_strlen(s1);
	dupstr = (char *)malloc((src_len + 1) * sizeof(char));
	if (!(dupstr))
		return (0);
	idx = 0;
	while (idx < src_len)
	{
		dupstr[idx] = s1[idx];
		idx++;
	}
	dupstr[idx] = '\0';
	return (dupstr);
}