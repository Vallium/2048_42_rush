#include "game.h"

void	ft_exit(int ind)
{
	endwin();
	if (ind == 1)
		ft_putendl_fd("exit", 1);
	else if (ind == 2)
		ft_putendl_fd("YOU ARE A HUSS PLAYER! Program quited", 2);
	else if (ind == 3)
		ft_putendl_fd("You just tried a too small window BITCH!", 2);
	exit(0);
}
