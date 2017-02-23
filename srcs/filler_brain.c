/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_brain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 23:59:34 by agrumbac          #+#    #+#             */
/*   Updated: 2017/02/23 14:05:33 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	pxd_yd(t_fill *fill, t_xy start, t_xy end, int (*f)(t_fill *, t_xy))
{
	t_xy	best;
	t_xy	try;

ft_printf("GRRRR\n");
	best = (t_xy){-1, -1};
	try.y = start.y;
	while (try.y >= end.y)
	{
		try.x = start.x;
		while (try.x >= end.x)
		{
			if (f(fill, try))
				best = try;
			try.x--;
		}
		try.y--;
	}
	return (best);
}

t_xy	pxd_yp(t_fill *fill, t_xy start, t_xy end, int (*f)(t_fill *, t_xy))
{
	t_xy	best;
	t_xy	try;

	best = (t_xy){-1, -1};
	try.x = start.x;
	while (try.x >= end.x)
	{
		try.y = start.y;
		while (try.y <= end.y)
		{
			if (f(fill, try))
				best = try;
			try.y++;
		}
		try.x--;
	}
	return (best);
}

t_xy	pxp_yd(t_fill *fill, t_xy start, t_xy end, int (*f)(t_fill *, t_xy))
{
	t_xy	best;
	t_xy	try;

	best = (t_xy){-1, -1};
	try.x = start.x;
	while (try.x <= end.x)
	{
		try.y = start.y;
		while (try.y >= end.y)
		{
			if (f(fill, try))
				best = try;
			try.y--;
		}
		try.x++;
	}
	return (best);
}

t_xy	pxp_yp(t_fill *fill, t_xy start, t_xy end, int (*f)(t_fill *, t_xy))
{
	t_xy	best;
	t_xy	try;

	best = (t_xy){-1, -1};
	try.y = start.y;
	while (try.y <= end.y)
	{
		try.x = start.x;
		while (try.x <= end.x)
		{
			if (f(fill, try))
				best = try;
			try.x++;
		}
		try.y++;
	}
	return (best);
}
