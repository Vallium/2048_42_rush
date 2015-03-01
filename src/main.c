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

void	ft_exit(int ind)
{
	endwin();
	if (ind == 1)
		ft_putendl_fd("exit", 1);
	if (ind == 2)
		ft_putendl_fd("window too small, program quited", 2);
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

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (x < 1 && tab[y][x + 1] == 0 && tab[y][x + 2] == 0 && tab[y][x] == tab[y][x + 3])
				tab[y][x] *= 2, tab[y][x + 3] = 0;
			else if (x < 2 && tab[y][x + 1] == 0 && tab[y][x] == tab[y][x + 2])
				tab[y][x] *= 2, tab[y][x + 2] = 0;
			else if (x != 3 && tab[y][x] == tab[y][x + 1])
				tab[y][x] *= 2, tab[y][x + 1] = 0;
		move_l(tab, y), move_l(tab, y), move_l(tab, y);
	}
}

void	move_right(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = 4;
		while (--x > -1)
			if (x > 2 && tab[y][x - 1] == 0 && tab[y][x - 2] == 0 && tab[y][x] == tab[y][x - 3])
				tab[y][x] *= 2, tab[y][x - 3] = 0;
			else if (x > 1 && tab[y][x - 1] == 0 && tab[y][x] == tab[y][x - 2])
				tab[y][x] *= 2, tab[y][x - 2] = 0;
			else if (x != 0 && tab[y][x] == tab[y][x - 1])
				tab[y][x] *= 2, tab[y][x - 1] = 0;
		move_r(tab, y), move_r(tab, y), move_r(tab, y);
	}
}

void	move_up(int tab[4][4])
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (y < 1 && tab[y + 1][x] == 0 && tab[y + 2][x] == 0 && tab[y][x] == tab[y + 3][x])
				tab[y][x] *= 2, tab[y + 3][x] = 0;
			else if (y < 2 && tab[y + 1][x] == 0 && tab[y][x] == tab[y + 2][x])
				tab[y][x] *= 2, tab[y + 2][x] = 0;
			else if (y != 3 && tab[y][x] == tab[y + 1][x])
				tab[y][x] *= 2, tab[y + 1][x] = 0;
		move_u(tab, x), move_u(tab, x), move_u(tab, x);
	}
}

void	move_down(int tab[4][4])
{
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 4;
		while (--y > -1)
		{
			if (y > 2 && tab[y - 1][x] == 0 && tab[y - 2][x] == 0 && tab[y][x] == tab[y - 3][x])
			{
				tab[y][x] *= 2;
				tab[y - 3][x] = 0;
			}
			else if (y > 1 && tab[y - 1][x] == 0 && tab[y][x] == tab[y - 2][x])
			{
				tab[y][x] *= 2;
				tab[y - 2][x] = 0;
			}
			else if (y != 0 && tab[y][x] == tab[y - 1][x])
			{
				tab[y][x] *= 2;
				tab[y - 1][x] = 0;
			}
		}
		move_d(tab, x), move_d(tab, x), move_d(tab, x);
		x++;
	}
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

int		grid_move(int tab[4][4], void (*f)(int[4][4]))
{
	int		oldtab[4][4];

	grid_cpy(tab, oldtab);
	f(tab);
	return (grid_cmp(tab, oldtab) ? 0 : 1);
}

void	print_tab(int tab[4][4], t_win *win)
{
//	WINDOW	*popup;
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
			if (tab[y][x])
				mvprintw((win->my / 8) * py, (win->mx / 8) * px, "%d", tab[y][x]);
			if (win->boul && tab[y][x] == WIN_VALUE)
			{
//				popup = newwin(10, 10, 10, 10);
//				box(popup, '&', '&');
//				wprintw(popup, "Gagne");
				mvprintw(10, 10, "gagne");
				win->boul = 0;
//				delwin(popup);
			}
			px += 2;
			x++;
		}
		py += 2;
		y++;
	}
}

int		rand_number(void)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 100 >= 90 ? 4 : 2;
	return (nb);
}

void	pop_number(int tab[4][4])
{
	int		x;
	int		y;
	int		rd;

	srand(time(NULL));
	rd = rand() % 20;
	while (42)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (!tab[y][x])
					rd--;
				if(!rd)
				{
					tab[y][x] = rand_number();
					return ;
				}
				x++;
			}
			y++;
		}
	}
}

int		rand_number_ini(void)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 100 >= 70 ? 4 : 2;
	return (nb);
}

void	grid_init(int tab[4][4])
{
	int		x;
	int		y;

	srand(time(NULL));
	x = rand() % 4;
	y = rand() % 4;
	tab[y][x] = rand_number_ini();
	while (42)
	{
		x = rand() % 4;
		y = rand() % 4;
		if (!tab[y][x])
		{
			tab[y][x] = 2;
			return ;
		}
	}
}

void	init_curses()
{
	initscr();
	start_color();
	keypad(stdscr, true);
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_RED,COLOR_WHITE);
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
		ft_exit(2);
	mvhline((win->my / 4) * 1, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 2, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 3, 1, '-', (win->mx - 2));
	mvvline(1, (win->mx / 4) * 1, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 2, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 3, '|', (win->my - 2));
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
	if ((WIN_VALUE & (WIN_VALUE - 1)))
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
		grid_responsive(stdscr, &win);

		print_tab(tab, &win);
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
		wclear(stdscr);
		refresh();
	}

	endwin();
	return (0);
}
