#include <unistd.h>
#include <stdlib.h>

void	ft_buffer(int number, int buffer[], int idx)
{
	if (number > 15)
	{
		ft_buffer(number / 16, buffer, idx + 1);
	}
	buffer[idx] = number % 16;
}

void	write_hex(unsigned int number, int char_len)
{
	int	buffer[16];
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		buffer[idx] = 0;
	}
	idx = 0;
	while (idx++ < char_len)
		write(1, &"0123456789abcdefgh"[buffer[char_len - idx]], 1);
}

void	write_char(char *str)
{
	if (*str >= 32 && *str <= 126)
		write(1, str, 1);
	else
		write(1, &".", 1);
}

void	print_line(void *start, unsigned int size)
{
	int	idx;

	idx = 0;
	write_hex((unsigned int)start, 16);
	write(1, &": ", 2);
	while (idx < 16)
	{
		if (size <= idx)
			write(1, &"  ", 2);
		else
			write_hex((unsigned int)*((char *)(start + idx)), 1);
		if (idx % 2 == 0)
			write(1, &" ", 1);
	}
	idx = 0;
	while (idx < 16)
	{
		if (size > idx)
		{
			write_char((char *)(start + idx));
		}
		idx++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*start_addr;

	start_addr = addr;
	
	while ((void *)start_addr < (addr + size))
	{
		print_line(start_addr, size);
		write(1, &"\n", 1);
		start_addr += 16;
	}
}

int		main(void)
{
	char	*string;

	string = "Bonjour les aminches\t\n\tc  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. ";
	ft_print_memory(string, 1500);
}
