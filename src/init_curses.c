/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:51:49 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:51:51 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <signal.h>

static void		init_colors(void)
{
	init_color(10, 216, 212, 212);
	init_color(11, 851, 459, 145);
	init_color(12, 145, 851, 576);
	init_color(13, 278, 149, 47);
	init_color(14, 851, 145, 537);
	init_pair(1, 11, 10);
	init_pair(2, 12, 10);
	init_pair(3, 14, 13);
}

void			init_curses(t_win *win)
{
	win->boul = 1;
	initscr();
	if (has_colors() == false)
		ft_exit(4);
	start_color();
	init_colors();
	keypad(stdscr, true);
	curs_set(0);
	signal(SIGINT, SIG_IGN);
}
