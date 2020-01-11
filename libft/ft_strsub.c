/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:57:25 by aelouazz          #+#    #+#             */
/*   Updated: 2019/05/18 04:22:36 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** Copies @len Bytes starting from position @start of the string @s            |
** @RET: the sub string @result resulted from copying                          |
** -----------------------------------------------------------------------------
*/

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s || !(result = (char*)ft_memalloc(len + 1)))
		return (NULL);
	result = ft_strncpy(result, (char*)s + start, len);
	result[len + 1] = '\0';
	return (result);
}
