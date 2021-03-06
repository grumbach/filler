/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:48:43 by agrumbac          #+#    #+#             */
/*   Updated: 2017/03/06 20:21:21 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy		go_top_left(const t_fill *fill)
{
	t_xy	direction;

	direction.x = fill->mapyx.x - fill->blockyx.x;
	direction.y = fill->mapyx.y - fill->blockyx.y;
	return (direction);
}

t_xy		go_bot_left(const t_fill *fill)
{
	t_xy	direction;

	direction.x = fill->mapyx.x - fill->blockyx.x;
	direction.y = 0;
	return (direction);
}

t_xy		go_top_right(const t_fill *fill)
{
	t_xy	direction;

	direction.x = 0;
	direction.y = fill->mapyx.y - fill->blockyx.y;
	return (direction);
}

t_xy		go_bot_right(const t_fill *fill)
{
	t_xy	direction;

	(void)fill;
	direction.x = 0;
	direction.y = 0;
	return (direction);
}
