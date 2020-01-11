/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_getting_beaten.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 03:50:13 by aelouazz          #+#    #+#             */
/*   Updated: 2019/07/18 04:37:18 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					free_all(char **map, int map_size, t_tet **list)
{
	free_map(map, map_size);
	while (*list)
		free(*list++);
	return (0);
}

static void			del_piece(char **map, char letter, int map_size)
{
	int			i;
	int			j;

	i = -1;
	while (++i < map_size)
	{
		j = -1;
		while (++j < map_size)
		{
			if (map[i][j] == letter)
				map[i][j] = '.';
		}
	}
}

int					wtf(char **map, t_tet **list, int map_size, int i)
{
	t_point			point;

	point.y = 0;
	if (list[i] == NULL)
		return (1);
	while (point.y < map_size - list[i]->height + 1)
	{
		point.x = 0;
		while (point.x < map_size - list[i]->width + 1)
		{
			if (check_place(map, list[i], point))
			{
				set_piece(map, list[i], point, list[i]->letter);
				if (wtf(map, list, map_size, i + 1))
					return (1);
				else
					del_piece(map, list[i]->letter, map_size);
			}
			point.x++;
		}
		point.y++;
	}
	return (0);
}
