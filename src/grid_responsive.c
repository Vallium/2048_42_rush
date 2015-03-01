/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_responsive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:51:38 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:51:40 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	grid_responsive(WINDOW *scr, t_win *win)
{
	bkgd(COLOR_PAIR(1));
	win->lastx = win->mx;
	win->lasty = win->my;
	getmaxyx(scr, win->my, win->mx);
	box(scr, 0, 0);
	if (win->lastx != win->mx || win->lasty != win->my)
		wclear(scr);
	if (win->mx < 46 || win->my < 25)
		ft_exit(3);
	mvhline((win->my / 4) * 1, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 2, 1, '-', (win->mx - 2));
	mvhline((win->my / 4) * 3, 1, '-', (win->mx - 2));
	mvvline(1, (win->mx / 4) * 1, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 2, '|', (win->my - 2));
	mvvline(1, (win->mx / 4) * 3, '|', (win->my - 2));
	attron(COLOR_PAIR(2));
}
