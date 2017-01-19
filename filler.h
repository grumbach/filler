/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:19:39 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 16:07:21 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

# define PLAYER_NAME "filler"

typedef struct	s_fill
{
	char		**map;
	char		**block;
	int			mapyx[2];
	int			blockyx[2];
	char		player;
}				t_fill;

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

int				blockplacer(t_fill *fill, t_xy *ret);
t_xy			xd_yd(t_fill *fill, t_xy dir);
t_xy			xd_yp(t_fill *fill, t_xy dir);
t_xy			xp_yd(t_fill *fill, t_xy dir);
t_xy			xp_yp(t_fill *fill, t_xy dir);
int				canplace(t_fill *fill, t_xy pos);
t_xy			go_top_left(t_fill *fill);
t_xy			go_bot_left(t_fill *fill);
t_xy			go_top_right(t_fill *fill);
t_xy			go_bot_right(t_fill *fill);

#endif
