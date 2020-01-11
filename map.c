/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 01:33:06 by aelouazz          #+#    #+#             */
/*   Updated: 2019/07/15 01:20:08 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**map_it(int sz)
{
	char	**map;
	int		i;

	map = (char**)ft_memalloc(sizeof(char *) * sz + 1);
	map[sz] = NULL;
	i = 0;
	while (i < sz)
	{
		map[i] = ft_strnew(sz);
		ft_memset(map[i++], '.', sz);
	}
	return (map);
}

void		print_map(char **map)
{
	while (*map)
		ft_putendl(*map++);
}

void		free_map(char **map, int map_size)
{
	int		i;

	i = -1;
	while (++i < map_size)
		free(map[i]);
	free(map);
}

int			check_place(char **map, t_tet *piece, t_point point)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < 4)
	{
		if (map[piece->row[i] + point.y][piece->col[i] + point.x] == '.')
			j++;
	}
	return ((j == 4) ? 1 : 0);
}

int			set_piece(char **map, t_tet *piece, t_point point, char letter)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (ft_isalpha(letter))
		{
			if (map[piece->row[i] + point.y][piece->col[i] + point.x] == '.')
				map[piece->row[i] + point.y][piece->col[i] + point.x] = letter;
			else
				return (0);
		}
		else
		{
			if (map[piece->row[i] + point.y][piece->col[i] +
					point.x] == piece->letter)
				map[piece->row[i] + point.y][piece->col[i] + point.x] = letter;
			else
				return (0);
		}
	}
	return (1);
}
