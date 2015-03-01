#include "game.h"

int		grid_cmp(int tab[4][4], int tab2[4][4])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] != tab2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
