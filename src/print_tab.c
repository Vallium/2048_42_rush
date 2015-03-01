#include "game.h"

int		print_tab(int tab[4][4], t_win *win)
{
	int		x;
	int		y;
	int		px;
	int		py;

	y = 0;
	py = 1;
	if (win->mx < 46 || win->my < 25)
		return (0);
	while (py < 8)
	{
		x = 0;
		px = 1;
		while (px < 8)
		{
			if (tab[y][x])
				mvprintw((win->my / 8) * py, (win->mx / 8) * px, "%d", tab[y][x]);
			if (win->boul && tab[y][x] == WIN_VALUE)
			{
				wclear(stdscr);
				box(stdscr, '#', '#');
				mvprintw((win->my / 2) - 3, (win->mx / 2) - 8, "CONGRATULATIONS");
				mvprintw((win->my / 2) , (win->mx / 2) - 11, "You got the 2048 tile!");
				mvprintw((win->my / 2) + 3, (win->mx / 2) - 13, "Press any key to continue.");
				while (!getch())
					;
				win->boul = 0;
				return (0);
			}
			px += 2;
			x++;
		}
		py += 2;
		y++;
	}
	return (1);
}
