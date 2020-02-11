#include <unistd.h>

int	is_not_validated(int table[][10], int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	diff_pos[2];

	x = 0;
	diff_pos[0] = pos_y - pos_x;
	diff_pos[1] = pos_y +pos_x;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (x == pos_x || y == pos_y || y == x + diff_pos[0] 
							|| y == -x + diff_pos[1])
	 			if (table[y][x])
					return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	preprocessing(int table[][10], int col)
{
	int	row;

	row = 0;
	while (row < 10)
		table[row++][col] = 0;
}

void	print_pos(int table[][10])
{
	int	row;
	int	col;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			if (table[row][col])
			{
				write(1, &"0123456789"[col], 1);
				break;
			}
			col++;
		}
		row++;
	}
	write(1, "\n", 1);
}

int	find_answer(int table[][10], int x, int *solve)
{
	int	y;

	y = 0;
	if (x >= 10)
	{
		return (1);
	}
	while (y < 10)
	{
		if (!is_not_validated(table, x, y))
		{
			table[y][x] = 1;
			if (find_answer(table, x + 1, solve))
			{
				*solve += 1;
				print_pos(table);
			}
			table[y][x] = 0;
		}
		y++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10][10];
	int	col;
	int	solve;

	col = 0;
	solve = 0;
	while (col++ < 10)
		preprocessing(table, col - 1);
	find_answer(table, 0, &solve);
	return (solve);
}

#include <stdio.h>
int main()
{
	int i = ft_ten_queens_puzzle();
	printf("%d", i);
}
