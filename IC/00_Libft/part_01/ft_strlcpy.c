unsigned int	ft_strlcpy(char *restrict dst, char *restrict src, unsigned int dstsize)
{
	unsigned int	src_len;
	unsigned int	idx;

	src_len = ft_strlen(src);
	idx = 0;
	if (dstsize > 0)
	{
		while (src[idx] != '\0' && idx + 1 < dstsize)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (src_len);
}