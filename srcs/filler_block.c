/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:40:00 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 17:41:07 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	xd_yd(t_fill *fill, t_xy dir)
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (dir.x >= 0)
	{
		dir.y = fill->mapyx.y - fill->blockyx.y;
		while (dir.y >= 0)
		{
			if (canplace(fill, dir))
				best = dir;
			dir.y--;
		}
		dir.x--;
	}
	return (best);
}

t_xy	xd_yp(t_fill *fill, t_xy dir)
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (dir.x >= 0)
	{
		dir.y = 0;
		while (dir.y + fill->blockyx.y <= fill->mapyx.y)
		{
			if (canplace(fill, dir))
				best = dir;
			dir.y++;
		}
		dir.x--;
	}
	return (best);
}

t_xy	xp_yd(t_fill *fill, t_xy dir)
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (dir.x + fill->blockyx.x <= fill->mapyx.x)
	{
		dir.y = fill->mapyx.y - fill->blockyx.y;
		while (dir.y >= 0)
		{
			if (canplace(fill, dir))
				best = dir;
			dir.y--;
		}
		dir.x++;
	}
	return (best);
}

t_xy	xp_yp(t_fill *fill, t_xy dir)
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (dir.x + fill->blockyx.x <= fill->mapyx.x)
	{
		dir.y = 0;
		while (dir.y + fill->blockyx.y <= fill->mapyx.y)
		{
			if (canplace(fill, dir))
				best = dir;
			dir.y++;
		}
		dir.x++;
	}
	return (best);
}
