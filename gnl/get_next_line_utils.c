/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:11:07 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/11/19 14:47:58 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len;
	char			*join;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
	{
		free((char *)s1);
		return (NULL);
	}
	ft_memmove(join, s1, ft_strlen(s1));
	ft_memmove((join + ft_strlen(s1)), s2, ft_strlen(s2));
	free((char *)s1);
	join[len] = '\0';
	return (join);
}

int			newline_isset(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
