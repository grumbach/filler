/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_spy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:30:51 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/24 16:19:34 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			enemy(char player)
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

void			reach(t_fill *fill, t_reach *player, int (*f)(t_fill *, t_xy))
{
	player->max.y = xd_yp(fill, (t_xy){0, fill->mapyx.x - 1}, \
							(t_xy){fill->mapyx.y - 1, 0}, f).y;
	player->max.x = xp_yp(fill, (t_xy){0, 0}, \
							(t_xy){fill->mapyx.y - 1, fill->mapyx.x - 1}, f).x;
	player->min.y = xp_yd(fill, (t_xy){fill->mapyx.y - 1, 0}, \
							(t_xy){0, fill->mapyx.x - 1}, f).y;
	player->min.x = xd_yd(fill, (t_xy){fill->mapyx.y - 1, fill->mapyx.x - 1}, \
							(t_xy){0, 0}, f).x;
}

int				canplace(t_fill *fill, t_xy pos)
{
	t_xy	try;
	int		friendlies;

	friendlies = 0; //ft_printf("oh[%d,%d]", pos.y, pos.x);
	try.y = 0;
	while (try.y < fill->blockyx.y)
	{
		try.x = 0;
		while (try.x < fill->blockyx.x)
		{
			if (fill->block[try.y][try.x] == FULL)
			{
				if (fill->map[pos.y + try.y][pos.x + try.x] == fill->player || \
				fill->map[pos.y + try.y][pos.x + try.x] == fill->player - 32)
					friendlies++;
				else if (fill->map[pos.y + try.y][pos.x + try.x] == EMPTY)
					friendlies = friendlies;
				else
					return (0);
			}
			try.x++;
		}
		try.y++;
	}
	return (friendlies == 1 ? 1 : 0);//ft_printf("OK!");
}
