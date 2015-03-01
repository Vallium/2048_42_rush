

void	move_r(int tab[4][4], int y)
{
	int x;

	x = 3;
	while (--x > -1)
		if (tab[y][x + 1] == 0)
		{
			tab[y][x + 1] = tab[y][x];
			tab[y][x] = 0;
		}
}

void	move_l(int tab[4][4], int y)
{
	int x;

	x = 0;
	while (++x < 4)
	{
		if (tab[y][x - 1] == 0)
		{
			tab[y][x - 1] = tab[y][x];
			tab[y][x] = 0;
		}
	}
}

void	move_left(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (x < 1 && tab[y][x + 1] == 0 && tab[y][x + 2] == 0 && tab[y][x] == tab[y][x + 3])
				tab[y][x] *= 2, tab[y][x + 3] = 0;
			else if (x < 2 && tab[y][x + 1] == 0 && tab[y][x] == tab[y][x + 2])
				tab[y][x] *= 2, tab[y][x + 2] = 0;
			else if (x != 3 && tab[y][x] == tab[y][x + 1])
				tab[y][x] *= 2, tab[y][x + 1] = 0;
		move_l(tab, y), move_l(tab, y), move_l(tab, y);
	}
}

void	move_right(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = 4;
		while (--x > -1)
			if (x > 2 && tab[y][x - 1] == 0 && tab[y][x - 2] == 0 && tab[y][x] == tab[y][x - 3])
				tab[y][x] *= 2, tab[y][x - 3] = 0;
			else if (x > 1 && tab[y][x - 1] == 0 && tab[y][x] == tab[y][x - 2])
				tab[y][x] *= 2, tab[y][x - 2] = 0;
			else if (x != 0 && tab[y][x] == tab[y][x - 1])
				tab[y][x] *= 2, tab[y][x - 1] = 0;
		move_r(tab, y), move_r(tab, y), move_r(tab, y);
	}
}
