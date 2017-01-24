/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:18:10 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/24 05:09:56 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_fill(t_fill *fill)
{
	int			i;

	i = 0;
	while (i < fill->mapyx.y)
	{
		ft_memdel((void**)&(fill->map[i]));
		i++;
	}
	ft_memdel((void**)&(fill->map));
	i = 0;
	while (i < fill->blockyx.y)
	{
		ft_memdel((void**)&(fill->block[i]));
		i++;
	}
	ft_memdel((void**)&(fill->block));
}

static char		**map_read(int y, int x, int location, t_xy *yx)
{
	char		**map;
	char		*line;
	int			i;

	i = 0;
//							ft_printf("y=%d x=%d\n", y, x);
	*yx = (t_xy){y, x};
	map = ft_memalloc(y * sizeof(char*));
	if (location)
	{
		if (ft_get_next_line(0, &line) < 0)
			return (0);
		ft_memdel((void**)&line);
	}
	while (i < y)
	{
		if (ft_get_next_line(0, &line) < 0)
			return (0);
		if (!(map[i] = ft_strdup(line + location)))
			return (0);
//							ft_printf("%.3d %s\n", i, map[i]);
		i++;
		ft_memdel((void**)&line);
	}
	return (map);
}

static int		filler(t_fill *fill, t_xy *ret, char *line)
{
	int		gnl;

	gnl = 1;
//							ft_printf("%42	start parse\n");
	if (!line)
		gnl = ft_get_next_line(0, &line);
	while (gnl)
	{
//							ft_printf("%42	reading...\n");
//							ft_printf("%42	line{%s}\n", line);
		if (line[0] == 'P' && !(fill->map))
			fill->map = map_read(ft_atoi(line + 8), ft_atoi(line + 8 + \
				ft_intlen(ft_atoi(line + 8))), 4, &(fill->mapyx));
		else if (line[0] == 'P')
		{
			fill->block = map_read(ft_atoi(line + 6), ft_atoi(line + 6 + \
				ft_intlen(ft_atoi(line + 6))), 0, &(fill->blockyx));
			ft_memdel((void**)&line);
			if (!(blockplacer(fill, ret)))
				return (0);
			free_fill(fill);
			break ;
		}
		ft_memdel((void**)&line);
		gnl = ft_get_next_line(0, &line);
	}
	ft_memdel((void**)&line);
//							ft_printf("%42	end parse\n");
	return (1);
}

int				main(void)
{
	char		*line;
	t_fill		fill;
	t_xy		ret;
	int			gnl;

	ft_bzero(&fill, sizeof(t_fill));
	gnl = ft_get_next_line(0, &line);
//							ft_printf("%42	called me\n");
	while (gnl != -1)
	{
		if (gnl)
		{
			if (line[9] == 'p')
			{
				fill.player = (line[10] == '2' ? PLAYER2 : PLAYER1);
				if (!(filler(&fill, &ret, NULL)))
					return (0);
//							ft_printf("%42	player : %c\n", fill.player);
				ft_memdel((void**)&line);
			}
			else if (!(filler(&fill, &ret, line)))
				return (0);
//						ft_printf("%42	returned(%d %d)\n", ret.y, ret.x);
			ft_putstr(ft_itoa(ret.y));
			ft_putstr(" ");
			ft_putendl(ft_itoa(ret.x));
		}
		gnl = ft_get_next_line(0, &line);
	}
//							ft_printf("%42	bye\n");
	return (0);
}
