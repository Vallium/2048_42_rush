/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:52:48 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:52:55 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		move_d(int tab[4][4], int x)
{
	int		y;

	y = 3;
	while (--y > -1)
		if (tab[y + 1][x] == 0)
		{
			tab[y + 1][x] = tab[y][x];
			tab[y][x] = 0;
		}
}

void			move_down(int tab[4][4])
{
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 4;
		while (--y > -1)
			if (y > 2 && tab[y - 1][x] == 0 && tab[y - 2][x] == 0
					&& tab[y][x] == tab[y - 3][x])
				tab[y][x] *= 2, tab[y - 3][x] = 0;
			else if (y > 1 && tab[y - 1][x] == 0 && tab[y][x] == tab[y - 2][x])
				tab[y][x] *= 2, tab[y - 2][x] = 0;
			else if (y != 0 && tab[y][x] == tab[y - 1][x])
				tab[y][x] *= 2, tab[y - 1][x] = 0;
		move_d(tab, x), move_d(tab, x), move_d(tab, x);
		x++;
	}
}
