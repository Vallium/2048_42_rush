/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:49:51 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/01 18:49:52 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_exit(int ind)
{
	endwin();
	if (ind == 1)
		ft_putendl_fd("exit", 1);
	else if (ind == 2)
		ft_putendl_fd("YOU ARE A HUSS PLAYER! Program quited", 2);
	else if (ind == 3)
		ft_putendl_fd("You just tried a too small window BITCH!", 2);
	exit(0);
}
