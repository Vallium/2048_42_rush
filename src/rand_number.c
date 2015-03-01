/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:24:46 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/01 18:24:48 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		rand_number(void)
{
	int		nb;

	srand(time(NULL));
	nb = rand() % 100 >= 90 ? 4 : 2;
	return (nb);
}