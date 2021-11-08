char    *ft_strchr(const char *s, int c)
{
    int     idx;
    int     s_len;
    char    *ptr;

    idx = 0;
    s_len = ft_strlen(s) + 1;
    ptr = s;
    while (idx < s_len)
    {
        if (*ptr == c)
            return (ptr);
        idx++;
        ptr++; 
    }
    return (0);
}