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

int		main(void)
{
//	WINDOW	*win;
	int		ch;

	initscr();/*Curses init*/
	keypad(stdscr, true);

	while(42)
	{
		ch = getch();
		if (ch == 27)
			ft_exit();
		mvprintw(10, 10,"|%d|", ch);
	}

	endwin();/*Curses close*/
	return (0);
}
