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

void	print_tab(char **tab)
{
	int		x;
	int		y;

	x = 0;
	while (**tab)
	{
		y = 0;
		while (*tab)
		{
			mvprintw(x * 2, y * 2, "%c", *tab);
			y++;
			tab++;
		}
		x++;
		(*tab)++;
	}
}

int		main(void)
{
//	WINDOW	*win;
	int		ch;
	int		lastx;
	int		lasty;
	int		mx;
	int		my;

//	char	tab[4][4] = {	{'.', '.', '.', '.'},
//							{'.', '.', '4', '.'},
//							{'2', '.', '.', '.'},
//							{'.', '.', '.', '.'}};
	initscr();/*Curses init*/
	keypad(stdscr, true);
	getmaxyx(stdscr, my, mx);
	while(42)
	{
		ch = getch();
		lastx = mx;
		lasty = my;
		getmaxyx(stdscr, my, mx);
		box(stdscr, 0, '-');
		if(lastx != mx || lasty != my)
			wclear(stdscr);
		mvhline((my / 4) * 1, 1, '-', (mx - 2));
		mvhline((my / 4) * 2, 1, '-', (mx - 2));
		mvhline((my / 4) * 3, 1, '-', (mx - 2));
		mvvline(1, (mx / 4) * 1, '|', (my - 2));
		mvvline(1, (mx / 4) * 2, '|', (my - 2));
		mvvline(1, (mx / 4) * 3, '|', (my - 2));


//		print_tab(tab);
		if (ch == 27)
			ft_exit();
//		mvprintw(10, 10,"|%d|", ch);
		refresh();
	}

	endwin();/*Curses close*/
	return (0);
}
