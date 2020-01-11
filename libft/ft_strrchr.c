/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:27:58 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 23:50:59 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** @RET: the LAST occurence of @c in @s including '/0'      NULL if not found  |
** -----------------------------------------------------------------------------
*/

char	*ft_strrchr(const char *s, int c)
{
	char *found;

	found = NULL;
	while (*s)
	{
		if (*s == c)
			found = (char *)s;
		s++;
	}
	if (found)
		return (found);
	if (c == 0)
		return ((char*)s);
	return (NULL);
}
