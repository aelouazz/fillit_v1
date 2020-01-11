/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 04:30:53 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 02:28:16 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** copies @len bytes from string @src to string @dst.                          |
** this function makes sure there is no overlap in the memory                  |
** -----------------------------------------------------------------------------
*/

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				count;
	unsigned char		*desty;
	const unsigned char	*srcy;

	desty = (unsigned char *)dst;
	srcy = (unsigned char *)src;
	count = 0;
	if (srcy < desty)
		while (++count <= len)
			desty[len - count] = srcy[len - count];
	else
		while (len-- > 0)
			*(desty++) = *(srcy++);
	return (dst);
}
