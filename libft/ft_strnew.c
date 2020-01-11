/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:45:46 by aelouazz          #+#    #+#             */
/*   Updated: 2019/05/18 04:14:54 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** @size:   The size of the string to be allocated                             |
** @RETURN: The string allocated and initialized to 0                          |
** -----------------------------------------------------------------------------
*/

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*string;

	if (!(string = (char*)ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
		string[i++] = '\0';
	return (string);
}
