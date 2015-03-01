/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:50:06 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:50:09 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	grid_check(int tab[4][4])
{
	int		nxt_tab[4][4];

	grid_cpy(tab, nxt_tab);
	if (grid_move(nxt_tab, move_up))
		pop_number(nxt_tab);
	if (grid_move(nxt_tab, move_down))
		pop_number(nxt_tab);
	if (grid_move(nxt_tab, move_right))
		pop_number(nxt_tab);
	if (grid_move(nxt_tab, move_left))
		pop_number(nxt_tab);
	if (grid_cmp(tab, nxt_tab))
	{
		ft_exit(2);
	}
}
