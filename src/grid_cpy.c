#include "game.h"

void	grid_cpy(int src[4][4], int dst[4][4])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			dst[y][x] = src[y][x];
			x++;
		}
		y++;
	}
}
