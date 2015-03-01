/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:52:39 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:52:41 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		move_u(int tab[4][4], int x)
{
	int		y;

	y = 0;
	while (++y < 4)
		if (tab[y - 1][x] == 0)
		{
			tab[y - 1][x] = tab[y][x];
			tab[y][x] = 0;
		}
}

void			move_up(int tab[4][4])
{
	int		x;
	int		y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (y < 1 && tab[y + 1][x] == 0 && tab[y + 2][x] == 0 &&
					tab[y][x] == tab[y + 3][x])
				tab[y][x] *= 2, tab[y + 3][x] = 0;
			else if (y < 2 && tab[y + 1][x] == 0 && tab[y][x] == tab[y + 2][x])
				tab[y][x] *= 2, tab[y + 2][x] = 0;
			else if (y != 3 && tab[y][x] == tab[y + 1][x])
				tab[y][x] *= 2, tab[y + 1][x] = 0;
		move_u(tab, x), move_u(tab, x), move_u(tab, x);
	}
}
