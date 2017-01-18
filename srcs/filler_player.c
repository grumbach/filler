/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 23:52:11 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				canplace(t_fill *fill, t_xy pos)
{
	t_xy	try;
	int		friendlies;

	ft_printf("oh[%d,%d]", pos.y, pos.x);
	friendlies = 0;
	try.y = 0;
	while (try.y < fill->blockyx[0])
	{
		try.x = 0;
		while (try.x < fill->blockyx[1])
		{
			if (fill->block[try.y][try.x] == '*')
			{
				if (fill->map[pos.y + try.y][pos.x + try.x] == fill->player || \
				fill->map[pos.y + try.y][pos.x + try.x] == fill->player - 32)
					friendlies++;
				else if (fill->map[pos.y + try.y][pos.x + try.x] == '.')
					friendlies = friendlies;
				else
					return (0);
			}
			try.x++;
		}
		try.y++;
	}
	if (friendlies != 1)
		return (0);
	ft_printf("OK!");
	return (1);
}

static t_xy		watchtower(t_fill *fill)//watch enemy's last move, ret opp dir
{
	t_xy	direction;

	//ft_bzero(&direction, sizeof(t_xy));
	direction.x = fill->mapyx[1] - fill->blockyx[1];
	direction.y = fill->mapyx[0] - fill->blockyx[0];
	return (direction);
}

static t_xy		tryblock(t_fill *fill, t_xy dir)//place bloc in dir ret xy
{
	if (dir.x)
	{
		if(dir.y)
			return (xd_yd(fill, dir));
		else
			return (xd_yp(fill, dir));
	}
	else
	{
		if(dir.y)
			return (xp_yd(fill, dir));
		else
			return (xp_yp(fill, dir));
	}
}

void			blockplacer(t_fill *fill, t_xy *ret)
{
	*ret = tryblock(fill, watchtower(fill));
	if (!(ret->x || ret->y))
		exit(0);
}
