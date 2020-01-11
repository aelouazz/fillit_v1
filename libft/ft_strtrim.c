/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 23:22:01 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/27 00:41:22 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** calculate the amount of the @charset exists in the START of @str            |
** if (count == tmp): tests to see of we hit a different char than those       |
** in the @charset                                                             |
** -----------------------------------------------------------------------------
*/

static unsigned int			count_start(char *str, const char *cs)
{
	int						index;
	unsigned int			count;
	unsigned int			tmp;

	count = 0;
	while (*str)
	{
		index = 0;
		tmp = count;
		while (cs[index])
			if (cs[index++] == *str)
				++count;
		if (count == tmp)
			return (count);
		++str;
	}
	return (count);
}

/*
** -----------------------------------------------------------------------------
** calculate the amount of the @charset exists in the END of @str              |
** if (count == tmp): tests to see of we hit a different char than those       |
** in the @charset                                                             |
** -----------------------------------------------------------------------------
*/

static unsigned int			count_end(char *str, const char *cs)
{
	unsigned int			last_index;
	int						index;
	unsigned int			count;
	unsigned int			tmp;

	count = 0;
	last_index = (unsigned int)ft_strlen(str) - 1;
	while (str[last_index])
	{
		index = 0;
		tmp = count;
		while (cs[index])
			if (cs[index++] == str[last_index])
				++count;
		if (count == tmp)
			return (count);
		--last_index;
	}
	return (count);
}

/*
** -----------------------------------------------------------------------------
** trims the white space at the start and the end of @s                        |
** @RET: allocate and fill @result with the trimed version of @s               |
** -----------------------------------------------------------------------------
*/

char						*ft_strtrim(char const *s)
{
	char					*result;
	unsigned int			start;
	unsigned int			size;
	unsigned int			spaces_count;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char *)s);
	spaces_count = count_start((char *)s, " \n\t");
	start = spaces_count;
	if (size > spaces_count)
		spaces_count += count_end((char *)s, " \n\t");
	size -= spaces_count;
	if (!(result = (char*)ft_memalloc((size_t)size + 1)))
		return (NULL);
	result = ft_strncpy(result, (char *)s + start, size);
	return (result);
}
