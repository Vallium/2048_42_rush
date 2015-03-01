/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:53:21 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/27 20:53:25 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		main(void)
{
	int		ch;
	t_win	win;

	int		tab[4][4] = {	{0, 0, 0, 0},
							{0, 0, 0, 0},
							{0, 0, 0, 0},
							{0, 0, 0, 0}};

	win.boul = 1;
	if (!WIN_VALUE || (WIN_VALUE & (WIN_VALUE - 1)))
	{
		ft_putnbr(WIN_VALUE);
		ft_putendl_fd(" is not a power of two\n", 2);
		return (0);
	}
	init_curses();
	grid_init(tab);
//	signal(SIGINT, SIG_IGN);
	getmaxyx(stdscr, win.my, win.mx);
	while(42)
	{
		wclear(stdscr);
		grid_check(tab);
		grid_responsive(stdscr, &win);
		if (!print_tab(tab, &win))
			continue ;
		ch = getch();
		if (ch == 27)
			ft_exit(1);
		else if (ch == 259)
		{
			if (grid_move(tab, move_up))
				pop_number(tab);
		}
		else if (ch == 258)
		{
			if (grid_move(tab, move_down))
				pop_number(tab);
		}
		else if (ch == 261)
		{
			if (grid_move(tab, move_right))
				pop_number(tab);
		}
		else if (ch == 260)
		{
			if (grid_move(tab, move_left))
				pop_number(tab);
		}

		refresh();
	}

	endwin();
	return (0);
}
