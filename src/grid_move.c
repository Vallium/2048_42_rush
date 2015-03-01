#include "game.h"

int		grid_move(int tab[4][4], void (*f)(int[4][4]))
{
	int		oldtab[4][4];

	grid_cpy(tab, oldtab);
	f(tab);
	return (grid_cmp(tab, oldtab) ? 0 : 1);
}
