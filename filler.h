/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:19:39 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/19 18:08:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

# define PLAYER_NAME "filler"

# define PLAYER1 'o'
# define PLAYER2 'x'
# define EMPTY '.'
# define FULL '*'

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_fill
{
	char		**map;
	char		**block;
	t_xy		mapyx;
	t_xy		blockyx;
	char		player;
}				t_fill;

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
t_xy			enemy_last_move(t_fill *fill);

#endif
