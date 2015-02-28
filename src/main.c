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

void	print_tab(char tab[4][4])
{
	int		x;
	int		y;

	x = 0;
	while (*tab[x])
	{
		y = 0;
		while (tab[y][x])
		{
			mvprintw(x * 2, y * 2, "%c", tab[y][x]);
			y++;
//			tab++;
		}
		x++;
//		*tab++;
	}
}

int		main(void)
{
//	WINDOW	*win;
	int		ch;
	t_win	win;

	char	tab[4][4] = {	{'.', '.', '.', '.'},
							{'.', '.', '4', '.'},
							{'2', '.', '.', '.'},
							{'.', '.', '.', '.'}};
	initscr();/*Curses init*/
	keypad(stdscr, true);
	getmaxyx(stdscr, win.my, win.mx);
	while(42)
	{
		ch = getch();
		win.lastx = win.mx;
		win.lasty = win.my;
		getmaxyx(stdscr, win.my, win.mx);
		box(stdscr, 0, '-');
		if(win.lastx != win.mx || win.lasty != win.my)
			wclear(stdscr);
		mvhline((win.my / 4) * 1, 1, '-', (win.mx - 2));
		mvhline((win.my / 4) * 2, 1, '-', (win.mx - 2));
		mvhline((win.my / 4) * 3, 1, '-', (win.mx - 2));
		mvvline(1, (win.mx / 4) * 1, '|', (win.my - 2));
		mvvline(1, (win.mx / 4) * 2, '|', (win.my - 2));
		mvvline(1, (win.mx / 4) * 3, '|', (win.my - 2));


		print_tab(tab);
		if (ch == 27)
			ft_exit();
//		mvprintw(10, 10,"|%d|", ch);
		refresh();
	}

	endwin();/*Curses close*/
	return (0);
}
