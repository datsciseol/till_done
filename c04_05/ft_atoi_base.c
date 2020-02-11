#include <unistd.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_validated(char *str)
{
	char *ptr;
	int	i;
	int	j;
	
	ptr = str;
	i = 0;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*ptr)
	{
		if (ft_is_space(*ptr) || *ptr == '-' || *ptr == '+')
			return (0);
		ptr++;
	}
	while (i < ptr - str)
	{
		j = i + 1;
		while (j < ptr - str)
		{
			if (str[i] == str[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_base(char *base, char tgt)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == tgt)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	minus;
	int	answer;
	int	checked;
	
	radix = ft_strlen(base);
	minus = 1;
	answer = 0;
	if (!is_validated(base))
		return (0);
	while (ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = minus * (-1);
		str++;
	}
	while ((checked = check_base(base, *str)) != -1)
	{
		answer *= radix;
		answer += checked;
		str++;
	}
	return (answer * minus);
}

int main()
{
	printf("%d\n", ft_atoi_base("-123456", "0123456789"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("11110001001000000", "01"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("-1e240", "0123456789abcdef"));
	fflush(stdout);	
}
