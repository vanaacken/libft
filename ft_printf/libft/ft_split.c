/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:51:01 by niels         #+#    #+#                 */
/*   Updated: 2020/10/29 13:52:04 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int count;
	unsigned int check;
	unsigned int i;

	count = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			check = 0;
		else if (s[i] != c && check == 0)
		{
			check = 1;
			count += 1;
		}
		i++;
	}
	return (count);
}

static char			*make_substring(const char *s, const char *sp,
					unsigned int i, char c)
{
	unsigned int len;

	len = 0;
	while (s[i + len] != c && s[i + len])
		len++;
	sp = ft_substr(s, i, len);
	return ((char *)sp);
}

static	char		**free_split(char **split, unsigned int index)
{
	while (index >= 0)
	{
		free((void *)split[index]);
		index--;
	}
	free(split);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**split;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	while (s[i] != '\0' && count > 0)
	{
		if (s[i] != c)
		{
			split[j] = make_substring(s, split[j], i, c);
			if (!split[j])
				return (free_split(split, j));
			i += ft_strlen(split[j]);
			j++;
			count--;
		}
		i++;
	}
	return (split);
}
