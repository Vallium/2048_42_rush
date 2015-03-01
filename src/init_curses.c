#include "game.h"

void	init_curses()
{
	initscr();
	start_color();
	keypad(stdscr, true);
	curs_set(0);
}
