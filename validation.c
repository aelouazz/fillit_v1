/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <aelouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:48:52 by aelouazz          #+#    #+#             */
/*   Updated: 2019/07/19 13:38:28 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			newlines(char *buff, int i)
{
	if ((buff[4] != '\n') || (buff[9] != '\n') || (buff[14] != '\n') ||
		(buff[19] != '\n'))
		return (0);
	if (i == 0)
		return (1);
	if ((buff[20] && (buff[20] != '\n')))
		return (0);
	return (1);
}

int			conn(char *buff)
{
	int		t;
	int		i;

	t = 0;
	i = -1;
	while (buff && buff[++i])
	{
		if (buff[i] == '#')
		{
			t += (((i >= 5) && (buff[i - 5] == '#')) ? 1 : 0);
			t += (((i >= 1) && (buff[i - 1] == '#')) ? 1 : 0);
			t += (((i <= 13) && (buff[i + 5] == '#')) ? 1 : 0);
			t += (((i <= 17) && (buff[i + 1] == '#')) ? 1 : 0);
		}
	}
	return ((t >= 6) ? 1 : 0);
}

int			count_all(char *buff, int i)
{
	int		dots;
	int		hash;
	int		nls;

	nls = 0;
	hash = 0;
	dots = 0;
	if (newlines(buff, i) == 1)
		while (*buff != '\0')
		{
			if (*buff == '.')
				dots++;
			if (*buff == '#')
				hash++;
			buff++;
		}
	return (((hash == 4) && (dots == 12) ? 1 : 0));
}

int			validation(int fd, t_tet **list, int *nbr_p)
{
	int		i;
	int		res;
	char	buff[22];

	i = 0;
	while ((res = read(fd, buff, 21)))
	{
		buff[res] = '\0';
		if (!(count_all(buff, i)) || !(conn(buff)) || i >= 26)
			return (0);
		list[i] = (t_tet*)ft_memalloc(sizeof(t_tet));
		ft_memcpy(list[i]->set, buff, 21);
		i++;
		ft_strclr(buff);
	}
	list[i] = 0;
	*nbr_p = i;
	if (i != 0)
		if ((list[i - 1]->set[20] == '\0') && (i <= 26))
			return (1);
	return (0);
}
