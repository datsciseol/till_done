#include <unistd.h>
#define MAX_PAGE_SIZE 14

void	ft_buffer_number(int number,  int buffer[], int index)
{
	if (number > 15)
		ft_buffer_number(number / 16, buffer, index + 1);
	buffer[index] = number % 16;
}

void	ft_write_hex(unsigned int number,  int char_count)
{
	int	buffer[MAX_PAGE_SIZE + 1];
	int	index;

	index = -1;
	while (index++ < MAX_PAGE_SIZE)
		buffer[index] = 0;
	ft_buffer_number(number,  buffer, 0);
	index = -1;
	while (index++ < char_count)
		write(1, &"0123456789abcdefgh"[buffer[char_count - index]], 1);
}













/*
void	ft_buffer_number(int number, int buffer[], int idx)
{
	if (number > 15)
		ft_buffer_number(number / 16,  buffer, idx + 1);
	buffer[idx] = number % 16;
}


void	ft_write_hex(unsigned int number,  int char_count)
{
	int	buffer[16];
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		buffer[idx] = 0;
		idx++;
	}
	ft_buffer_number(number, buffer, 0);
	idx = 0;
	while (idx <= char_count)
	{
		write(1, &"0123456789abcdefgh"[buffer[char_count - idx]], 1);
		idx++;
	}	
}*/
int main()
{
	int i = 0;
	char *str = "Abcdfewfdfcgdfd";
	ft_write_hex(str, 30);
	
}
