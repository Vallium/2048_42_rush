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

static void		fill_tab_zero(int tab[4][4])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			tab[y][x] = 0;
			x++;
		}
		y++;
	}
}

static void		get_ch(int tab[4][4])
{
	int		ch;

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
}

int				main(void)
{
	t_win	win;
	int		tab[4][4];

	if (WIN_VALUE <= 0 || (WIN_VALUE & (WIN_VALUE - 1)))
	{
		ft_putnbr(WIN_VALUE);
		ft_putendl_fd(" is not a power of two\n", 2);
		return (0);
	}
	fill_tab_zero(tab);
	init_curses(&win);
	grid_init(tab);
	getmaxyx(stdscr, win.my, win.mx);
	while (42)
	{
		wclear(stdscr);
		grid_check(tab);
		grid_responsive(stdscr, &win);
		if (!print_tab(tab, &win))
			continue ;
		get_ch(tab);
	}
	return (0);
}
