/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:01 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 16:46:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				canplace(t_fill *fill, t_xy pos)
{
	if (1)
		return (0);
	return (1);
}

static t_xy		watchtower(t_fill *fill)//watch enemy's last move, ret opposing dir
{
	t_xy	direction;

	ft_bzero(&direction, sizeof(t_xy));
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
}
