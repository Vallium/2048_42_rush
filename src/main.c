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

void	grid_cpy(int src[4][4], int dst[4][4])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			dst[y][x] = src[y][x];
			x++;
		}
		y++;
	}
}

int		grid_cmp(int tab[4][4], int tab2[4][4])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] != tab2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

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

int		grid_move(int tab[4][4], void (*f)(int[4][4]))
{
	int		oldtab[4][4];

	grid_cpy(tab, oldtab);
	f(tab);
	return (grid_cmp(tab, oldtab) ? 0 : 1);
}

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
