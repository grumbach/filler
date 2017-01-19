/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_spy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:30:51 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 18:16:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		enemy(char player)
{
	if (player == PLAYER1)
		return (PLAYER2);
	else
		return (PLAYER1);
}

t_xy			enemy_last_move(t_fill *fill)
{
	t_xy	try;
	t_xy	last;

	last = (t_xy){-1, -1};
	try.x = fill->mapyx.x - 1;
	while (try.x >= 0)
	{
		try.y = fill->mapyx.y - 1;
		while (try.y >= 0)
		{
			if (fill->map[try.y][try.x] == enemy(fill->player))
				last = try;
			try.y--;
		}
		try.x--;
	}
	//ft_printf("enemy move : y=%d, x=%d", last.y, last.x);
	return (last);
}
