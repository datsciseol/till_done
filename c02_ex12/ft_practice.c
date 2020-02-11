#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(str);
		str++;
	}
}

void	print_hex(unsigned char hex)
{
	char	*tab;

	tab = "0123456789abcdef";
	ft_putchar(tab[hex / 16]);
	ft_putchar(tab[hex % 16]);
}

void	print_char(unsigned char hex)
{
	if (hex > 31 && hex < 127)
		ft_putchar(hex);
	else
		ft_putchar('.');
}

void	make_hexs(unsigned char *line, unsigned int curline, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (curline * 16 + i < size)
			print_hex(line[i]);
		else
			ft_putstr("  ");
		i++;
	}
}

void		ft_print_memory(void *addr, unsigned int size)
{
	size_t			curline;
	unsigned char	*tmp;
	size_t			i;

	curline = 0;
	tmp = (unsigned char*)addr;
	while (curline * 16 < size)
	{
		make_hexs(tmp, curline, size);
		ft_putchar(' ');
		i = 0;
		while (i < 16)
		{
			if (curline * 16 + i < size)
				print_char(tmp[i]);
			i++;
		}
		ft_putchar('\n');
		tmp += 16;
		curline++;
	}
}








int main()
{
	char *str = "Salut sdfsd ggfw dfe les aminches c'est cool show mem on fait de truc terrible\1\2";
	ft_print_memory(str, 1000);
	ft_print_memory(str, 0);
}
