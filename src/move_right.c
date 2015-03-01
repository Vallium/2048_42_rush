/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:20:14 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/01 18:23:08 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	move_right(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = 4;
		while (--x > -1)
			if (x > 2 && tab[y][x - 1] == 0 && tab[y][x - 2] == 0 && tab[y][x]
					== tab[y][x - 3])
				tab[y][x] *= 2, tab[y][x - 3] = 0;
			else if (x > 1 && tab[y][x - 1] == 0 && tab[y][x] == tab[y][x - 2])
				tab[y][x] *= 2, tab[y][x - 2] = 0;
			else if (x != 0 && tab[y][x] == tab[y][x - 1])
				tab[y][x] *= 2, tab[y][x - 1] = 0;
		move_r(tab, y), move_r(tab, y), move_r(tab, y);
	}
}
