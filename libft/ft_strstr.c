/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:44:14 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/26 00:32:52 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** @RET: ( (@s1 starts with @s2) ? 1 : 0 )                                     |
** -----------------------------------------------------------------------------
*/

static int		found(const char *s1, const char *s2)
{
	while (*s2)
	{
		if (!(*s1 == *s2))
			return (0);
		s2++;
		s1++;
	}
	return (1);
}

/*
** -----------------------------------------------------------------------------
** @RET: address of first occurence of @s2 in @s1       NULL if not found      |
** -----------------------------------------------------------------------------
*/

char			*ft_strstr(const char *to_search, const char *to_find)
{
	if (!*to_find)
		return ((char*)to_search);
	while (*to_search)
	{
		if (found(to_search, to_find))
			return ((char*)to_search);
		to_search++;
	}
	return (NULL);
}
