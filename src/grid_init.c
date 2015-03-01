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
