/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_brain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 23:59:34 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/29 22:22:58 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy		do_mission(t_plan *plan)
{
	if (plan->mission_a.x == -1 && plan->mission_a.y == -1)
	{
		if (plan->mission_b.x == -1 && plan->mission_b.y == -1)
			return (plan->mission_c);
		else
			return (plan->mission_b);
	}
	else
		return (plan->mission_a);
}

void		mission_complete(t_plan *plan, int n)
{
	if (n == 1)
		plan->mission_a = (t_xy){-1, -1};
	else if (n == 2)
		plan->mission_b = (t_xy){-1, -1};
}

t_plan		planner(t_fill *fill, t_reach *enemy, t_reach *own)
{
	t_plan	plan;

	if (own->max.x <= enemy->max.x)
	{
		if (own->max.y <= enemy->max.y)
		{
			plan.mission_a = go_bot_right(fill);
			plan.mission_b = go_top_left(fill);
		}
		else
		{
			plan.mission_a = go_top_right(fill);
			plan.mission_b = go_bot_left(fill);
		}
	}
	else
	{
		if (own->max.y <= enemy->max.y)
		{
			plan.mission_a = go_bot_left(fill);
			plan.mission_b = go_top_right(fill);
		}
		else
		{
			plan.mission_a = go_top_left(fill);
			plan.mission_b = go_bot_right(fill);
		}
	}
	// plan.mission_a = go_bot_left(fill);
	// plan.mission_b = go_bot_right(fill);
	// plan.mission_c = go_top_right(fill);
	//  (go_bot_left(fill));
	//  (go_top_left(fill));
	//  (go_bot_right(fill));
	//  (go_top_right(fill));
	return (plan);
}
