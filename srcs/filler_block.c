/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:40:00 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 21:39:14 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	xd_yd(t_fill *fill, t_xy dir)
{
	t_xy	best;

	best = (t_xy){0, 0};
	while (dir.x >= 0)
	{
		dir.y = fill->mapyx[0];
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

	best = (t_xy){0, 0};
	while (dir.x >= 0)
	{
		dir.y = 0;
		while (dir.y + fill->blockyx[0] <= fill->mapyx[0])
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

	best = (t_xy){0, 0};
	while (dir.x + fill->blockyx[1] <= fill->mapyx[1])
	{
		dir.y = fill->mapyx[0];
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

	best = (t_xy){0, 0};
	while (dir.x + fill->blockyx[1] <= fill->mapyx[1])
	{
		dir.y = 0;
		while (dir.y + fill->blockyx[0] <= fill->mapyx[0])
		{
			if (canplace(fill, dir))
				best = dir;
			dir.y++;
		}
		dir.x++;
	}
	return (best);
}
