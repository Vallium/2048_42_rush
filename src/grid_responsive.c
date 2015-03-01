#include "game.h"

void	grid_responsive(WINDOW *scr, t_win *win)
{
	win->lastx = win->mx;
	win->lasty = win->my;
	getmaxyx(scr, win->my, win->mx);
	box(scr, 0, 0);
	if (win->lastx != win->mx || win->lasty != win->my)
		wclear(scr);
	if (win->mx < 46 || win->my < 25)
		ft_exit(3);
	mvhline((win->my / 4) * 1, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 2, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 3, 1, '-', (win->mx - 2));
	mvvline(1, (win->mx / 4) * 1, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 2, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 3, '|', (win->my - 2));
}
