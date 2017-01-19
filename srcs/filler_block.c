/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:40:00 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 22:52:57 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	xd_yd(t_fill *fill, t_xy try, int (*f)(t_fill *, t_xy))
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (try.x >= 0)
	{
		try.y = fill->mapyx.y - fill->blockyx.y;
		while (try.y >= 0)
		{
			if (f(fill, try))
				best = try;
			try.y--;
		}
		try.x--;
	}
	return (best);
}

t_xy	xd_yp(t_fill *fill, t_xy try, int (*f)(t_fill *, t_xy))
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (try.y + fill->blockyx.y <= fill->mapyx.y)
	{
		try.x = fill->mapyx.x - fill->blockyx.x;
		while (try.x >= 0)
		{
			if (f(fill, try))
				best = try;
			try.x--;
		}
		try.y++;
	}
	return (best);
}

t_xy	xp_yd(t_fill *fill, t_xy try, int (*f)(t_fill *, t_xy))
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (try.y >= 0)
	{
		try.x = 0;
		while (try.x + fill->blockyx.x <= fill->mapyx.x)
		{
			if (f(fill, try))
				best = try;
			try.x++;
		}
		try.y--;
	}
	return (best);
}

t_xy	xp_yp(t_fill *fill, t_xy try, int (*f)(t_fill *, t_xy))
{
	t_xy	best;

	best = (t_xy){-1, -1};
	while (try.x + fill->blockyx.x <= fill->mapyx.x)
	{
		try.y = 0;
		while (try.y + fill->blockyx.y <= fill->mapyx.y)
		{
			if (f(fill, try))
				best = try;
			try.y++;
		}
		try.x++;
	}
	return (best);
}
