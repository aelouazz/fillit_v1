/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 03:46:45 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 02:25:02 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** copy from @src to @dest until it finds the char @c (included) or it hits @n |
** @ret: =(&c + 1) if @c is found else (NULL)                                  |
** -----------------------------------------------------------------------------
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *desty;
	unsigned char *srcy;

	desty = (unsigned char*)dest;
	srcy = (unsigned char*)src;
	while (n-- > 0)
	{
		*(desty++) = *srcy;
		if (*(srcy++) == (unsigned char)c)
			return ((void*)(desty));
	}
	return (NULL);
}
