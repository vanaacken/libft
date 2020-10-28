/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:52:52 by niels         #+#    #+#                 */
/*   Updated: 2020/10/27 23:41:03 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*dst;
	unsigned int	i;

	dst = ft_strnew(ft_strlen((char *)s));
	i = 0;
	while (s[i])
	{
		dst[i] = (*f)(s[i]);
		i++;
	}
	return (dst);
}
