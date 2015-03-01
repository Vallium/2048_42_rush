/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:25:27 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/01 18:25:30 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		rand_number_ini(void)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 100 >= 70 ? 4 : 2;
	return (nb);
}

void			grid_init(int tab[4][4])
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
