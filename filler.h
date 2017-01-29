/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:19:39 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/29 22:11:34 by agrumbac         ###   ########.fr       */
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
	int			y;
	int			x;
}				t_xy;

typedef struct	s_reach
{
	t_xy		max;
	t_xy		min;
}				t_reach;

typedef struct	s_fill
{
	char		**map;
	char		**block;
	t_xy		mapyx;
	t_xy		blockyx;
	char		player;
}				t_fill;

typedef struct	s_plan
{
	t_xy		mission_a;
	t_xy		mission_b;
	t_xy		mission_c;
}				t_plan;

int				blockplacer(t_fill *fill, t_xy *ret);
t_xy			xd_yd(t_fill *fill, t_xy start, t_xy end, \
				int (*f)(t_fill *, t_xy));
t_xy			xd_yp(t_fill *fill, t_xy start, t_xy end, \
				int (*f)(t_fill *, t_xy));
t_xy			xp_yd(t_fill *fill, t_xy start, t_xy end, \
				int (*f)(t_fill *, t_xy));
t_xy			xp_yp(t_fill *fill, t_xy start, t_xy end, \
				int (*f)(t_fill *, t_xy));
t_xy			go_top_left(t_fill *fill);
t_xy			go_bot_left(t_fill *fill);
t_xy			go_top_right(t_fill *fill);
t_xy			go_bot_right(t_fill *fill);
int				canplace(t_fill *fill, t_xy pos);
int				enemy_pos(t_fill *fill, t_xy try);
int				my_pos(t_fill *fill, t_xy try);
char			enemy(char player);
void			reach(t_fill *fill, t_reach *player, int (*f)(t_fill *, t_xy));
t_plan			planner(t_fill *fill, t_reach *enemy, t_reach *own);
void			mission_complete(t_plan *plan, int n);
t_xy			do_mission(t_plan *plan);

#endif
