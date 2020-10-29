/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:52:37 by niels         #+#    #+#                 */
/*   Updated: 2020/10/28 23:28:23 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*join;

	len = ft_strlen((char *)s1);
	len = len + ft_strlen((char *)s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	ft_strlcat(join, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(join, (char *)s2, len + 1);
	return (join);
}
