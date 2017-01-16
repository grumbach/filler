/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:19:39 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/16 09:30:38 by agrumbac         ###   ########.fr       */
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
	char		player;
}				t_fill;

#endif
