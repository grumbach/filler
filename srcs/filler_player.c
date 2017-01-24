/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/24 07:33:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

static t_xy		watchtower(t_fill *fill)//watch enemy's last move, ret opp dir
{
	static int		rando = 0;
	static t_reach	enemy;
	static t_reach	own;

	reach(fill, &own, &my_pos);//my reach
	// ft_printf("mypos y+(%d), y-(%d), x+(%d), x-(%d)\n", \
	// own.max.y, own.min.y, own.max.x, own.min.x);
	reach(fill, &enemy, &enemy_pos);//enemy reach
	ft_printf("enemy y+(%d), y-(%d), x+(%d), x-(%d)\n",
	enemy.max.y, enemy.min.y, enemy.max.x, enemy.min.x);
	ft_printf("diff y+(%d), y-(%d), x+(%d), x-(%d)\n",
	own.max.y - enemy.max.y, own.min.y - enemy.min.y, \
	own.max.x - enemy.max.x, own.min.x - enemy.min.x);
	rando++;
	if (rando % 4 == 0)
		return (go_bot_left(fill));
	if (rando % 3 == 0)
		return (go_top_left(fill));
	if (rando % 2 == 0)
		return (go_bot_right(fill));
	else
		return (go_top_right(fill));
}

static t_xy		tryblock(t_fill *fill, t_xy start)//place bloc in dir ret xy
{
	if (start.x)
	{
		if (start.y)
			return (xd_yd(fill, start, go_bot_right(fill), &canplace));
		else
			return (xd_yp(fill, start, go_top_right(fill), &canplace));
	}
	else
	{
		if (start.y)
			return (xp_yd(fill, start, go_bot_left(fill), &canplace));
		else
			return (xp_yp(fill, start, go_top_left(fill), &canplace));
	}
}

int				blockplacer(t_fill *fill, t_xy *ret)
{
	*ret = tryblock(fill, watchtower(fill));
	if (ret->x == -1 || ret->y == -1)
		return (0);
	return (1);
}
