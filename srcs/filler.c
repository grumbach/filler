/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:18:10 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/17 18:01:19 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_fill(t_fill *fill)
{
	int			i;

	i = 0;
	while (i < fill->mapyx[0])
	{
		free(fill->map[i]);
		i++;
	}
	free(fill->map);
	i = 0;
	while (i < fill->blockyx[0])
	{
		free(fill->block[i]);
		i++;
	}
	free(fill->block);
}

static char		**map_read(int y, int x, int location, int *yx)
{
	char		**map;
	char		*line;
	int			i;

	//ft_printf("y=%d x=%d\n", y, x);
	i = 0;
	yx[0] = y;
	yx[1] = x;
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
		//ft_printf("%.3d %s\n", i, map[i]);
		i++;
		ft_memdel((void**)&line);
	}
	return (map);
}

static int		filler(t_fill *fill, t_xy *ret)
{
	char		*line;

	ft_printf("%42	start parse\n");
	while (ft_get_next_line(0, &line) > 0)
	{
		ft_printf("%42	reading...\n");
		if (line[0] == 0)
			return (0);
		else if (line[0] == 'P' && !(fill->map))
			fill->map = map_read(ft_atoi(line + 8), ft_atoi(line + 8 + \
				ft_intlen(ft_atoi(line + 8))), 4, fill->mapyx);
		else if (line[0] == 'P')
		{
			fill->block = map_read(ft_atoi(line + 6), ft_atoi(line + 6 + \
				ft_intlen(ft_atoi(line + 6))), 0, fill->blockyx);
			ft_memdel((void**)&line);
			blockplacer(fill, ret);
			free_fill(fill);
			break ;
		}
		ft_memdel((void**)&line);
	}
	ft_printf("%42	end parse\n");
	return (1);
}

int				main(void)
{
	char		*line;
	t_fill		fill;
	t_xy		ret;

	ft_bzero(&fill, sizeof(t_fill));
	fill.player = 'o';
	line = NULL;
	if (ft_get_next_line(0, &line) < 0)
		return (-1);
	if (line[10] == '2')
		fill.player = 'x';
	ft_printf("%42	player : %c\n", fill.player);
	ft_memdel((void**)&line);
	while (filler(&fill, &ret))
	{
		ft_printf("%42	returned(%d %d)\n", ret.x, ret.y);
		ft_putstr(ft_itoa(ret.x));
		ft_putstr(" ");
		ft_putendl(ft_itoa(ret.y));
		sleep(1);
	}
	return (0);
}
