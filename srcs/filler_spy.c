/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_spy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:30:51 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 19:29:11 by agrumbac         ###   ########.fr       */
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

// t_xy			enemy_pos(t_fill *fill)
// {
// 	t_xy	try;
// 	t_xy	last;
//
// 	last = (t_xy){-1, -1};
// 	try.x = fill->mapyx.x - 1;
// 	while (try.x >= 0)
// 	{
// 		try.y = fill->mapyx.y - 1;
// 		while (try.y >= 0)
// 		{
// 			if (fill->map[try.y][try.x] == enemy(fill->player))
// 				last = try;
// 			try.y--;
// 		}
// 		try.x--;
// 	}
// 	ft_printf("enemy pos : y=%d, x=%d\n", last.y, last.x);
// 	return (last);
// }
// t_xy			my_pos(t_fill *fill)
// {
// 	t_xy	try;
// 	t_xy	last;
//
// 	last = (t_xy){-1, -1};
// 	try.x = fill->mapyx.x - 1;
// 	while (try.x >= 0)
// 	{
// 		try.y = fill->mapyx.y - 1;
// 		while (try.y >= 0)
// 		{
// 			if (fill->map[try.y][try.x] == fill->player - 32)
// 				last = try;
// 			try.y--;
// 		}
// 		try.x--;
// 	}
// 	ft_printf("my pos : y=%d, x=%d\n", last.y, last.x);
// 	return (last);
// }
