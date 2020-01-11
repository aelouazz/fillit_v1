/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 05:16:31 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 02:41:24 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ----------------------------------------------------------------------------
** locates the first occurrence of @c in @s within the first @n bytes         |
** ----------------------------------------------------------------------------
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ss;

	ss = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*ss == (unsigned char)c)
			return ((void*)ss);
		ss++;
	}
	return (NULL);
}
