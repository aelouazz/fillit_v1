/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:03:30 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/26 00:46:16 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** Search for @s2 in @s1 within the @limit                                     |
** @RET: ( (@s1 starts with @s2) ? 1 : 0 )                                     |
** comparison stops when @s2 end OR when @s1 == @limit                         |
** -----------------------------------------------------------------------------
*/

static int	found(const char *s1, const char *s2, const char *limit)
{
	while (*s2 && (s1 < limit))
	{
		if (!(*s1 == *s2))
			return (0);
		s2++;
		s1++;
	}
	if (!*s2)
		return (1);
	return (0);
}

/*
** -----------------------------------------------------------------------------
** @RET: address of first occurence of @s2 in @s1 within the limit of :        |
**       @to_search[@len - 1]                                                  |
** -----------------------------------------------------------------------------
*/

char		*ft_strnstr(const char *to_search, const char *to_find, size_t len)
{
	const char *limit;

	limit = to_search + len;
	if (!*to_find)
		return ((char*)to_search);
	while (*to_search && (to_search < limit))
	{
		if (found(to_search, to_find, limit))
			return ((char*)to_search);
		to_search++;
	}
	return (NULL);
}
