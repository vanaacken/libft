/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:54:39 by niels         #+#    #+#                 */
/*   Updated: 2020/10/27 23:42:10 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len = ft_strlen((char *)s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	new = ft_substr((char *)s1, 0, len + 1);
	return (new);
}
