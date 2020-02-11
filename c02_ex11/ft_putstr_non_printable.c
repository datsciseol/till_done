#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	if (c >= 20 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
		{
			ft_putchar(*str);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[*str / 16]);
			ft_putchar("0123456789abcdef"[*str % 16]);
		}
		str++;
	}	
}

int main()
{
	char s[40] = "13123\n \r \t \s sfweewf sdfwe ";
	ft_putstr_non_printable(s);
}
