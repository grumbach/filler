/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:18:10 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/16 09:39:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//connard
#include <stdio.h>

char	**map_read(int y, int location)
{
	char		**map;
	char		*line;
	int			i;

	ft_printf("y=%d\n", y);
	i = 0;
	map = ft_memalloc(y * sizeof(char*));
	if (location)
	{
		if (ft_get_next_line(0, &line) < 0)
			return (0);//skip 01234567890123..
		ft_memdel((void**)&line);
	}
	while (i < y)
	{
		if (ft_get_next_line(0, &line) < 0)
			return (0);
		if (!(map[i] = ft_strdup(line + location)))
			return (0);
		ft_printf("(%.3d) %s\n", i, map[i]);
		i++;
		ft_memdel((void**)&line);
	}
	return (map);
}

int		main(void)
{
	char		*line;
	t_fill		fill;

	fill = (t_fill){0, 0, 'o'};
	line = NULL;
	if (ft_get_next_line(0, &line) < 0)
		return (-1);
	if (line[10] == '2')
		fill.player = 'x';
	ft_printf("[player : %c]\n", fill.player);
	ft_memdel((void**)&line);
	while (ft_get_next_line(0, &line) > 0)
	{
		if (line[0] == 0)
			break ;
		else if (line[0] == 'P' && !(fill.map))
			fill.map = map_read(ft_atoi(line + 8), 4);
		else if (line[0] == 'P')
			fill.block = map_read(ft_atoi(line + 5), 0);
		ft_memdel((void**)&line);
	}
	ft_printf("==============END================\n");
	return (0);
}
