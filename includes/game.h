/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:55:25 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/27 20:56:06 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

#include "libft.h"
#include <time.h>

typedef enum	e_const
{
	WIN_VALUE = 2048
}				t_const;

typedef struct	s_win
{
	int			lastx;
	int			lasty;
	int			mx;
	int			my;
	int			boul;
}				t_win;

#endif
