/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 02:15:53 by aelouazz          #+#    #+#             */
/*   Updated: 2019/05/18 04:46:28 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** checks if the @c existes within the @charset                                |
** -----------------------------------------------------------------------------
*/

static int		is_separator(char c, char const *charset)
{
	int			i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

/*
** -----------------------------------------------------------------------------
** looks for the first word and count it as a one then keeps traversing @s     |
** and if the character is preceeded by a seperator it increments @count       |
** -----------------------------------------------------------------------------
*/

static int		count_words(char *str, const char *charset)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (str[i] && is_separator(str[i], charset))
		++i;
	if (str[i] && !is_separator(str[i], charset))
		count = 1;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && is_separator(str[i - 1], charset))
			++count;
		++i;
	}
	return (count);
}

/*
** -----------------------------------------------------------------------------
**	keeps counting the characters until it reachs the end or in hit a charset  |
** -----------------------------------------------------------------------------
*/

static int		word_size(char *str, char const *charset)
{
	int			size;

	size = 0;
	while (str[size] && !is_separator(str[size], charset))
		++size;
	return (size);
}

/*
** -----------------------------------------------------------------------------
** allocates @ret to point at words and adds a null at the end of the words    |
** then fills every word from @src to the @ret and increments the @index with  |
** with every new word                                                         |
** -----------------------------------------------------------------------------
*/

char			**ft_strsplitset(char *str, const char *charset)
{
	char		**ret;
	int			i;
	int			j;
	int			index;

	if (!(ret = (char **)malloc(sizeof(char *) *
		(count_words(str, charset) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!is_separator(str[i], charset))
		{
			if (index == -1 || is_separator(str[i - 1], charset))
			{
				if (!(ret[++index] = (char *)malloc(sizeof(char) * (word_size(
					str + i, charset) + 1))))
					return (NULL);
				j = 0;
			}
			ret[index][j] = str[i];
			ret[index][++j] = '\0';
		}
	ret[++index] = 0;
	return (ret);
}
