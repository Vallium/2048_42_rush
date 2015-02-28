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

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <game.h>

void	ft_exit()
{
	endwin();/*Curses close*/
	ft_putendl_fd("exit", 2);
	exit(0);
}

void	move_u(int tab[4][4], int x)
{
	int y;

	y = 0;
	while (++y < 4)
		if (tab[y - 1][x] == 0)
		{
			tab[y - 1][x] = tab[y][x];
			tab[y][x] = 0;
		}
}

void	move_d(int tab[4][4], int x)
{
	int y;

	y = 3;
	while (--y > -1)
		if (tab[y + 1][x] == 0)
		{
			tab[y + 1][x] = tab[y][x];
			tab[y][x] = 0;
		}
}

void	move_r(int tab[4][4], int y)
{
	int x;

	x = 3;
	while (--x > -1)
		if (tab[y][x + 1] == 0)
		{
			tab[y][x + 1] = tab[y][x];
			tab[y][x] = 0;
		}
}

void	move_l(int tab[4][4], int y)
{
	int x;

	x = 0;
	while (++x < 4)
	{
		if (tab[y][x - 1] == 0)
		{
			tab[y][x - 1] = tab[y][x];
			tab[y][x] = 0;
		}
	}
}

void	move_left(int tab[4][4])
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (x != 3 && tab[y][x] == tab[y][x + 1])
			{
				tab[y][x] *= 2;
				tab[y][x + 1] = 0;
			}
			x++;
		}
		move_l(tab, y), move_l(tab, y), move_l(tab, y);
		y++;
	}
}

void	move_right(int tab[4][4])
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 4;
		while (x > 0)
		{
			if (x != 0 && tab[y][x] == tab[y][x - 1])
			{
				tab[y][x] *= 2;
				tab[y][x - 1] = 0;
			}
			move_r(tab, y), move_r(tab, y), move_r(tab, y);
			x--;
		}
		y++;
	}
}

void	move_up(int tab[4][4])
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (y != 3 && tab[y][x] == tab[y + 1][x])
			{
				tab[y][x] *= 2;
				tab[y + 1][x] = 0;
			}
			y++;
		}
		move_u(tab, x), move_u(tab, x), move_u(tab, x);
		x++;
	}
}

void	move_down(int tab[4][4])
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 4;
		while (y > 0)
		{
			if (y != 0 && tab[y][x] == tab[y - 1][x])
			{
				tab[y][x] *= 2;
				tab[y - 1][x] = 0;
			}
			move_d(tab, x), move_d(tab, x), move_d(tab, x);
			y--;
		}
		x++;
	}
}

void	print_tab(int tab[4][4], t_win *win)
{
	int		x;
	int		y;
	int		px;
	int		py;

	y = 0;
	py = 1;
	while (py < 8)
	{
		x = 0;
		px = 1;
		while (px < 8)
		{
			mvprintw((win->my / 8) * py, (win->mx / 8) * px, "%d", tab[y][x]);
			px += 2;
			x++;
		}
		py += 2;
		y++;
	}
}

int		main(void)
{
//	WINDOW	*win;
	int		ch;
	t_win	win;

	int		tab[4][4] = {	{0, 2, 2, 2},
							{0, 2, 2, 2},
							{0, 2, 2, 2},
							{0, 2, 2, 2}};
	initscr();/*Curses init*/
	keypad(stdscr, true);
	getmaxyx(stdscr, win.my, win.mx);
	while(42)
	{
		win.lastx = win.mx;
		win.lasty = win.my;
		getmaxyx(stdscr, win.my, win.mx);
		box(stdscr, 0, 0);
		if(win.lastx != win.mx || win.lasty != win.my)
			wclear(stdscr);
		mvhline((win.my / 4) * 1, 1, '-', (win.mx - 2));
		mvhline((win.my / 4) * 2, 1, '-', (win.mx - 2));
		mvhline((win.my / 4) * 3, 1, '-', (win.mx - 2));
		mvvline(1, (win.mx / 4) * 1, '|', (win.my - 2));
		mvvline(1, (win.mx / 4) * 2, '|', (win.my - 2));
		mvvline(1, (win.mx / 4) * 3, '|', (win.my - 2));


		print_tab(tab, &win);
		ch = getch();
		if (ch == 27)
			ft_exit();
		else if (ch == 259)
			move_up(tab);
		else if (ch == 258)
			move_down(tab);
		else if (ch == 261)
			move_right(tab);
		else if (ch == 260)
			move_left(tab);
//		mvprintw(10, 10,"|%d|", ch);
		refresh();
	}

	endwin();/*Curses close*/
	return (0);
}
