#include "game.h"

int		rand_number(void)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 100 >= 90 ? 4 : 2;
	return (nb);
}

void	pop_number(int tab[4][4])
{
	int		x;
	int		y;
	int		rd;

	srand(time(NULL));
	rd = rand() % 20;
	while (42)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (!tab[y][x])
					rd--;
				if(!rd)
				{
					tab[y][x] = rand_number();
					return ;
				}
				x++;
			}
			y++;
		}
	}
}

int		rand_number_ini(void)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 100 >= 70 ? 4 : 2;
	return (nb);
}

void	grid_init(int tab[4][4])
{
	int		x;
	int		y;

	srand(time(NULL));
	x = rand() % 4;
	y = rand() % 4;
	tab[y][x] = rand_number_ini();
	while (42)
	{
		x = rand() % 4;
		y = rand() % 4;
		if (!tab[y][x])
		{
			tab[y][x] = 2;
			return ;
		}
	}
}
