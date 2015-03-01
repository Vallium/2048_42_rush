#include "game.h"

void	init_curses()
{
	initscr();
	start_color();
	keypad(stdscr, true);
	curs_set(0);
}

void	grid_responsive(WINDOW *scr, t_win *win)
{
	win->lastx = win->mx;
	win->lasty = win->my;
	getmaxyx(scr, win->my, win->mx);
	box(scr, 0, 0);
	if (win->lastx != win->mx || win->lasty != win->my)
		wclear(scr);
	if (win->mx < 46 || win->my < 25)
	{
		wclear(scr);
		mvprintw(win->my / 2, (win->mx / 2) - 3, "RESIZE");
		return ;
	}
	mvhline((win->my / 4) * 1, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 2, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 3, 1, '-', (win->mx - 2));
	mvvline(1, (win->mx / 4) * 1, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 2, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 3, '|', (win->my - 2));
}
