/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:19:04 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/01 18:22:24 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	move_left(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (x < 1 && tab[y][x + 1] == 0 && tab[y][x + 2] == 0 && tab[y][x]
					== tab[y][x + 3])
				tab[y][x] *= 2, tab[y][x + 3] = 0;
			else if (x < 2 && tab[y][x + 1] == 0 && tab[y][x] == tab[y][x + 2])
				tab[y][x] *= 2, tab[y][x + 2] = 0;
			else if (x != 3 && tab[y][x] == tab[y][x + 1])
				tab[y][x] *= 2, tab[y][x + 1] = 0;
		move_l(tab, y), move_l(tab, y), move_l(tab, y);
	}
}
