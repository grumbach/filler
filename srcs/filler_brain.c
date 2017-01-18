/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_brain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 23:59:34 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 00:10:36 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy		go_top_left(t_fill *fill)
{
	t_xy	direction;

	direction.x = fill->mapyx[1] - fill->blockyx[1];
	direction.y = fill->mapyx[0] - fill->blockyx[0];
	return (direction);
}

t_xy		go_bot_left(t_fill *fill)
{
	t_xy	direction;

	direction.x = fill->mapyx[1] - fill->blockyx[1];
	direction.y = 0;
	return (direction);
}

t_xy		go_top_right(t_fill *fill)
{
	t_xy	direction;

	direction.x = 0;
	direction.y = fill->mapyx[0] - fill->blockyx[0];
	return (direction);
}

t_xy		go_bot_right(t_fill *fill)
{
	t_xy	direction;

	direction.x = 0;
	direction.y = 0;
	return (direction);
}
