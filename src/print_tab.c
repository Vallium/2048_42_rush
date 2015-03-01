/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:52:11 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:52:13 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		print_win(t_win *win)
{
	bkgd(COLOR_PAIR(3));
	wclear(stdscr);
	box(stdscr, '#', '#');
	mvprintw((win->my / 2) - 3, (win->mx / 2) - 8, "CONGRATULATIONS");
	mvprintw((win->my / 2), (win->mx / 2) - 11, "You got the 2048 tile!");
	mvprintw((win->my / 2) + 3, (win->mx / 2) - 13,
			"Press any key to continue.");
	while (!getch())
		;
	win->boul = 0;
	bkgd(COLOR_PAIR(2));
	return (0);
}

int				print_tab(int tab[4][4], t_win *win)
{
	t_print		print;

	print.y = 0;
	print.py = 1;
	if (win->mx < 46 || win->my < 25)
		return (0);
	while (print.py < 8)
	{
		print.x = 0;
		print.px = 1;
		while (print.px < 8)
		{
			if (tab[print.y][print.x])
				mvprintw((win->my / 8) * print.py, (win->mx / 8) * print.px -
						(ft_intlen(tab[print.y][print.x]) / 2),
						"%d", tab[print.y][print.x]);
			if (win->boul && tab[print.y][print.x] == WIN_VALUE)
				return (print_win(win));
			print.px += 2;
			print.x++;
		}
		print.py += 2;
		print.y++;
	}
	return (1);
}
