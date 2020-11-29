/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student-codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:21:32 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/28 09:27:37 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h>			// weghalen

/* strlen adjusted to stop counting after finding a specific character. */
size_t	ft_strclen(const char *str, int c)
{
	size_t	i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == (unsigned char)c && c != 0)
			return (i);
	}
	return (i);
}

/*	memccpy adjusted to copy until it finds the character.
if it finds the character, it null terminates destination.
It also returns destination instead of NULL */
char	*ft_memccpy(char *dst, const char *src, int c)
{
	if (!src)
		return (dst);
	while (*src)
	{
		if (*src == (unsigned char)c && c != 0)
		{
			*dst = '\0';
			return ((char *)src);
		}	
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst);
}

/* moves memory from end of buffer to beginning. 
Then makes the rest of the buffer 0 */
void	ft_memmove(char *dst, const char *src) 
{
	size_t	src_len;
	size_t	i;

	if (*src == '\n')
		src++;
	src_len = ft_strclen(src, 0);
	i = 0;
	while(i < BUFFER_SIZE)
	{
		if (i <= src_len)
			dst[i] = src[i];
		else
			dst[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (TRUE)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}
