/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 03:36:40 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 01:08:47 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** copies n bytes from memory area @src to memory area @dst.  If @dst and @src |
** overlap, behavior is undefined. Applications in which @dst and @src overlap |
** should use ft_memmove instead.                                              |
** -----------------------------------------------------------------------------
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (n-- > 0)
		*(b++) = *(a++);
	return (dest);
}
