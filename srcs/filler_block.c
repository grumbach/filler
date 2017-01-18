/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:40:00 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 16:46:05 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	xd_yd(t_fill *fill, t_xy dir)
{
	t_xy	best;

	best = (t_xy){0, 0};
	while (dir.x)
	{
		while (dir.y)
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
	while (dir.x)
	{
		while (dir.y)
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
	while (dir.x)
	{
		while (dir.y)
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
	while (dir.x)
	{
		while (dir.y)
		{
			if (canplace(fill, dir))
				best = dir;
			dir.y++;
		}
		dir.x++;
	}
	return (best);
}
