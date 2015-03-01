#include "game.h"

void	grid_check(int tab[4][4])
{
	int		nxt_tab[4][4];

	grid_cpy(tab, nxt_tab);
	if (grid_move(nxt_tab, move_up))
		pop_number(nxt_tab);
	if (grid_move(nxt_tab, move_down))
		pop_number(nxt_tab);
	if (grid_move(nxt_tab, move_right))
		pop_number(nxt_tab);
	if (grid_move(nxt_tab, move_left))
		pop_number(nxt_tab);
	if (grid_cmp(tab, nxt_tab))
	{
		ft_exit(2);
	}
}
