/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_love.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 10:23:22 by agrumbac          #+#    #+#             */
/*   Updated: 2017/03/06 21:39:56 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	blockdist(t_fill *fill, t_xy him, t_xy me)
{
	int		xi;
	int		yi;
	int		dist;
	int		mydist;

	xi = -1;
	dist = 2147483647;
	while (++xi < fill->blockyx.x)
	{
		yi = -1;
		while (++yi < fill->blockyx.y)
		{
			if (fill->block[yi][xi] == FULL)
			{
				mydist = ft_sqrt(\
					ft_abs((him.y - me.y - yi) * (him.y - me.y - yi)) + \
					ft_abs((him.x - me.x - xi) * (him.x - me.x - xi)));
				if (mydist <= dist)
					dist = mydist;
			}
		}
	}
	return (dist);
}

static int	distance(t_fill *fill, t_xy try)
{
	int		xi;
	int		yi;
	int		dist;
	int		mydist;

	xi = -1;
	dist = 2147483647;
	while (++xi < fill->mapyx.x)
	{
		yi = -1;
		while (++yi < fill->mapyx.y)
		{
			if (fill->map[yi][xi] == enemy(fill->player))
			{
				mydist = blockdist(fill, (t_xy){yi, xi}, try);
				if (mydist <= dist)
					dist = mydist;
			}
		}
	}
	return (dist);
}

static int	stalker(t_fill *fill, t_xy try)
{
	static int	bestdist = 2147483647;

	if (!fill)
		return ((bestdist = 2147483647));
	if (canplace(fill, try))
	{
		if (distance(fill, try) <= bestdist)
		{
			bestdist = distance(fill, try);
			return (1);
		}
	}
	return (0);
}

t_xy		lover(t_fill *fill, t_xy start)
{
	stalker(NULL, start);//initalise bestdist
	return (tryblock(fill, start, &stalker));
}

t_xy		tryblock(t_fill *fill, t_xy start, int (*f)(t_fill *, t_xy))
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
