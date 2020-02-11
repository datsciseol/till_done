#include <unistd.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}


int	is_validate(char *str)
{
	char	*ptr;
	int	i;
	int	j;

	ptr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*ptr)
	{
		if (*ptr == '\t' || *ptr == '\n' || *ptr == '\v' || *ptr == '\f'
			|| *ptr == '\r' || *ptr == ' ' || *ptr == '+' || *ptr == '-')
			return (0);
		ptr++;
	}
	i = 0;
	while (i < ptr - str)
	{
		j = i + 1;
		while (j < ptr - str)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

void	ft_rec_putnbr_base(int nbr, char *base, int radix)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			ft_rec_putnbr_base(nbr / radix, base, radix);
		else
		{
			write(1, "-", 1);
			ft_rec_putnbr_base(-nbr, base, radix);
		}
	}
	if (nbr > radix - 1)
		ft_rec_putnbr_base(nbr / radix, base, radix);
	write(1, &base[nbr % radix], 1);
}
void	ft_putnbr_base(int nbr, char *base)
{
	int radix;

	if (!is_validate(base))
		return ;
	radix = ft_strlen(base);
	ft_rec_putnbr_base(nbr, base, radix);
}
