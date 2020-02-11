unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, int size)
{
	unsigned int	idx;
	unsigned int	src_len;

	idx = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[idx] && idx < (size - 1))
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (src_len);
}
