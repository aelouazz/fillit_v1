/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 00:51:29 by aelouazz          #+#    #+#             */
/*   Updated: 2019/07/15 01:01:54 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		extracting(t_tet *list)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = -1;
	y = -1;
	while (++y < 4)
	{
		while (++x < 4)
			list->table[y][x] = list->set[i++];
		list->table[y][4] = '\0';
		i++;
		x = -1;
	}
}

void			shifting(t_tet *list)
{
	int		mrow;
	int		mcol;
	int		i;

	i = -1;
	mrow = ft_min(list->row);
	mcol = ft_min(list->col);
	while (++i < 4)
	{
		list->row[i] -= mrow;
		list->col[i] -= mcol;
	}
}

void			fill_points(t_tet *list)
{
	int			j;
	int			k;
	int			x;

	x = 0;
	j = -1;
	while (++j < 4)
	{
		k = -1;
		while (++k < 4)
		{
			if (list->table[j][k] == '#')
			{
				list->row[x] = j;
				list->col[x++] = k;
			}
		}
	}
}

void			extraction(t_tet **list)
{
	int			i;

	i = -1;
	while (list[++i])
	{
		extracting(list[i]);
		fill_points(list[i]);
		shifting(list[i]);
		list[i]->letter = 'A' + i;
		list[i]->height = ft_max(list[i]->row) + 1;
		list[i]->width = ft_max(list[i]->col) + 1;
	}
}
