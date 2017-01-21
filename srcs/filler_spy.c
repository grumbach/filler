/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_spy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:30:51 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/21 18:23:29 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		enemy(char player)
{
	if (player == PLAYER1)
		return (PLAYER2 - 32);
	else
		return (PLAYER1 - 32);
}

int				enemy_pos(t_fill *fill, t_xy try)
{
	return (fill->map[try.y][try.x] == enemy(fill->player) ? 1 : 0);
}

int				my_pos(t_fill *fill, t_xy try)
{
	return (fill->map[try.y][try.x] == fill->player - 32 ? 1 : 0);
}
