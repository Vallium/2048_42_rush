/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:55:25 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/27 20:56:06 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

#include "libft.h"
#include <time.h>
#include <stdlib.h>
#include <curses.h>
#include <game.h>

typedef enum	e_const
{
	WIN_VALUE = 2048
}				t_const;

typedef struct	s_win
{
	int			lastx;
	int			lasty;
	int			mx;
	int			my;
	int			boul;
}				t_win;

void			init_curses();
void			grid_responsive(WINDOW *scr, t_win *win);

void			ft_exit(int ind);
void			grid_cpy(int src[4][4], int dst[4][4]);
int				grid_cmp(int tab[4][4], int tab2[4][4]);
int				grid_move(int tab[4][4], void (*f)(int[4][4]));
void			print_tab(int tab[4][4], t_win *win);

void			move_r(int tab[4][4], int y);
void			move_l(int tab[4][4], int y);
void			move_left(int tab[4][4]);
void			move_right(int tab[4][4]);

void			move_u(int tab[4][4], int x);
void			move_d(int tab[4][4], int x);
void			move_up(int tab[4][4]);
void			move_down(int tab[4][4]);

int				rand_number(void);
void			pop_number(int tab[4][4]);
int				rand_number_ini(void);
void			grid_init(int tab[4][4]);

#endif
