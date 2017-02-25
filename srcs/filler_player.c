/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/02/25 15:16:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_xy		direction(t_fill *fill, int dir)
{
	dir %= 360;
	if (dir == 0)
		return (go_top_left(fill));
	if (dir == 90)
		return (go_top_right(fill));
	if (dir == 180)
		return (go_bot_right(fill));
	else
		return (go_bot_left(fill));
}

static int		enemy_dir(t_reach *enemy, t_reach *own)
{
	if (own->max.x <= enemy->max.x)
	{
		if (own->max.y <= enemy->max.y)
			return(180);
		else
			return(90);
	}
	else
	{
		if (own->max.y <= enemy->max.y)
			return(270);
		else
			return(0);
	}
}

static t_xy		watchtower(t_fill *fill)//watch enemy's last move, ret opp dir
{
	t_reach			enemy;
	t_reach			own;
	int				go;
	static int		enemy_d = -1;

	reach(fill, &own, &my_pos);//my reach
	reach(fill, &enemy, &enemy_pos);//enemy reach
	if (enemy_d == -1)
		enemy_d = enemy_dir(&enemy, &own);
	go = enemy_d + 90;
	if (((enemy_d > 90) && \
			(enemy.max.y < own.max.y - 2)) || \
			((enemy_d <= 90) && \
			(enemy.min.y > own.min.y + 2))) // crossy enemy
	{
		go = enemy_d;
		fill->p = 0;
	}
	return (lover(fill, direction(fill, go)));
}

t_xy			tryblock(t_fill *fill, t_xy start, int (*f)(t_fill *, t_xy))
{
	if (start.x)
	{
		if (start.y)
			return (fill->p ? xd_yd(fill, start, go_bot_right(fill), f)\
			: pxd_yd(fill, start, go_bot_right(fill), f));
		else
			return (fill->p ? xd_yp(fill, start, go_top_right(fill), f)\
			: pxd_yp(fill, start, go_top_right(fill), f));
	}
	else
	{
		if (start.y)
			return (fill->p ? xp_yd(fill, start, go_bot_left(fill), f)\
			: pxp_yd(fill, start, go_bot_left(fill), f));
		else
			return (fill->p ? xp_yp(fill, start, go_top_left(fill), f)\
			: pxp_yp(fill, start, go_top_left(fill), f));
	}
}

int				blockplacer(t_fill *fill, t_xy *ret)
{
	*ret = watchtower(fill);
	if (ret->x == -1 || ret->y == -1)
		return (0);
	return (1);
}
