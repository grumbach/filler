/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/02/23 14:08:48 by agrumbac         ###   ########.fr       */
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
	if (direction(fill, enemy_d + 180).x == (enemy_d > 90 ? own.max.x : own.min.x) &&\
		direction(fill, enemy_d + 180).y == (enemy_d > 90 ? own.max.y : own.min.y))// objective complete
	{
		go = enemy_d - 90;
		fill->p = 1;
		ft_printf("ASSSEEKERON!! :D\n");
	}
	else if (((enemy_d > 90) && \
			(enemy.max.y < own.max.y - 2)) || \
			((enemy_d <= 90) && \
			(enemy.min.y > own.min.y + 2))) // crossy enemy
	{
		go = enemy_d;
		fill->p = 0;
		ft_printf("CROSSED!!! :D\n");
	}
	else
	{
		go = enemy_d + 90;
		fill->p = 1;
		ft_printf("SHIT\n");
	}

	// ft_printf("mypos y+(%d), y-(%d), x+(%d), x-(%d)\n", \
	// own.max.y, own.min.y, own.max.x, own.min.x);
	// ft_printf("enemy y+(%d), y-(%d), x+(%d), x-(%d)\n",
	// enemy.max.y, enemy.min.y, enemy.max.x, enemy.min.x);
	// ft_printf("diff y+(%d), y-(%d), x+(%d), x-(%d)\n",
	// own.max.y - enemy.max.y, own.min.y - enemy.min.y, \
	// own.max.x - enemy.max.x, own.min.x - enemy.min.x);
	return (direction(fill, go));
}

static t_xy		tryblock(t_fill *fill, t_xy start)//place bloc in dir ret xy
{
	if (start.x)
	{
		if (start.y)
			return (fill->p ? xd_yd(fill, start, go_bot_right(fill), &canplace)\
			: pxd_yd(fill, start, go_bot_right(fill), &canplace));
		else
			return (fill->p ? xd_yp(fill, start, go_top_right(fill), &canplace)\
			: pxd_yp(fill, start, go_top_right(fill), &canplace));
	}
	else
	{
		if (start.y)
			return (fill->p ? xp_yd(fill, start, go_bot_left(fill), &canplace)\
			: pxp_yd(fill, start, go_bot_left(fill), &canplace));
		else
			return (fill->p ? xp_yp(fill, start, go_top_left(fill), &canplace)\
			: pxp_yp(fill, start, go_top_left(fill), &canplace));
	}
}

int				blockplacer(t_fill *fill, t_xy *ret)
{
	*ret = tryblock(fill, watchtower(fill));
	if (ret->x == -1 || ret->y == -1)
		return (0);
	return (1);
}
