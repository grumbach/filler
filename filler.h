/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:19:39 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 15:50:15 by agrumbac         ###   ########.fr       */
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

void			blockplacer(t_fill *fill, t_xy *ret);
t_xy			xd_yd(t_fill *fill, t_xy dir);
t_xy			xd_yp(t_fill *fill, t_xy dir);
t_xy			xp_yd(t_fill *fill, t_xy dir);
t_xy			xp_yp(t_fill *fill, t_xy dir);
int				canplace(t_fill *fill, t_xy pos);

#endif
