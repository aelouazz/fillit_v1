/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:19:23 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/25 22:03:16 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** allocates memory to copy @src and returns @new pointing to the copy address |
** -----------------------------------------------------------------------------
*/

char		*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	size_t	size;

	size = ft_strlen(src);
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
