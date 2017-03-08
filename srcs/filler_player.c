/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/03/08 03:57:32 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_xy		direction(const t_fill *fill, int dir)
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

static int		enemy_dir(const t_reach *enemy, const t_reach *own)
{
	if (own->max.x <= enemy->max.x)
	{
		if (own->max.y <= enemy->max.y)
			return (180);
		else
			return (90);
	}
	else
	{
		if (own->max.y <= enemy->max.y)
			return (270);
		else
			return (0);
	}
}

static int		reached_dir(const t_fill *fill, int dir, const t_reach reach)
{
	dir %= 360;
	if (dir == 0)
		return (reach.min.y == 0 ? 1 : 0);
	if (dir == 90)
		return (reach.max.x == fill->mapyx.x - 1 ? 1 : 0);
	if (dir == 180)
		return (reach.max.y == fill->mapyx.y - 1 ? 1 : 0);
	else
		return (reach.min.x == 0 ? 1 : 0);
}

static t_xy		watchtower(t_fill *fill)
{
	t_reach			enemy;
	t_reach			own;
	static int		enemy_d = -1;

	reach(fill, &own, &my_pos);
	reach(fill, &enemy, &enemy_pos);
	if (enemy_d == -1)
		enemy_d = enemy_dir(&enemy, &own);
	if (!(reached_dir(fill, enemy_d, own) || reached_dir(fill, enemy_d, enemy)))
	{
		fill->p = 0;
		if (!reached_dir(fill, enemy_d + 90, enemy))
			return (tryblock(fill, direction(fill, enemy_d), &canplace));
	}
	fill->p = 1;
	if (reached_dir(fill, enemy_d + 180, enemy))
		return (lover(fill, direction(fill, enemy_d + 180)));
	return (lover(fill, direction(fill, enemy_d)));
}

int				blockplacer(t_fill *fill, t_xy *ret)
{
	*ret = watchtower(fill);
	return (1);
}
