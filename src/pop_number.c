/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:24:59 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/01 18:27:44 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	pop_number(int tab[4][4])
{
	int		x;
	int		y;
	int		rd;

	srand(time(NULL));
	rd = rand() % 20;
	while (42)
	{
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				if (!tab[y][x])
					rd--;
				if (!rd)
				{
					tab[y][x] = rand_number();
					return ;
				}
			}
		}
	}
}
