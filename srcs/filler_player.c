/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/29 22:23:41 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_xy		watchtower(t_fill *fill)//watch enemy's last move, ret opp dir
{
	static t_plan	plan;
	t_reach			enemy;
	t_reach			own;

	reach(fill, &own, &my_pos);//my reach
	reach(fill, &enemy, &enemy_pos);//enemy reach
	plan = planner(fill, &enemy, &own);
	ft_printf("mypos y+(%d), y-(%d), x+(%d), x-(%d)\n", \
	own.max.y, own.min.y, own.max.x, own.min.x);
	ft_printf("enemy y+(%d), y-(%d), x+(%d), x-(%d)\n",
	enemy.max.y, enemy.min.y, enemy.max.x, enemy.min.x);
	ft_printf("diff y+(%d), y-(%d), x+(%d), x-(%d)\n",
	own.max.y - enemy.max.y, own.min.y - enemy.min.y, \
	own.max.x - enemy.max.x, own.min.x - enemy.min.x);
	return (do_mission(&plan));
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
