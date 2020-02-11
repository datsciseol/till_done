include <unistd.h>



void	write_char(char *c)
{
	if (*c >= 32 && *c <= 126)
		write(1, c, 1);
	else
		write(1, &".", 1);
}

void	ft_print_line(void *str_addr, unsigned int size, char *temp)
{
	int	idx;

	write_hex((unsigned int)temp, 16);
	write(1, &": ", 2);
	idx = 0;
	while (idx < 16)
	{
		if (str_addr + size <= (void *)(temp + idx)
			write(1, &" ", 2);
		else
void	ft_buffer_number(int number, int radix, int buffer[], int index)
{
	if (number > radix - 1)
		ft_buffer_number(number / radix, radix, buffer, index + 1);
	buffer[index] = number % radix;
}

void	ft_write_hex(unsigned int number, int radix, int char_count)
{
	int	buffer[MAX_PAGE_SIZE + 1];
	int	index;

	index = -1;
	while (index++ < MAX_PAGE_SIZE)
		buffer[index] = 0;
	ft_buffer_number(number, radix, buffer, 0);
	index = -1;
	while (index++ < char_count)
		write(1, &"0123456789abcdefgh"[buffer[char_count - index]], 1);
}
			write_hex((unsigned char)*(temp + idx), 1);
		if (idx % 2 == 0)
			write(1, &" ", 1);
		idx++;
	}
	idx = 0;
	while (idx < 16)
	{
		if (str_addr + size > (void*)(temp + idx))
			write_char((char *)temp + idx);
		idx++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*temp_ptr;

	temp_ptr = (char *)addr;
	while ((void *)temp_ptr < (addr + size))
	{
		ft_print_line(addr, size, temp_ptr);
		temp_ptr += 16;
	}
	return (addr);
}
