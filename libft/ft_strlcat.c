/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:12:29 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 23:44:43 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** @size: supposed total bytes of the resulting string                         |
** Append untill @size is hit OR @src ends                                     |
** @ret: the len of the resulting string                                       |
** -----------------------------------------------------------------------------
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count_dest;
	size_t	i;
	size_t	res;

	count_dest = ft_strlen(dst);
	res = ft_strlen(src);
	(size <= count_dest) ? (res += size) : (res += count_dest);
	i = 0;
	while (src[i] && count_dest + 1 < size)
	{
		dst[count_dest] = src[i];
		count_dest++;
		i++;
	}
	dst[count_dest] = 0;
	return (res);
}
