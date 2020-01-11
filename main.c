/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <aelouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 00:51:11 by aelouazz          #+#    #+#             */
/*   Updated: 2019/07/19 13:37:58 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					my_sqrt(int nbr)
{
	int				nb;

	nb = nbr;
	while (nb * nb > nbr && nb >= 0)
		nb--;
	return ((nbr % nb) == 0 ? (nb) : (nb + 1));
}

int					ft_min(int *pos)
{
	int				min;
	int				i;

	i = 0;
	min = pos[0];
	while (++i < 4)
		if (pos[i] < min)
			min = pos[i];
	return (min);
}

int					ft_max(int *pos)
{
	int				max;
	int				i;

	i = 0;
	max = pos[0];
	while (++i < 4)
		if (pos[i] > max)
			max = pos[i];
	return (max);
}

int					print_error(char *msg)
{
	ft_putendl(msg);
	return (0);
}

int					main(int ac, char **av)
{
	t_tet			*list[26];
	int				fd;
	int				map_size;
	char			**map;

	map_size = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (print_error("usage: ./fillit [file]"));
	if (!validation(fd, list, &map_size))
		return (print_error("error"));
	extraction(list);
	map_size = my_sqrt(map_size * 4);
	map = map_it(map_size);
	while (!wtf(map, list, map_size, 0))
	{
		free_map(map, map_size);
		map_size++;
		map = map_it(map_size);
	}
	print_map(map);
	return (free_all(map, map_size, list));
}
