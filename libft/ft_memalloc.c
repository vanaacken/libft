/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:48:06 by niels         #+#    #+#                 */
/*   Updated: 2020/10/28 11:52:07 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *dst;

	if (!size)
		return (0);
	if (!(dst = (char *)malloc(size)))
		return (NULL);
	ft_bzero(dst, size);
	return (dst);
}
